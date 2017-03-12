int bulb=8;
int i=0;
int j=0;
String in;
String detected[3];
int pin[2];
int m=0;
String devices[]={"bulb", "bulbs", "CFL", };
void setup()
{
 
  pinMode(bulb, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  while(Serial.available()==0);
  Serial.flush();
  in = Serial.readString();
  Serial.println(in);
  
  {
  if(in.indexOf("on")>=0)
{
  Serial.println("ON");
  object("on");
  //digitalWrite(led, HIGH);
  //Serial.println("Led on");
}  
if(in.indexOf("off")>=0)
{
  Serial.println("OFF");
  object("off");
  //digitalWrite(led, LOW);
  //Serial.println("Led off");
}
}
}

void object(String data)
{
  if(data == "on")
  {
     if(in.indexOf("bulb")>=0 || in.indexOf("cfl")>=0 || in.indexOf("CFL")>=0)
   {
    digitalWrite(bulb, LOW);
    Serial.println("Bulb OFF");
                      // delay(3000);
   }
   
    
  }
  if(data == "off")
  { 
  
   
    if(in.indexOf("bulb")>=0 || in.indexOf("cfl")>=0 || in.indexOf("CFL")>=0)
    {
    digitalWrite(bulb, HIGH);
    Serial.println("Bulb ON");
                      //delay(3000);
    }

  
  }
  return;
}
