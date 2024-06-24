
const int voltageSensor = A0;

float Vout = 0.0;
float Vin = 0.0;
int value = 0;


void setup()
{
//Serial.begin(9600);
 Serial.begin(9600);

}

void loop()
{
  value = analogRead(voltageSensor);
  Vout = (value * 5.0) / 1024.0;
  
  Vin = Vout * 5.0 ;
  
  //Serial.print("Input = ");
  //Serial.println(Vin;
 Serial.print("Input: ");
  Serial.print(Vin);//print the voltge
  Serial.println("V");
  
  delay(500);
}
