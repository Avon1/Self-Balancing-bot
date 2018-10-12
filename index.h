const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title> Self Balancing Bot</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script>
            function clickedup() {
                var selected_value = 0;
                if (document.getElementById('v1').checked) {
                    selected_value = document.getElementById('v1').value;
                } else if (document.getElementById('v2').checked) {
                    selected_value = document.getElementById('v2').value;
                } else if (document.getElementById('v3').checked) {
                    selected_value = document.getElementById('v3').value;
                }
                var pwmvalue = document.getElementById('pwmvalueup_down').value;
                pwmvalue = parseInt(pwmvalue) + parseInt(selected_value);
                if (pwmvalue > 1023) {
                    pwmvalue = 1023;
                }
                //need to remove
//                document.getElementById('pwmvalueup_down').value = pwmvalue;
                //ok
                Send_post_dataupdown(pwmvalue);
            }
            function clickeddown() {
                var selected_value = 0;
                if (document.getElementById('v1').checked) {
                    selected_value = document.getElementById('v1').value;
                } else if (document.getElementById('v2').checked) {
                    selected_value = document.getElementById('v2').value;
                } else if (document.getElementById('v3').checked) {
                    selected_value = document.getElementById('v3').value;
                }
                var pwmvalue = document.getElementById('pwmvalueup_down').value;
                pwmvalue = parseInt(pwmvalue) - parseInt(selected_value);
                if (pwmvalue < -1023) {
                    pwmvalue = -1023;
                }
                //need to remove
//                document.getElementById('pwmvalueup_down').value = pwmvalue;
                //new code
                Send_post_dataupdown(pwmvalue);
            }
            var ip = location.host;
            function Send_post_dataupdown(code) {
                var http = new XMLHttpRequest();
                var url = 'http://' + ip + '/post';
                var params = 'updown=' + code;
                http.open('POST', url, true);
                http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

                http.onreadystatechange = function () {
                    if (http.readyState === 4 && http.status === 200) {
                        if (http.responseText === null) {
                            alert('Failed!');
                        } else {
                 document.getElementById('pwmvalueup_down').value = parseInt(http.responseText);            
                        }

                    }
                };
                http.send(params);
            }
        </script>
    </head>

    <body>
        <div style="border-style: solid">
            <h3>Self Balancing Bot</h3>
            <div> 
                <h4>Up/Down</h4>
                <button id="up_button" onclick="clickedup()">UP</button>
                <br>
                <br>
                <input id="pwmvalueup_down" value="0" readonly>
                <br>
                <br>
                <button id="up_down" onclick="clickeddown()">Down</button>
                <br>
                <br>
            </div>
            <h4>Select the value</h4>
            100<input id = "v1" type="radio" name="updownvalue" value="100"> 
            10<input id = "v2" type="radio" name="updownvalue" value="10"> 
            1<input id = "v3" type="radio" name="updownvalue" value="1" checked="checked"> 
            <br><br>
        </div>
    </body>
</html>


)=====";
