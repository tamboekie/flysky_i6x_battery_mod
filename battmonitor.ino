/* Simple battery monitor to test the FlySky i6x battery mod */
/*   It will measure A0 and print out the physical volatge   */
/*   Output baud is 9600                                     */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to


void setup() {
  // initialize serial communication at 9600 bits per second:

  Serial.begin(9600);
  //Serial.println("init.");
}


int last_raw = 0;

void loop() {
    
 int raw = analogRead(sensorPin);

 if ((raw > (last_raw+2)) || (raw < (last_raw-2)))
 {
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = (float)raw * (3.27 / 666.0);
  // print out the value you read:
  Serial.print(raw);
  Serial.print("\t");
  Serial.println(voltage);
  last_raw =  raw;
 }
  delay(1000);
 }
