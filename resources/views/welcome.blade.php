<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
    <meta name="csrf-token" content="{{ csrf_token() }}">
    <title>Okosüvegház</title>
</head>
<body class="bg-white">
    <h1 class="text-center mx-auto">Okosüvegház</h1>
    <div class="container mt-5">
        <!--<div class="row mx-auto p-5">
            <div class="col-5 bg-warning mx-auto">Fűtés</div>
            <div class="col-5 bg-info mx-auto">Víz</div>
        </div>
        <div class="row p-5">
            <button type="button" class="col-2 ">Fűtés be</button>
            <button type="button" class="col-2 ">Fűtés ki</button>
            <span class="col-3"></span>
            <button type="button" class="col-2 ">Víz be</button>
            <button type="button" class="col-2 ">Víz ki</button>
        </div>-->
        <div class="input-group d-flex justify-content-between">
            <span>
                <span class="input-group-text"><svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" fill="currentColor" class="bi bi-wind" viewBox="0 0 16 16">
                    <path d="M12.5 2A2.5 2.5 0 0 0 10 4.5a.5.5 0 0 1-1 0A3.5 3.5 0 1 1 12.5 8H.5a.5.5 0 0 1 0-1h12a2.5 2.5 0 0 0 0-5m-7 1a1 1 0 0 0-1 1 .5.5 0 0 1-1 0 2 2 0 1 1 2 2h-5a.5.5 0 0 1 0-1h5a1 1 0 0 0 0-2M0 9.5A.5.5 0 0 1 .5 9h10.042a3 3 0 1 1-3 3 .5.5 0 0 1 1 0 2 2 0 1 0 2-2H.5a.5.5 0 0 1-.5-.5"/>
                  </svg>Szellőzés</span>
                  
                <button type="button" class="btn btn-outline-secondary" onclick="szellozesKapcsolas(1);" class="szellozesGombok">Be</button>
                <button type="button" class="btn btn-outline-secondary szellozesGombok">Ki</button>
            </span>
            <span>
                <span class="input-group-text"><svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" fill="currentColor" class="bi bi-water" viewBox="0 0 16 16">
                    <path d="M.036 3.314a.5.5 0 0 1 .65-.278l1.757.703a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.757-.703a.5.5 0 1 1 .372.928l-1.758.703a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0L.314 3.964a.5.5 0 0 1-.278-.65m0 3a.5.5 0 0 1 .65-.278l1.757.703a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.757-.703a.5.5 0 1 1 .372.928l-1.758.703a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0L.314 6.964a.5.5 0 0 1-.278-.65m0 3a.5.5 0 0 1 .65-.278l1.757.703a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.757-.703a.5.5 0 1 1 .372.928l-1.758.703a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0L.314 9.964a.5.5 0 0 1-.278-.65m0 3a.5.5 0 0 1 .65-.278l1.757.703a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.014-.406a2.5 2.5 0 0 1 1.857 0l1.015.406a1.5 1.5 0 0 0 1.114 0l1.757-.703a.5.5 0 1 1 .372.928l-1.758.703a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0l-1.014-.406a1.5 1.5 0 0 0-1.114 0l-1.015.406a2.5 2.5 0 0 1-1.857 0l-1.757-.703a.5.5 0 0 1-.278-.65"/>
                  </svg>Öntözés</span>
                  
                <button type="button" class="btn btn-outline-secondary" onclick="onteskapcsolas(1);" class="ontesGombok">Önt</button>
                <button type="button" class="btn btn-outline-secondary ontesGombok">Leállít</button>
            </span>
            <div class="col-auto bg-success text-center border border-3 border-dark border-radius rounded p-3 mb-5">
                <h2>Utolsó Adat:</h2>
                <p>
                    @if ($utolsoAdat)
                        {{ $utolsoAdat[0]['homerseklet'] }}, 
                        {{ $utolsoAdat[0]['paratartalom'] }}, 
                        {{ $utolsoAdat[0]['tn'] }} <br>
                        {{ $utolsoAdat[0]['meres_ideje'] }}
                    @endif
                </p>
                
                
            </div>
        </div>
        
    </div>
    
    <div class="container">
        <div class="row">
            <div class="col-12">
                <div class="table-responsive">
                    <table class="table table-bordered border-dark table-success table-striped table-hover align-middle">
                        <tr>
                            <th>Id</th>
                            <th>Hőmérséklet</th>
                            <th>Páratartalom</th>
                            <th>Talajnedvessége</th>
                            <th>Mérés ideje</th>
                        </tr>
                        @foreach ($uveghazak as $uve)
                            <tr
                            @if ($uve->homerseklet < 20)
                                class="bg-gradient" style="background-color: rgb(123, 61, 238)"
                            @endif
                            @if ($uve->homerseklet > 30)
                                class=" bg-warning bg-gradient"
                            @endif
                            @if ($uve->paratartalom < 40)
                                class="bg-info bg-gradient" 
                            @endif
                            @if ($uve->paratartalom > 60)
                                class="bg-gradient" style="background-color: #ba549d"
                                
                            @endif
                            >
                                <td>{{ $uve->h_id }}</td>
                                <td>{{ $uve->homerseklet }}&deg;C</td>
                                <td>{{ $uve->paratartalom }}%</td>
                                <td>{{ $uve->tn }} mm</td>
                                <td>{{ $uve->meres_ideje }}</td>
                            </tr> 
                        @endforeach
                    </table>
                </div>
            </div>
        </div>
    </div>
    
        
        {{ $uveghazak->links() }}
    </div> 

    <footer class="bg-dark fixed-bottom text-white text-center">@ 2024</footer>

    <script>

        function szellozesKapcsolas(allapot){
            $(".szellozesGombok").attr("disabled",true);
            $.ajax({
                url: "/uveghaz/public/api/kuldes/szellozeskapcsolas",
                method: "POST",
                data: {allapot:allapot},
                async:false,
                headers: {
                    'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
                },
                beforeSend: function(){
                    //Mi történjen addig amíg nem kapok választ 
                    //$(placeholder).addClass('hutesGombok'); //timeout
                    //alert("Állapot " + allapot);

                },
                success:function(data){
                    //Mi történjen ha kaptam választ
                    
                   
                    $(".szellozesGombok").attr("disabled",false);
                }

            });
        }
        function onteskapcsolas(allapot){
            $(".ontesGombok").attr("disabled",true);
            $.ajax({
                url: "/uveghaz/public/api/kuldes/onteskapcsolas",
                method: "POST",
                data: {allapot:allapot},
                async:false,
                headers: {
                    'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
                },
                beforeSend: function(){
                    //Mi történjen addig amíg nem kapok választ 
                    //$(placeholder).addClass('ontesGombok');
                    
                },
                success:function(data){
                    
                    
                    $(".ontesGombok").attr("disabled",false);
                }

            });
        }

    </script>
</body>
</html>

@section('title', "Főoldal")
@section('content')



@endsection