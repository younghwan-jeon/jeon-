#include <Servo.h>

// Arduino pin assignment
#define PIN_IR A0
#define PIN_LED 9
#define PIN_SERVO 10

int a,b;
// configurable parameters
#define _DUTY_MIN 1600 // servo full clockwise position (0 degree)
#define _DUTY_NEU 1700 // servo neutral position (90 degree)
#define _DUTY_MAX 1800 // servo full counterclockwise position (180 degree)

#define _SERVO_SPEED 800 // servo speed limit (unit: degree/second)
#define INTERVAL 20  // servo update interval
int duty_curr, duty_target;
int duty_chg_per_interval; // maximum duty difference per interval
Servo myservo;
  
void setup() {
// initialize GPIO pins
  pinMode(PIN_LED,OUTPUT);
  digitalWrite(PIN_LED, 1);
  myservo.attach(PIN_SERVO);   
  duty_chg_per_interval = (_DUTY_MAX - _DUTY_MIN) * ((float)_SERVO_SPEED / 180) * ((float)INTERVAL / 1000);
 duty_curr = duty_target = 2000;


// initialize serial port
  Serial.begin(57600);

  a=106;
  b=250;
}



void loop() {
  float raw_dist = ir_distance();
  float dist_cali;

  if (raw_dist >200) dist_cali = (raw_dist-200)*(50/15) + 200;
  else dist_cali = raw_dist;
  
  if(dist_cali < 265) {
      myservo.writeMicroseconds(_DUTY_MAX);
  }
  else {
      myservo.writeMicroseconds(_DUTY_MIN);
  }
  Serial.print("min:0,max:500");
  Serial.print("dist_fixed:");
  Serial.print(dist_cali);
  Serial.print("duty_curr:");
  Serial.println(duty_curr);
  delay(20);
}

float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}
//
