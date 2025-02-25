const int limit = 90;

//front sensor - 1
const int trigPin1 = 18;
const int echoPin1 = 19;

//back sensor -  2
const int trigPin2 = 23;
const int echoPin2 = 4;

//right sensor - 3
const int trigPin3 = 25;
const int echoPin3 = 26;

// left sensor - 4
const int trigPin4 = 32;
const int echoPin4 = 33;

const int in1 = 34;
const int in2 = 35;
const int relay = 5;
const int relay2 = 15;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  digitalWrite(relay, LOW);
  digitalWrite(relay2, LOW);
  delay(1000);
  digitalWrite(relay, HIGH);
  digitalWrite(relay2, HIGH);
}


unsigned long pmillis = 0;
long front = 0, back = 0, left = 0, right = 0;
void loop() {
  int val1 = digitalRead(in1);  // 0 on Input Signal - NPN NO
  int val2 = digitalRead(in2);
  front = read_ultra(trigPin1, echoPin1);
  back = read_ultra(trigPin2, echoPin2);
  right = read_ultra(trigPin3, echoPin3);
  left = read_ultra(trigPin4, echoPin4); 

  // Serial.print(val1);
  // Serial.print("\t");
  // Serial.println(val2);
  Serial.print("\t");
  Serial.print(front);
  Serial.print("\t");
  Serial.print(back);
  Serial.print("\t");
  Serial.print(right);
  Serial.print("\t");
  Serial.println(left);

  if (val1 == 1 && val2 == 0) {  // Input : 0 0 - front
    Serial.println("Case # 01");
    if (front < limit) {
      Serial.println("relay # 01");
      digitalWrite(relay2, LOW);
    } else {
      digitalWrite(relay2, HIGH);
    }
    if (back < limit) {
      Serial.println("relay # 02");
      digitalWrite(relay, LOW);
    } else {
      digitalWrite(relay, HIGH);
    }
  } else if (val1 == 0 && val2 == 1) {  // Input : 0 1 - left
    Serial.println("Case # 02");
    if (left < limit) {
      Serial.println("relay # 01");
      digitalWrite(relay, LOW);
    } else {
      digitalWrite(relay, HIGH);
    }
    if (right < limit) {
      Serial.println("relay # 02");
      digitalWrite(relay2, LOW);
    } else {
      digitalWrite(relay2, HIGH);
    }
  } else {
    digitalWrite(relay, HIGH);
    digitalWrite(relay2, HIGH);
  }
}


long read_ultra(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2;
  // double dis_inch = distance / 2.54;
  // double dis_foot = dis_inch / 12.0;
  return distance;
}

// Serial.print("Distance : ");
// Serial.print(distance);
// Serial.print("\t");
// Serial.print(dis_inch);
// Serial.print("\t");
// Serial.println(dis_foot);
