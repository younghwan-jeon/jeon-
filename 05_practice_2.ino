#define LED7 7

int count = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED7, OUTPUT);
  Serial.begin(115200);
  Serial.print("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED7, 0);
  delay(1000);
  while(count < 5) {
    digitalWrite(LED7, 1);
    delay(100);
    digitalWrite(LED7, 0);
    delay(100);
    Serial.println(++count);
  }
  while(1){
    digitalWrite(LED7, 1);
    }
}
