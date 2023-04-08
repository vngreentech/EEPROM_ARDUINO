#include <Servo.h>
#include <EEPROM.h>

Servo servo1;
int servo = 7;

int diachi = 0;
byte giatri; //byte là kiểu số nguyên từ 0-255

void setup() 
{
  Serial.begin(9600);

  servo1.attach(servo);
  
}

void loop() 
{
  for (diachi = 0; diachi < 10; diachi++)
  {
    giatri = random(0,180);
    EEPROM.write(diachi, giatri);
    Serial.print("Địa chỉ WRITE: "); Serial.print(diachi); Serial.print("   ");
    Serial.print("Giá trị: "); Serial.println(giatri); 
    delay(100);    
  }
  delay(5000);
  Serial.println("   ");
  
  for (diachi = 0; diachi < 10; diachi++)
  {
    giatri = EEPROM.read(diachi);
    Serial.print("Địa chỉ READ: "); Serial.print(diachi); Serial.print("   ");
    Serial.print("Giá trị: "); Serial.println(giatri); 

    servo1.write(giatri);
    delay(1000);
  }
  Serial.println("   ");
  delay(3000);
}
