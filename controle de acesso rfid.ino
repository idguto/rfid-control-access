
#include <SPI.h>
#include <RFID.h>
#include <avr/wdt.h>

#define SS_PIN 10
#define RST_PIN 9
#define rele 8
#define led 7
RFID rfid(SS_PIN, RST_PIN); 

void libera(void);
void number(void);

int senha1[]={ 
  220, 110, 203,  7, 126};      
int senha2[]={ 
  144,  72,  42, 51, 193};    
int senha3[]={ 
  218,  90,  243, 19, 96};     
int senha4[]={ 
  253,  228,  190, 242, 85};   
int senha5[]={ 
  23,  199,  102, 245, 67};  
int senha6[]={ 
  0,  0,  0, 0, 0};
void setup()
{ 
  pinMode(rele,OUTPUT);
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  digitalWrite(rele,LOW);
  wdt_enable(WDTO_1S);
}

void loop()
{
  digitalWrite(rele,LOW);
  wdt_reset();
  if (rfid.isCard()) {
     if (rfid.readCardSerial())
    {
      if (   rfid.serNum[0] == senha1[0]
        && rfid.serNum[1] == senha1[1] 
        && rfid.serNum[2] == senha1[2]
        && rfid.serNum[3] == senha1[3] 
        && rfid.serNum[4] == senha1[4]
        ) 
      { 
        libera();
      }

      else if(rfid.serNum[0] == senha2[0]
        && rfid.serNum[1] == senha2[1] 
        && rfid.serNum[2] == senha2[2] 
        && rfid.serNum[3] == senha2[3]
        && rfid.serNum[4] == senha2[4]
        ) 
      { 
        libera();
      } 
      else if(rfid.serNum[0] == senha3[0]
        && rfid.serNum[1] == senha3[1] 
        && rfid.serNum[2] == senha3[2] 
        && rfid.serNum[3] == senha3[3]
        && rfid.serNum[4] == senha3[4]
        ) 
      { 
        libera();
      }
      else if(rfid.serNum[0] == senha4[0]
        && rfid.serNum[1] == senha4[1] 
        && rfid.serNum[2] == senha4[2] 
        && rfid.serNum[3] == senha4[3]
        && rfid.serNum[4] == senha4[4]
        ) 
      { 
        libera();
      }
      else if(rfid.serNum[0] == senha5[0]
        && rfid.serNum[1] == senha5[1] 
        && rfid.serNum[2] == senha5[2] 
        && rfid.serNum[3] == senha5[3]
        && rfid.serNum[4] == senha5[4]
        ) 
      {
        libera();
      }
      else if(rfid.serNum[0] == senha6[0]
        && rfid.serNum[1] == senha6[1] 
        && rfid.serNum[2] == senha6[2] 
        && rfid.serNum[3] == senha6[3]
        && rfid.serNum[4] == senha6[4]
        ) 
      { 
        libera(); 
      }

      wdt_reset();
      number();   
    }
  }

  rfid.halt();
   wdt_reset();
}
void libera()
{
  
  digitalWrite(rele,HIGH);
  delay(200);
  digitalWrite(rele,LOW);
  
  number();
  wdt_reset();
}
void number()
{
  
  Serial.println("Cardnumber:");
  Serial.print("Dec: ");
  Serial.print(rfid.serNum[0],DEC);
  Serial.print(", ");
  Serial.print(rfid.serNum[1],DEC);
  Serial.print(", ");
  Serial.print(rfid.serNum[2],DEC);
  Serial.print(", ");
  Serial.print(rfid.serNum[3],DEC);
  Serial.print(", ");
  Serial.print(rfid.serNum[4],DEC);
  Serial.println(" ");
}

