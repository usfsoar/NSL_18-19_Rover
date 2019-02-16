# NSL_18-19_Rover
Code for the rover for NASA Student Launch 2018-19.

## Instructions
Download all the files and compile nsl_rover_18-19.ino using the Arduino IDE.

*Pins for Adafruit DRV8871 Motor 1 and Motor 2*

```
MOTOR   INPUT    PIN
MOTOR1  INPUT1   8
MOTOR1  INPUT2   9
MOTOR2  INPUT1   10
MOTOR2  INPUT2   11
```

## Organization

The `master` [branch](https://github.com/usfsoar/NSL_18-19_Rover/branches)
should only hold the code that is currently in use in the rover. Create new
branches for new features or fixes that aren't immediately implemented. IE:
`feature/led-output` or `fix/startup-crash`. When ready to use a branch's code
in the rover itself, submit a
[pull request](https://github.com/usfsoar/NSL_18-19_Rover/pulls). Don't merge
pull requests until the code is tested in the rover.

There are [milestones](https://github.com/usfsoar/NSL_18-19_Rover/milestones)
for each launch. If you think of a feature or find a problem, first create an
issue, then assign it to a milestone, then create a branch for it if you want to
work on it.

At every launch or major test, create a new 
[release](https://github.com/usfsoar/NSL_18-19_Rover/releases). This will allow
us to easily refer back to the code we were using at that event. 