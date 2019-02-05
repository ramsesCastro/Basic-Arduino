
//Control PID de un motor CD

//PINES DEL ARDUINO
int entrada = A0;
int entradaM = A1;

int In1 = 5;
int In2 = 6;

//VARIABLES Y CONSTANTES
int PotD, PotM;
float ei, ed;
int e;
float error, eUlt;
float PID;

int t = 17;
float Kp = 53.8873;
float Ki = 299.73;
float Kd = 5.5984;

int Wd= 0.005;

void setup() {
  Serial.begin(9600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
}

void loop() {
  PotD = analogRead(entrada);
  PotM = analogRead(entradaM);
  
  e = PotD - PotM;
  error = float(e)*5.0/1023.0;
  
  if( error< Wd && error>-Wd)  ei += e*t/1000.0;
  else ei = 0;
  ed = (error - eUlt)/t*1000.0;
  PID = abs(Kp*error + Ki*ei + Kd*ed);
  eUlt = error;

  
  if( error>0 )  {
    analogWrite(In1,PID);
    digitalWrite(In2,LOW);
  }
  if( error<0 )  {
    digitalWrite(In1,LOW);
    analogWrite(In2,PID);
  }
  if (PID > 255)  PID = 255;
  
  Serial.print(PotD);
  Serial.print("  ");
  Serial.print(PotM);
  Serial.print("  ");
  Serial.print(error);
  Serial.print("  ");
  Serial.print(ei);
  Serial.print("  ");
  Serial.print(ed);
  Serial.print("  ");
  Serial.println(PID);
  delay(t);
}
