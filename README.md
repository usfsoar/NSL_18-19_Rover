# NSL_18-19_Rover [![Build Status](https://travis-ci.org/usfsoar/NSL_18-19_Rover.svg?branch=master)](https://travis-ci.org/usfsoar/NSL_18-19_Rover)
Code for the rover for NASA Student Launch 2018-19.

_Note_: Build status (above) confirms that the latest code compiles on Arduino,
not that it necessarily behaves as expected.

## Instructions
Download all the files and compile `nsl_rover_18-19.ino` using the Arduino IDE.

### Arduino Pin Configuration

| NAME            | PIN | DESCRIPTION      |
|-----------------|-----|------------------|
| MOTOR1 - INPUT1 | 8   | Motor #1 PWM     |
| MOTOR1 - INPUT2 | 9   | Motor #1 PWM     |
| MOTOR2 - INPUT1 | 10  | Motor #2 PWM     |
| MOTOR2 - INPUT2 | 11  | Motor #2 PWM     |
| VAC             | 12  | Vacuum Control   |

## Organization

### Branches
The `master` [branch](https://github.com/usfsoar/NSL_18-19_Rover/branches)
should only hold the code that is currently in use in the rover. Create new
branches for new features or fixes that aren't immediately implemented. IE:
`feature/led-output` or `fix/startup-crash`. When ready to use a branch's code
in the rover itself, submit a
[pull request](https://github.com/usfsoar/NSL_18-19_Rover/pulls). Don't merge
pull requests until the code is tested in the rover.

### Milestones
There are [milestones](https://github.com/usfsoar/NSL_18-19_Rover/milestones)
for each launch. If you think of a feature or find a problem, first create an
issue, then assign it to a milestone, then create a branch for it if you want to
work on it.

### Releases
At every launch or major test, create a new 
[release](https://github.com/usfsoar/NSL_18-19_Rover/releases). This will allow
us to easily refer back to the code we were using at that event. 
