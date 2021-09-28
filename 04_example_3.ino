#define PIN_LED 13

int toggle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); // Initialize serial port
  while (!Serial) {
    ; // wait for serial port to connect.
  };
  Serial.println("Hello World!");
  digitalWrite(PIN_LED, toggle); //turn off LED.
}

void loop() {
  int count = 0;
  digitalWrite(PIN_LED, count); // update LED status.
  delay(1000); // wait for 1,000 milliseconds;Serial.println(++count);
  Serial.println(++count);
  digitalWrite(PIN_LED, count); // update LED status.
  delay(1000); // wait for 1,000 milliseconds
}
int toggle_state(int toggle) {
  return toggle;
}
