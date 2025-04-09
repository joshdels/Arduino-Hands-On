class LED {
  private:
    int pin;

  public:
  LED(int ledPin){
    pin = ledPin;
    pinMode(pin, OUTPUT);
  }

    // functions pratice
  void led_on(){
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
  }

  void led_blinking(){
    int i = 0;
    while (i < 10) { 
        digitalWrite(pin, HIGH);
        delay(100);
        digitalWrite(pin, LOW);
        delay(100);
        i++;  
    }
  }
};


//Create blueprints
LED led1(13);
LED led2(12);
LED led3(11);
LED sound(10);

void setup() {
  // no need since it initalized by the constructor
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
