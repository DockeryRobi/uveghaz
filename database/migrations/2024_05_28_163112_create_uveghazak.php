<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('uveghazak', function (Blueprint $table) {
            $table->id("h_id");
            $table->float('homerseklet',4,2);
            $table->integer('paratartalom'); //float('paratartalom')
            $table->integer('tn');
            $table->dateTime('meres_ideje');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('uveghazak');
    }
};
