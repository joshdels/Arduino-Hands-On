const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int sound = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sound, OUTPUT);

}
// functions pratice
void led_on(int ledPin){
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

void led_blinking(int ledPin){
    int i = 0;
    while (i < 10) { 
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
        i++;  
    }
}

void loop() {
  led_on(led1);
  led_on(led2);
  delay(1000);
  led_blinking(sound), 
  // led_on(led1);
  led_blinking(led3);
}
