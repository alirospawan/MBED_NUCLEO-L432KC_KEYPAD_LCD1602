#include "mbed.h"
#include "keypad.h"
#include "TextLCD.h"

Serial pc(USBTX, USBRX);

            //RS, E, D4, D5, D6, D7
//TextLCD lcd(PB_3, PA_0, PB_4, PB_5, PA_2, PA_3, TextLCD::LCD16x2);
//TextLCD lcd(PA_9, PA_0, PA_5, PA_1, PA_6, PA_3, TextLCD::LCD16x2);
TextLCD lcd(PA_0, PA_2, PA_3, PA_4, PA_5, PA_6, TextLCD::LCD16x2);

int main() {
    pc.baud(115200);
                //  c0   c1   c2   c3  r0   r1   r2   r3    
    Keypad keypad( PB_1, PA_8, PA_11, PA_10, PA_12, PB_0, PB_7, PB_6 ); 
    keypad.enablePullUp();
    
    char key;
    lcd.locate(0,0);        lcd.printf("PROGRAMMABLE");
    lcd.locate(0,1);        lcd.printf("WAVE GENERATOR");
    wait(3);
    lcd.cls();
    
    while (1) 
    {
         key = keypad.getKey();    
         if(key != KEY_RELEASED)
         {
             lcd.locate(10,0);
             lcd.printf("%c",key);
             pc.printf("%c\n",key);
             wait(0.6);
         }
         
         if (key == '*'){
             lcd.cls();
             lcd.locate(0,0);        lcd.printf("SETUP CLEAR");
         }
    }
}
