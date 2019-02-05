int y=digitalRead(26); //Segundo//
 int x=digitalRead(27); //Primero//
  int xmm, ymm,a,b;
 
  
  
  void setup()
  {
     pinMode(26,INPUT);
     pinMode(27,INPUT);
     Serial.begin(9600);
    }
    
    void loop()
    {
    contador();
      }
  
  
  
  


void contador()
{
  
  if(x==0&&y==0)
  {
   if(xmm==LOW&&ymm== HIGH)
   {
     a++;
   }
   if(xmm==HIGH&&ymm==LOW)
   {
     a--;
   }
   xmm=x;
   ymm=y;
  }
  
  if(x==LOW&&y==HIGH)
  {
   if(xmm==HIGH&&ymm== HIGH)
   {
     a++;
   }
   if(xmm==LOW&&ymm==LOW)
   {
     a--;
   }
   xmm=x;
   ymm=y;
  }
  
  if(x==HIGH&&y==HIGH)
  {
   if(xmm==HIGH&&ymm== LOW)
   {
     a++;
   }
   if(xmm==LOW&&ymm==HIGH)
   {
     a--;
   }
   xmm=x;
   ymm=y;
  }
  
  
  if(x==HIGH&&y==LOW)
  {
   if(xmm==LOW&&ymm== LOW)
   {
     a++;
   }
   if(xmm==HIGH&&ymm==HIGH)
   {
     a--;
   }
   xmm=x;
   ymm=y;
  }

 
  b=a;
  
  Serial.print(x);
   Serial.print("  ");
  Serial.print(y);
   Serial.print("  ");
    Serial.print("  ");
  Serial.println(b);  
}
