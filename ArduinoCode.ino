int desk = 1;

int trigPin1 [] = {22, 24, 26, 28, 30, 32};
int echoPin1 [] = {23, 25, 27, 29, 31, 33};

int trigPin2 [] = {34, 36, 38, 40, 42, 44};
int echoPin2 [] = {35, 37, 39, 41, 43, 45};

int PIRPin [] = {46, 47, 48, 49, 50, 50};

int PIRIN [6];

long duration1 [6];
long distance1 [6];

long duration2 [6];
long distance2 [6];

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  for (byte i = 0; i < desk; i++) {
    pinMode(trigPin1[i], OUTPUT);
    pinMode(echoPin1[i], INPUT);
    pinMode(trigPin2[i], OUTPUT);
    pinMode(echoPin2[i], INPUT);
    pinMode(PIRPin[i], INPUT);

    PIRIN[i] = 0;
    duration1[i] = 0;
    distance1[i] = 0;
    duration2[i] = 0;
    distance2[i] = 0;
  }

}

void loop() {
  for (byte i = 0; i < desk; i++) {
    digitalWrite(trigPin1[i], LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin1[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1[i], LOW);
    duration1[i] = pulseIn(echoPin1[i], HIGH);
    distance1[i] = (duration1[i]/2) / 29.1;

    digitalWrite(trigPin2[i], LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin2[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2[i], LOW);
    duration2[i] = pulseIn(echoPin2[i], HIGH);
    distance2[i] = (duration2[i]/2) / 29.1;\

    PIRIN[i] = digitalRead(PIRPin[i]);
  }

  Serial.println("/////////////////////////////////////");
  for (byte i = 0; i < 6; i++) {
    Serial.print("Desk ");
    Serial.print(i+1);
    Serial.print(": Distance: ");
    Serial.print(distance1[i]);
    Serial.print(" | ");
    Serial.print(distance2[i]);
    Serial.print("   Movement: ");
    Serial.print(PIRIN[i]);
    Serial.println();
  }
  Serial.println("/////////////////////////////////////");
  Serial.println();
  Serial.println();

  for (byte i = 0; i < 6; i++) {
    Serial1.print(distance1[i]);
    Serial1.print("|");
    Serial1.print(distance2[i]);
    Serial1.print("|");
    Serial1.print(PIRIN[i]);
    Serial1.print("|");
  }
  Serial1.println();

  delay(3000);

}
