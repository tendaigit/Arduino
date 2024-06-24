
int temp = 60;
void setup() {
  // put your setup code here, to run once:
 pinMode(4,INPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
//digitalRead(4)== temp;

if(temp < 50 && temp > 10){
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  delay(500);
}
else if(temp>50 && temp<70){
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500); 
}
else{
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8,LOW);
  delay(500);
}
}
