
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            8
#define NUMPIXELS      26

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30; 
int pisca = 200;
int acendeTodos = 1;

void setup() {
  
  pixels.begin();
    for(int z=0; z<3; z++){
      
        for(int n=0;n<14;n++){        
              pixels.setPixelColor(n, pixels.Color(0,191,255)); 
              if(n != 10) {
              pixels.setPixelColor(n+14, pixels.Color(255,255,255)); 
              }  
              delay(delayval);              
              pixels.show();  
        }
        for(int s=0;s<23;s++){ 
            if(z!=2) {  
                pixels.setPixelColor(s, 0);    
                delay(delayval);
                pixels.show(); 
            }
        }       
    }
 
      delay(delayval);  
      for(int x=0; x<3; x++) {              
        clearLEDs();
        delay(pisca);
        acendeLeds();
        delay(pisca);
        pixels.show();
        
     }
     pixels.setPixelColor(14, pixels.Color(255,255,255)); 
        pixels.setPixelColor(15, pixels.Color(255,255,255));
        pixels.setPixelColor(16, pixels.Color(255,255,255));
        pixels.setPixelColor(17, pixels.Color(255,255,255));
        pixels.setPixelColor(18, pixels.Color(255,255,255));
        pixels.setPixelColor(19, pixels.Color(255,255,255));
        pixels.setPixelColor(20, pixels.Color(255,255,255));
        pixels.setPixelColor(21, pixels.Color(255,255,255));
        pixels.setPixelColor(22, pixels.Color(255,255,255));
        pixels.setPixelColor(23, pixels.Color(255,255,255));        
        pixels.show();
        int b;
        for(int a = 0; a < 256; a++) { //Acender de forma gradual o led central no final.
          if(a < 192) {
            b = a;
          }
          pixels.setPixelColor(24, pixels.Color(0,b,a));  
          pixels.show();
          delay(50);
        }
        delay(15000);
        clearLEDs();        
}

void loop() {  
    
}

void acendeLeds(){
  for(int i=0;i<14;i++){        
       pixels.setPixelColor(i, pixels.Color(0,191,255)); 
       //pixels.setPixelColor(24, pixels.Color(0,191,255));  
       pixels.show();   
  }
      
}
 

//Função apaga LEDs geral
void clearLEDs(){
  for (int p=0; p<26; p++){
    pixels.setPixelColor(p, 0);
     pixels.show();
  }
}
