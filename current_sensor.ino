// 20A bi-directional ACS712

int sensorPin = A0; // the pin that the sensor is connected to

// calibration
float offset = 511.5; // zeroing bi-directional sensor | could be 510.0 to 513.0
float span = 0.04883; // span | depends on type of sensor used (e.g. 20A) | finetune max readout

const byte numReadings = 32; // number of readings for smoothing (max 64)
int readings[numReadings]; // raw A/D readings
byte index = 0; // index of the current reading
unsigned int total = 0; // running total
float current; // resulting current

void setup() {
  Serial.begin(115200); // ***set serial monitor to this value***
  for (index = 0; index < numReadings; index++) { // fast-fill the array at startup
    readings[index] = analogRead(sensorPin);
    total = total + readings[index];
  }
  index = 0; // reset index
}

void loop() {
  total = total - readings[index]; // subtract the last reading
  readings[index] = analogRead(sensorPin); // one unused reading to clear any ghost charge
  readings[index] = analogRead(sensorPin); // read the sensor
  total = total + readings[index]; // add the reading to the total
  index = index + 1; // advance to the next position in the array
  if (index >= numReadings) // if we're at the end of the array
    index = 0; // wrap around to the beginning

  // convert value to current
  current = (total / numReadings - offset) * span; // value to current conversion

  // print to serial monitor
  Serial.print("Current is  ");
  Serial.print(current); // default two decimal places | ...(current, 1);  is one decimal place
  Serial.println("  Amp");

  delay(100); // use a non-blocking delay when combined with other code
}
