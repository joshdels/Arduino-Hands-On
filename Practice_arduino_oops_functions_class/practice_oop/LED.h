#ifndef LED_H
#define LED_H

class LED {
  private:
    int pin;

  public:
    LED(int ledPin);

    // functions pratice
    void led_on();

    void led_blinking();
    
};
#endif