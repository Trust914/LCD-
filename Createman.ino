#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void manstag(int col,int row,int row1,int byteval,int maxprint);

LiquidCrystal_I2C lcd(0x27,16,2);

// binary of each character pixels to display on the LCD
byte man[]={B00000,
              B00011,
              B00011,
              B00011,
              B00001,
              B00001,
              B11111,
              B11111};
byte man1[]={
              B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011};
byte man2[]= {B00000,
                B11000,
                B11000,
                B11000,
                B10000,
                B10000,
                B11111,
                B11111};
byte man3[]={B11000,
             B11000,
             B11110,
             B11110,
             B00110,
             B00110,
             B00000,
             B00000};  
// man character move forward 

  // 1 of 4
byte man4[]={B00000,
              B00011,
              B00011,
              B00011,
              B00001,
              B00001,
              B11111,
              B11111
                    };
  // 2 of 4                  
  byte man5[]={B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011,
               B00011
                      };
  // 3 of 4
  byte man6[]={
                B00000,
                B11000,
                B11000,
                B11000,
                B10000,
                B10000,
                B11111,
                B11111
                        } ;
  byte man7[]={
                B11000,
                B11000,
                B11111,
                B11111,
                B00000,
                B00000,
                B00000,
                B00000
                      };                    
  


void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();


  lcd.createChar(0,man);
  lcd.createChar(1,man1);
  lcd.createChar(2,man2);
  lcd.createChar(3,man3);
   lcd.createChar(4,man4);
  lcd.createChar(5,man5);
  lcd.createChar(6,man6);
  lcd.createChar(7,man7);
  
  
} 

void loop() 
{
    manstag(0,0,0,0,2);
    manstag(4,0,0,4,6);
    
}

void manstag(int col,int row,int row1,int byteval,int maxprint)
{
   for( row,byteval; row < 2,byteval<maxprint; row++,byteval++)
   {
     lcd.setCursor(col,row);
     lcd.write(byte(byteval));    
   }
   col++;
   if(col>=1 || col >=5)
   {
     if (col == 1)
     {
       col =1;
       byteval = 0;
     }
     else if(col == 5)
     {
       col = 5;
       byteval = 4;
     }
     for (row1,byteval; row1<2,byteval<maxprint; row1++,byteval++)
     {
       lcd.setCursor(col,row1);
       lcd.write(byte(byteval+2));
     }
   }
}
