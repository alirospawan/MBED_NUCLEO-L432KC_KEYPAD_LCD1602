#include "mbed.h"
#include "keypad.h"

Serial pc(USBTX, USBRX);
 
int main() {
    pc.baud(115200);
    
                //  c0   c1   c2   c3  r0   r1   r2   r3    
    Keypad keypad( PB_1, PA_8, PA_11, PA_10, PA_12, PB_0, PB_7, PB_6 ); 
    keypad.enablePullUp();
    
    char key;
    pc.printf("PROGRAMMABLE\n");
    pc.printf("WAVE GENERATOR\n");
    wait(3);
    //lcd.cls();
    
    while (1) 
    {
         key = keypad.getKey();    
         if(key != KEY_RELEASED)
         {
             pc.printf("%c\n",key);
             wait(0.6);
         }
         
         if (key == '*'){
             //lcd.cls();
             pc.printf("SETUP CLEAR\n");
         }
    }
}
