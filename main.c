int mode = 1; 

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    mode = (mode == 1) ? 2 : 1;
    delay(300); 
  }
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1') mode = 1;
    if (c == '2') mode = 2;
  }
  Fs = (mode == 1) ? 500 : 150;
  unsigned long t = micros();
  int value = analogRead(A0);
  Serial.println(value);
  while (micros() - t < 1000000 / Fs) { /* ожидание */ }
}