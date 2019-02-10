#ifndef MOTORDRIVER_h
#define MOTORDRIVER_h

class motor_driver{
    public:
        int convertPercent(double input);
        void setSpeedPercent(double leftPercent, double rightPercent);
        void setSpeedPWM(int leftPWM, int rightPWM);
        void stop();

    motor_driver();
    ~motor_driver();
};

#endif /*MOTORDRIVER_h*/