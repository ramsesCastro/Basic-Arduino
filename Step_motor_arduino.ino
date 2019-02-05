//Control de MOTOR a Pasos en Secuencia Normal (2 bobinas activadas por cada paso) para 4 estaciones

int motorPin1 = 15; // Pines del Motor
int motorPin2 = 16;
int motorPin3 = 17;
int motorPin4 = 18;
int delayTime = 300; // DelayTime determina la espera entre uno y otro paso
int delayTime1 = 50; // DelayTime1 determina la velocidad de giro entre uno y otro paso
int count = 0;

void setup()
{
pinMode(motorPin1, OUTPUT); // Configuración de los Pines como salida digital
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
}

void loop()
{

for (count = 0; count < 3; count++) // Aqui en el for es donde se manipulan los grados que se desean asignar al motor
{
// Los pines se activan en secuencia de las manecillas del reloj

// Punto A (Primero)
digitalWrite(motorPin1, HIGH); //cafe – A
digitalWrite(motorPin2, LOW); //negro – B
digitalWrite(motorPin3, LOW); //morado – C
digitalWrite(motorPin4, HIGH); //naranja – D
delay(delayTime1); // Un micro segundo de espera

// Punto B (Segundo)
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(delayTime1);
// Punto C (Tercero)
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(delayTime1);

// Punto D (Cuarto)
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, HIGH);
delay(delayTime1);

} //End For

delay(delayTime); // Se espera 3 segundos despues de cada paso y al iniciar la secuencia

}//End Loop
