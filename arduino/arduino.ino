    // Simple NeoPixel test.  Lights just a few pixels at a time so a
    // 1m strip can safely be powered from Arduino 5V pin.  Arduino
    // may nonetheless hiccup when LEDs are first connected and not
    // accept code.  So upload code first, unplug USB, connect pixels
    // to GND FIRST, then +5V and digital pin 6, then re-plug USB.
    // A working strip will show a few pixels moving down the line,
    // cycling between red, green and blue.  If you get no response,
    // might be connected to wrong end of strip (the end wires, if
    // any, are no indication -- look instead for the data direction
    // arrows printed on the strip).
     
    #include <Adafruit_NeoPixel.h>
     
    #define PIN      6
    #define N_LEDS 30

//    int a[5][5] = {{1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1},{1,0,0,0,1}, {1,1,1,1,1}
//      };
     
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
     
    void setup() {
      strip.begin();
    }
     
    void loop() {
      chase(strip.Color(255, 0, 0)); // Red
    
    }
     
    static void chase(uint32_t c) {
      for(uint16_t i=0; i < 30; i++) {
//       for( uint16_t j = 0; j < 5; j++)
//       {
//        if(a[j][i] == 1)
//        {
//          strip.setPixelColor(j, c); 
//          strip.show(); 
//          delay(5 ); 
//          strip.setPixelColor(j, strip.Color(0,0,0)); 
//          strip.show();
//        }
//       }
       
          strip.setPixelColor(i  , c); // Draw new pixel
          //strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
          strip.show();
          delay(25);
      }
    }
