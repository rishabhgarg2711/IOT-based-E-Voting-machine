#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
int p1=0;
int p2=0;


const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head><title>Login</title>
</head>
<body>
<br><center><h2>Election Commission Of India<h2></center>
 
<form action="/action_page">
  Name:<br>
  <input type="text" name="Name">
  <br><br>
  Password:<br>
  <input type="password" name="pass" >
  <br><br>
  <input type="submit" value="Submit">
</form> 
 
</body>
</html>
)=====";
 
//SSID and Password of your WiFi router
const char* ssid = "Redmi2";
const char* password = "09876543";
 
ESP8266WebServer server(80); //Server on port 80
 
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handlel1() {
 String s = "<!DOCTYPE html><html><head><script type=\"text/javascript\">function code(){window.history.go(-2);}window.onload = code;</script></head><body></body></html>"; //Read HTML contents
 Serial.write("1");
 server.send(200, "text/html", s); //Send web page
}
void handlel2() {
 String s = "<!DOCTYPE html><html><head><script type=\"text/javascript\">function code(){window.history.go(-2);}window.onload = code;</script></head><body></body></html>"; //Read HTML contents
 Serial.write("2");
 server.send(200, "text/html", s); //Send web page
}
void handlel3() {
 String s = "<!DOCTYPE html><html><head><script type=\"text/javascript\">function code(){window.history.go(-2);}window.onload = code;</script></head><body></body></html>"; //Read HTML contents
 Serial.write("3");
 server.send(200, "text/html", s); //Send web page
}

void handleForm() {
 String Name = server.arg("Name"); 
 String pass = server.arg("pass"); 
  String p = "<!DOCTYPE html><html><head><title>Voting</title></head><body><br><h1><center> Welcome to Voting</center></h1><br><br><h2>Click <a href='/LEADER=1'>here</a> to vote Congress</h2><br><br><h2>Click <a href='/LEADER=2'>here</a> to vote BJP</h2><br><br><h2>Click <a href='/LEADER=3'>here </a>to vote AAP</h2><br><br></body></html>";
  
if(Name=="Rishabh" && pass=="1234a" && p1==0)
 {
 server.send(200, "text/html", p); //Send web page
  p1=1;
 }
 else if(Name=="Vinay" && pass=="0987b" && p2==0)
 {
 
 server.send(200, "text/html", p); //Send web page
 p2=1;
 }
 else{
 String s = "<br><center><h1><a href='javascript:history.back()'> Go Back Wrong inputs </a><h1></center>";
 server.send(200, "text/html", s); //Send web page
  
 }
}

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1);
  }
 
   server.on("/", handleRoot);      //Which routine to handle at root location
   server.on("/action_page", handleForm); //form action is handled here
   server.on("/LEADER=1", handlel1);
   server.on("/LEADER=2", handlel2);
   server.on("/LEADER=3", handlel3);
   server.begin();                  //Start server
    
}
void loop(){
  server.handleClient();          //Handle client requests
}
