double obstacleLimit =  60.0;

//Define Ultrasonic Sensors Pins
const int trig_Front_L = 3;
const int trig_Front_R = 5;
const int trig_Back_L = 7;
const int trig_Back_R = 9;
const int echo_Front_L = 2;
const int echo_Front_R = 4;
const int echo_Back_L = 6;
const int echo_Back_R = 8;
const int led = 13;

void setup() {
  Serial.begin(115200);             // Starts the serial communication

pinMode(led, OUTPUT);  // Sets the trigPin as an Output
  digitalWrite(led, HIGH);

 pinMode(trig_Front_L, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo_Front_L, INPUT);  // Sets the echoPin as an Input
}


uint32_t pmillis = 0;
void loop() {
//  if (millis() - pmillis >= 1500) {
  //    pmillis = millis();
double distance = read_ultra(trig_main, echo_main);
Serial.print("Dist = ");
      Serial.println(dist);
Serial.print("cm");
}


double read_distance(const int trig, const int echo) {
  long duration = 0;
  double distance = 0.0;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  
  // Calculating the distance
  distance = (duration * 0.034) / 2;
//  distance = (duration * 34) / 2000; // Speed of sound wave divided by 2 (go and back)

  return distance;
}
