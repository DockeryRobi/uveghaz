<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UveghazController;


Route::get('/user', function (Request $request) {
    return $request->user();
})->middleware('auth:sanctum');

Route::post('/kuldes/szellozeskapcsolas',[UveghazController::class,'szellozes']); //->name()
Route::post('/kuldes/onteskapcsolas',[UveghazController::class,'ontes']);

Route::post('/kuldes',[UveghazController::class,'tarol'])->name('uveghaz');



