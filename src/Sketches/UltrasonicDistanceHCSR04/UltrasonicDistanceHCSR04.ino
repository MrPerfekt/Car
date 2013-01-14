#define TRIGPIN 22        // Pin to send trigger pulse
#define ECHOPIN 23        // Pin to receive echo pulse

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */
 
void setup()
{
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

/*
 * loop function.
 * 
 */
void loop()
{
  // Start Ranging
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Compute distance
  float distance = pulseIn(ECHOPIN, HIGH);
  Serial.print(distance);
  Serial.print("  ");
  distance= distance/58;
  Serial.println(distance);
  delay(200);
}

