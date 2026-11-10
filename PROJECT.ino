int Data;
int val;
int AR = LOW;
int DR;
int i;
int curr = LOW;
int RR = digitalRead(7);
void setup() {
pinMode(A0,INPUT);
pinMode(A2,INPUT);
pinMode(7,INPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);

}

void loop() 
{
  Data = 153;
  int ABRA = 523;
  switch (ABRA / 128)
  {
   case 0:  // 0 - 127
    Serial.println("Non-Return-to-Zero Level");
     for(i=9;i>=0;i--)
      {
        digitalWrite(9,bitRead(Data,i));
                                if(digitalRead(9) == LOW) 
                                 {
                                   digitalWrite(8, HIGH);
                                 }
      
                                else {
                                      digitalWrite(8, LOW);
                                     }
                                if(digitalRead(7) == LOW) {
                                     digitalWrite(6, HIGH);
                                    }
                                else {
                                digitalWrite(6, LOW);}
      
       
            digitalWrite(4,HIGH);
        delay(5);
        digitalWrite(4,LOW);
        delay(5);
        val = digitalRead(9);}
    break;

  case 1:  // 128 - 255
    Serial.println("Non-Return-to-Zero Mark");
       for(int i=9;i>=0;i--)
      {
        digitalWrite(9,bitRead(Data,i));
            int SR = LOW;
    if(digitalRead(9) != SR){
          digitalWrite(8, !digitalRead(8));   
        

    SR = digitalRead(8);
    }
      
    if (digitalRead(7) == curr  )
    {
      digitalWrite(6,LOW);
    }
    else  {
     digitalWrite(6,HIGH); 
     curr = !curr;
    }
      digitalWrite(4,HIGH);
        delay(5);
        digitalWrite(4,LOW);
        delay(5);
        val = digitalRead(4);}
    break;

  case 2:  // 256 - 383
    Serial.println("Non-Return-to-Zero-Space");
    for(int i=9;i>=0;i--)
      {
                               digitalWrite(9,bitRead(Data,i));
                               DR = HIGH;
                                if(digitalRead(9) != DR){
                                   digitalWrite(8, !digitalRead(8));   
                                   val = digitalRead(8);
                                  }
                                if(digitalRead(7) != AR)
                                   {
                                    digitalWrite(6,LOW);
                                     AR = !AR;
                                   }
                                else
                                   {
                                   digitalWrite(6,HIGH);
                                   }
                                   digitalWrite(4,HIGH);
        delay(5);
        digitalWrite(4,LOW);
        delay(5);
        val = digitalRead(9);
      }
                                   break;

  case 3:  // 384 - 511
    Serial.println("Manchester Encoding");
        for(int i=9;i>=0;i--)
      {
                              digitalWrite(9,bitRead(Data,i));
                              val = digitalRead(7);
                             if(digitalRead(9) == HIGH)
                              {
                               digitalWrite(8,LOW);
                               delay(5);
                               digitalWrite(8,HIGH);
                               delay(5);
                              }
                            else
                              {
                               digitalWrite(8,HIGH);
                               delay(5);
                               digitalWrite(8,LOW);
                               delay(5);
                               }
      }
    break;

  case 4:  // 512 - 639
    Serial.println("Manchester Decoding");
      for(int i=9;i>=0;i--)
      {
                    val = digitalRead(7);
                    if (digitalRead(7) == AR)
                     {
                      digitalWrite(6,HIGH);
                      delay(10);
                     }
                    else
                     {
                      digitalWrite(6,LOW);
                      delay(10);
                     }
      }
    break;

  case 5:  // 640 - 767
    Serial.println("Differential Manchester Encoding");
      for(int i=9;i>=0;i--)
      {
                             digitalWrite(9,bitRead(Data,i));
                             if(digitalRead(9) == 0)
                             {
                              AR = !AR;
                              digitalWrite(8,AR);
                             }
                              delay(5);
                              AR = !AR;
                              digitalWrite(8,AR);
                              delay(5);
      }  
    break;

  case 6:  // 768 - 895
    Serial.println("Differential Manchester Decoding");
    DR = digitalRead(7);
      for(int i=9;i>=0;i--)
      {
        delay(5);
       int  CR = !digitalRead(7);
                   if(CR != RR)
                     {
                      digitalWrite(6,LOW);
                      }
                   else
                      {
                     digitalWrite(6,HIGH); 
                     }
                     RR = CR;
                    delay(5);
      }delay(1000); 
    break;

  case 7:  // 896 - 1023
    Serial.println("Repeater");
      val = analogRead(A0);
        if(digitalRead(7) >= val/2)
           {
            digitalWrite(6,HIGH);
           }
        else
           {
           digitalWrite(6,LOW);
           }
    break;

  default:
    Serial.println("Out of range");
    break;
      }
      }
