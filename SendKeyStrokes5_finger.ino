/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>
#include <HLK_fingerprint.h>
#define FP_RX  16
#define FP_TX  17
constexpr int CTRL = -1;  // set to GPIO number to enable low-power circuit; -1 = disabled

FingerprintModule fp(Serial1, FP_RX, FP_TX);


BleKeyboard bleKeyboard;
const int buttonPin = 0;
int previousButtonState = HIGH;
void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(buttonPin, INPUT_PULLUP);
  bleKeyboard.begin();
if (CTRL >= 0) {
        pinMode(CTRL, OUTPUT);
        digitalWrite(CTRL, HIGH);  // assert HIGH to enable low-power circuit
    }

    if (!fp.begin()) {
        Serial.println(F("ERROR: Module not found. Check wiring and baud rate."));
        while (true) delay(1000);
    }

    Serial.print(F("Module ready  |  "));
    Serial.print(fp.getTemplateCount());
    Serial.print(F(" / "));
    Serial.print(fp.capacity());
    Serial.println(F(" slots enrolled."));
    Serial.println(F("Place a finger on the sensor..."));

    fp.ledBreathing(FP_LED_BLUE);  // idle breathing animation
}

  


void loop() {
  if(bleKeyboard.isConnected()) 
  {
    
 uint16_t score = 0;
 int16_t  id    = fp.matchFingerprint(score);  // blocks up to 10 s waiting for finger

    if (id == 0) 
    {
    bleKeyboard.println("password0");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
    bleKeyboard.releaseAll();
   
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);

    }
   if (id == 1) 
    {
    bleKeyboard.println("12345678");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
    bleKeyboard.releaseAll();
      
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);

    }

       if (id == 2) 
    {

    bleKeyboard.println("87654321");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
    bleKeyboard.releaseAll();
      
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);
        


    }
       if (id == 3) 
    {

   bleKeyboard.println("password1");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
   bleKeyboard.releaseAll();
     
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);
        

    }
       if (id == 4) 
    {

bleKeyboard.println("password2");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
   bleKeyboard.releaseAll();
      
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);


    }
       if (id == 5) 
    {
bleKeyboard.println("password3");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
   bleKeyboard.releaseAll();
      
      Serial.println("valide user!");  
        fp.ledFlash(FP_LED_GREEN, 2);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);

    }
    
    
    if (id == -1) 
    {
        
        Serial.println("error user!");
        fp.ledFlash(FP_LED_RED, 3);
        delay(1000);
        fp.ledBreathing(FP_LED_BLUE);

    }
  
 
}
 
}
