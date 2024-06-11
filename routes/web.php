<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UveghazController;

Route::get('/', [UveghazController::class,'index']);



