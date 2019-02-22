#ifndef MOTORDRIVER_h
#define MOTORDRIVER_h

class motor_driver{
    public:
        int setPWM(int pwmValue, int pinIfPositive, int pinIfNegative);
        int convertPercent(double percent);
        void setSpeedPercent(double leftPercent, double rightPercent);
        void setSpeedPWM(int leftPWM, int rightPWM);
        void stop();

    motor_driver();
    ~motor_driver();
};

#endif /*MOTORDRIVER_h*/