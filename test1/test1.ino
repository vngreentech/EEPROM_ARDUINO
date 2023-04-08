
#include <EEPROM.h>

int diachi = 645;

byte giatri = 55; //byte là kiểu số nguyên từ 0-255

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  EEPROM.write(diachi, giatri);

  diachi = diachi + 1;
  
  if (diachi == EEPROM.length()) 
  {
    diachi = 0;
  }

  delay(100);
}
