<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Http;
use App\Models\Uveghaz;

class UveghazController extends Controller
{
    public function index(){
        $uveghazak = Uveghaz::orderBy('h_id','DESC')->paginate(10);
        $utolsoAdat = Uveghaz::orderBy('h_id','DESC')->limit(1)->get();
        return view('welcome',['uveghazak' => $uveghazak, 'utolsoAdat' => $utolsoAdat]);
    }

    public function tarol(Request $req){
        $uveghaz = new Uveghaz;
        $uveghaz->homerseklet = $req->input('homerseklet');
        $uveghaz->paratartalom = $req->input('paratartalom');
        $uveghaz->tn = $req->input('tn');
        $uveghaz->meres_ideje = date('Y-m-d H:i:s');
        $uveghaz->save();
        return response()->json($uveghaz,201);

    }

    public function szellozes(Request $req){
        $Hparameter = array(
            'allapot' => $req->allapot
            //'rogido' => 'meres_ideje'
        );
    
        if($req->allapot == 1){
            $curlHandle = curl_init('http://192.168.12.19/szellozesbekapcsolas'); //arduino kap ip cim
            
        }else{
            $curlHandle = curl_init('http://192.168.12.19/szellozeslekapcsolas'); //arduino kap ip cim
        }
    
        //curl_setopt($curlHandle, CURLOPT_POSTFIELDS, $Hparameter);
        curl_setopt($curlHandle, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curlHandle, CURLOPT_HEADER, true);
        curl_setopt($curlHandle, CURLOPT_NOBODY, true);
        curl_setopt($curlHandle, CURLOPT_TIMEOUT,30); //lehet kevesebb 15-20
        $curlResponse = curl_exec($curlHandle);
        curl_close($curlHandle);
             
        //$httpcode = curl_getinfo($curlHandle, CURLINFO_HTTP_CODE);
        
       

        return $curlResponse;

    }

    public function ontes(Request $req){
        $Oparameter = array(
            'allapot' => $req->allapot
        );

        if ($req->allapot == 1) {
            $curlHandle = curl_init('http://192.168.12.19/ontesbekapcsolas');
        }else{
            $curlHandle = curl_init('http://192.168.12.19/onteslekapcsolas');
        }
        
        curl_setopt($curlHandle, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curlHandle, CURLOPT_HEADER, true);
        curl_setopt($curlHandle, CURLOPT_NOBODY, true);
        curl_setopt($curlHandle, CURLOPT_TIMEOUT,30); //lehet kevesebb 15-20
        $curlResponse = curl_exec($curlHandle);
        curl_close($curlHandle);

        //return 'HTTP Code: ' . $httpcode;
        return $curlResponse;
    }
}
