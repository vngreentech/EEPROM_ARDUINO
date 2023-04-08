
#include <EEPROM.h>

int diachi = 645;
byte giatri; //Kiểu số nguyên nằm trong 0-255

void setup() 
{
  Serial.begin(9600);
  
}

void loop() 
{
  giatri = EEPROM.read(diachi);

  Serial.print("Địa chỉ: "); Serial.print(diachi); Serial.print("   ");
  Serial.print("Giá trị: "); Serial.println(giatri);

//  diachi = diachi + 1;
//  
//  if (diachi == EEPROM.length()) 
//  {
//    diachi = 0;
//  }

  delay(500);
}
