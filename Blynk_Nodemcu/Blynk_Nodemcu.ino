
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial//used to print data on serial monitor that comes from mobile.//
#include<Servo.h>


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = getenv("blynk_auth");//Specify your auth token here.

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wifiiiii";//submit the ssid and password here of your router.
char pass[] = getenv("wifi_password");

Servo m1,m2,m3,m4;
void setup()
{
  // Debug console
  Serial.begin(9600);
  m1.attach(D2);    //Pins are attatched to the D2,D3,D4,D5 pins of the NODEMCU which produces pwm//
  m2.attach(D3);
  m3.attach(D4);
  m4.attach(D5);
 
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);


}

BLYNK_WRITE(V0){  //for calibration of the motor.
  int ab=param.asInt();
  m1.write(map(ab,0,255,0,179));
  m2.write(map(ab,0,255,0,179));
  m3.write(map(ab,0,255,0,179));
  m4.write(map(ab,0,255,0,179));
}
BLYNK_WRITE(V1){  //for drone control
  int ab=param.asInt();
  m1.write(map(ab,0,255,0,179));
  m2.write(map(ab,0,255,0,179));
  m3.write(map(ab,0,255,0,179));
  m4.write(map(ab,0,255,0,179));
}

void loop()
{
  Blynk.run();
}

