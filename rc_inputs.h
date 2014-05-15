#ifndef rc_inputs_h
#define rc_inputs_h

class RCInputs {
  public:
    RCInputs();
    void loop();
    float throttle_percentage();

    //Public Variables
    int current_throttle;
    int current_aileron;
    int current_elevator;
    int current_rudder;
    int current_flight_mode;

  private:
    void setup_pins();
    int read_input(int pin);
};

#endif



