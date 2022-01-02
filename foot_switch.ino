int ledPin = 13;
int switch_btn = 2;
int last_state = 0;


void setup() {  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(switch_btn, INPUT_PULLUP);
}

void loop() {
  if (Serial.available() > 0)
  {
    char data = Serial.read();    
    if( data == '2')
    {
      if(last_state == 0)
      {
        Serial.write("1;");
      }
      else if(last_state == 1)
      {
        Serial.write("0;");
      }
      
    }
  }
  
  int btn_state = digitalRead(switch_btn);
  if(btn_state != last_state)
  {
    last_state = btn_state;
    if(btn_state == HIGH)
    {
      digitalWrite(ledPin, LOW);
      Serial.write("0;");
    }
    else
    {
      digitalWrite(ledPin, HIGH);
      Serial.write("1;");
    }

  }  
  delay(10); 
}
