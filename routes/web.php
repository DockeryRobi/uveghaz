<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UveghazController;

Route::get('/', [UveghazController::class,'index']);

Route::post('/kuldes',[UveghazController::class,'tarol'])->name('uveghaz');

