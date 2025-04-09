#inlcude "LED.h"

//Create blueprints
LED led1(13);
LED led2(12);
LED led3(11);
LED sound(10);

void setup() {

}

void loop() {
  led1.led_on();
  led2.led_on();
  led3.led_on();
  delay(100);
  led1.led_blinking();
  led2.led_blinking();
  sound.led_blinking();
}
