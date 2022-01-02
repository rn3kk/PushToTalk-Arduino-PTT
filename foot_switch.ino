int ledPin = 13;
int switch_btn = 2;
int val = 0;
int btn_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switch_btn, INPUT_PULLUP);
}

void loop() {
  btn_state = digitalRead(switch_btn);
  if(btn_state == HIGH)
  {
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, HIGH);
  }
  delay(10); 
}
