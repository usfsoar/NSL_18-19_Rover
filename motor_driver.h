#ifndef MOTORDRIVER_h
#define MOTORDRIVER_h

#define MOTOR1_IN1 9
#define MOTOR1_IN2 10
#define MOTOR2_IN1 11
#define MOTOR2_IN2 12

class motor_driver{
    public:
        int convertPercent(double input);
        void setSpeedPercent(double leftPercent, double rightPercent);
        void setSpeedPWM(int leftPWM, int rightPWM);
        void stop();
};

#endif /*MOTORDRIVER_h*/