#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

String In = "";
String splitInput[19];

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);    // Specify ESP8266 operating mode: Client
  WiFi.begin("Utlity", "JimMyDad");   //Connect to WiFi
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }
}

void loop() {
  boolean StringReady = false;    //Detecting Serial input
  while (Serial.available()) {
    In = Serial.readString();
    StringReady= true;
  }

  if (StringReady) {    //Process input data
    for (int i=0; i<(sizeof(splitInput)/sizeof(splitInput[0])); i++) {
      splitInput[i] = "";
    }

    int arrayPtr = 0;
  
    for (int i=0; i<In.length(); i++) {
      if (In.charAt(i) == '|') {
        arrayPtr++;
      } else {
        splitInput[arrayPtr] += In.charAt(i);
      }
    }

    for (int i=0; i<(sizeof(splitInput)/sizeof(splitInput[0]))-1; i++) {
      Serial.print(splitInput[i]);
      Serial.print("   ");
    }
    Serial.println();


    //Construct HTTP POST data
    String data = "%7B%0A%20%20%20%20%20%20%20%20%22hub_id%22%3A%202%2C%0A%20%20%20%20%20%20%20%20%22key%22%3A%20%22key2%22%2C%0A%20%20%20%20%20%20%20%20%22desks%22%3A%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%22desks%22%3A%5B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%201%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%20125%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%20103%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%202%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%20164%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%2042%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%203%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%2014%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%20150%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%204%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%20158%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%20115%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%205%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%2094%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%2020%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22desk_number%22%3A%206%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22ultrasonic_distance%22%3A%2037%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22pir_quiet_time%22%3A%2034%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5D%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A";
    if (WiFi.status() == WL_CONNECTED) {                      //Check WiFi connection status

//      Serial.println(data);
      HTTPClient http;                                        //Declare object of class HTTPClient
 
      http.begin("http://51.68.198.28/library/submit/");      //Specify request destination
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

      int httpCode = http.POST(data);
      String payload = http.getString();                      //Get the response payload
 
      Serial.println(httpCode);                               //Print HTTP return code
      Serial.println(payload);                                //Print request response payload
 
      http.end();                                             //Close connection
 
    } else {
      Serial.println("Error in WiFi connection");
    }



    
  }
  
}
