#include "mbed.h"

PwmOut redLight(p21);
PwmOut sound(p22);
PwmOut blueLight(LED1);

DigitalIn switch19(p19);
DigitalIn switch20(p20);

int main() {
    switch20.mode(PullDown);
    switch19.mode(PullUp);

    redLight.period(0.7);
    redLight.pulsewidth(0.7);
    redLight=1;

    sound = 0;

    blueLight.period(0.7);
    blueLight.pulsewidth(0.7);
    blueLight = 0;
    
  while(1) {
      
      if(switch20 == 1){

          wait_ms(25);

          sound.period(1/960.0);
          blueLight = 1;
          sound = 0.5;
          wait(0.7);

          redLight = 0;
          blueLight = 0;
          sound.period(1/1140.0);
          wait(0.7);

          redLight = 1;
          redLight.pulsewidth(0.7);

          sound = 0;
          
      }

      if (switch19 == 0){
        
        wait_ms(25);

        sound.period(1/800.0);
        sound = 0.5;


        for (int i = 8000; i <= 12000; i+=10){
            sound.period(10.0/(i));
            redLight = (12000-i)/4000.0;
            wait(10.0/i);
        }

        for (int i = 12000; i >= 8000; i-=10){
            sound.period(10.0/i);
            redLight = (12000-i)/4000.0;
            wait(10.0/i);
        }

        redLight = 1;
        redLight.pulsewidth(0.7);

        sound = 0;
      }
    
  }
}
