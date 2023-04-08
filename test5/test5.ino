#include <Servo.h>
#include <EEPROM.h>

Servo servo1;
int servo = 7;

int diachi1 = 0;
int diachi2 = 0;
byte giatri; //byte là kiểu số nguyên từ 0-255

int set = 5; int gtset; int demset = 0;
int chay = 6; int gtchay; int demchay = 0;
int macdinh = 1;
int bientro = A0; int gtbientro; int gtbiendoi;

unsigned long thoigian;

void setup() 
{
  Serial.begin(9600);

  servo1.attach(servo);

  pinMode(set, INPUT_PULLUP);
  pinMode(chay, INPUT_PULLUP);
  pinMode(bientro, INPUT);
  
  thoigian = millis();
}

void loop() 
{
  gtset = digitalRead(set);
//  Serial.print("Nút Set: "); Serial.print(gtset); Serial.print("  ");
  gtchay = digitalRead(chay);
//  Serial.print("Nút Chạy: "); Serial.print(gtchay); Serial.print("  ");
  gtbientro = analogRead(bientro);
//  Serial.print("Biến trở: "); Serial.print(gtbientro);  Serial.print("  ");

  gtbiendoi = map(gtbientro, 0, 1023, 0, 180);
  servo1.write(gtbiendoi);
//  Serial.print("Servo: "); Serial.println(gtbiendoi);
//  Serial.println("  ");

if (gtchay != macdinh)
{
   if (gtchay == 0)
    { 
      if (demchay >= 1)
      {
        demchay = 0;
      }
      else
      {
        demchay ++;
      }  
    }
  macdinh = gtchay;
  delay(100);
}
//Serial.print("Đếm chạy: "); Serial.println(demchay);
     
   if (demchay == 0)
      {
        if (gtset != macdinh)
        {
          if (gtset == 0)
          {
            demset ++;
            if (demset > 0)
            {
              EEPROM.write(diachi1, gtbiendoi);
              delay(50);
              Serial.print("           "); 
              Serial.print("Địa chỉ 1: "); Serial.print(diachi1); Serial.print("   ");
              Serial.print("Góc Servo: "); Serial.println(gtbiendoi);
              Serial.println("  ");
              diachi1 = diachi1 + 1;
                if (diachi1 == EEPROM.length()) 
                {
                  diachi1 = 0;
                } 
              demset = 0;   
            }
          }
          macdinh = gtset;
          delay(100);
        }
      }
      
   if (demchay == 1)
      {
        if (diachi2 <= diachi1)
        {                                     
          giatri = EEPROM.read(diachi2);
          servo1.write(giatri);
          delay (50);
          if ( (unsigned long) (millis() - thoigian) > 3000)
           { 
             thoigian = millis();
             Serial.print("           "); 
             Serial.print("Địa chỉ 2: "); Serial.print(diachi2); Serial.print("   "); 
             Serial.print("Góc Servo: "); Serial.println(giatri);   
             diachi2++;       
           }
        }
        else
        {
          diachi2 = 0;
        }
      }
  
} //Kết loop
