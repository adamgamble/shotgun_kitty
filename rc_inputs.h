#ifndef rc_inputs_h
#define rc_inputs_h

class RCInputs {
  public:
    RCInputs();
    void get_inputs();
    float throttle_percentage();

    //Public Variables
    int current_throttle;

  private:
    void setup_pins();
    int read_input(int pin);
};

#endif
