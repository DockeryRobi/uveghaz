<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Uveghaz extends Model
{
    use HasFactory;
    public $table = "uveghazak";
    public $primaryKey = "h_id";
    public $timestamps = false;
    public $guarded = [];
}
