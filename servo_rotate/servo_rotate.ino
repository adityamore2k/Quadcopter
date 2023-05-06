#include <Servo.h>

Servo esc;

void setup() {
  esc.attach(4, 1000, 2000); // attach the ESC to pin 5 and set the PWM pulse range
}

void loop() {
  // set the ESC throttle value to rotate the motor
  esc.writeMicroseconds(1500); // set the throttle to 1500 microseconds for no rotation
  delay(1000); // wait for 1 second

  esc.writeMicroseconds(1700); // set the throttle to 1700 microseconds for clockwise rotation
  delay(1000); // wait for 1 second

  esc.writeMicroseconds(1300); // set the throttle to 1300 microseconds for counterclockwise rotation
  delay(1000); // wait for 1 second
}
