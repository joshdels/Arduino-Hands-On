#ifndef PROXIMITY_H
#define PROXIMITY_H

class PROXIMITY {
  private:
    int trig;
    int echo;
    int thresholdDistance;

  public:
    PROXIMITY(int trigPin, int echoPin);

    void get_distance();
};
#endif