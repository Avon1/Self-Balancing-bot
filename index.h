const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Self Balancing Robot</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <script>
            var ip = location.host;
                function Send_post_data(code) {
                var http = new XMLHttpRequest();
                var url = 'http://'+ ip + '/post';
                var params = 'msg=' + code;
                http.open('POST', url, true);
                http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

                http.onreadystatechange = function () {
                    if (http.readyState === 4 && http.status === 200) {
                        if (http.responseText === null) {
                            alert('Failed!');
                        } else {
                            console.log(http.responseText);
                        }

                    }
                };
                http.send(params);
            }
        </script>
        
        <h1>Self Balancing Bot</h1>
        <hr>
        <br>
        <button onmousedown="Send_post_data('put led on')" onmouseup="Send_post_data('put led on')">Up</button>
        <br>
        <button >Down</button>
    </body>
</html>


)=====";
