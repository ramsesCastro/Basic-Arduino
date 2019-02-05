#include <LiquidCrystal.h>


int x=0,x2,x3,x4, p=0;
int btn1=0;
int valor = 0;
int valor2=0;

boolean selec = false;

volatile int inc;



LiquidCrystal lcd(7, 8, 10, 16, 14, 15);


void setup() {

attachInterrupt(0,int5,RISING);   
  
  pinMode(9,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(btn1,INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {


  
  
  
  if(valor==0)
  {
    lcd.setCursor(0,0);
    lcd.print("Sin apagado");
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    cuenta();
    delay(100);
    lcd.clear();
    
  }
  
  else if(selec==false)
  {
    lcd.setCursor(0,0);
    lcd.print("Apagado:");
    lcd.setCursor(9,0);
    lcd.print(valor/60);
    lcd.setCursor(13,0);
    lcd.print("min");
    
    cuenta();
    apaga();
    delay(1);
    if(valor2>0)
    {
      lcd.setCursor(0, 1);
      lcd.print("Quedan:");
      lcd.setCursor(8,1);
      lcd.print(valor2);
      lcd.setCursor(13,1);
      lcd.print("seg");
      
    }
  }
}



void cuenta()
{
  x=millis()/1000;
  x3=x-x2;
  valor2=valor-x3;
}

void apaga()
{
  if(valor2>0)
  {
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
  }
  else
  {
    digitalWrite(9,LOW);  
    digitalWrite(5,LOW);
  }
}



void int5() 
{
    lcd.clear();    
    selec=true;
    if(selec)
    {
    increment();
    x2=x;
    
    lcd.clear();
    }
}


void increment() {
  selec=false;
  delay(1);
  valor = valor + 900;
  
  if(valor>=3600)
  {
   lcd.clear();
   valor=0; 
   valor2=0;
   lcd.clear();
  }
  
}







