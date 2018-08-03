# Obstacle Avoiding Robot with Ultrasonic Ranging

## Introduction

This repository cointains the Arduino code required to create an obstacle avoiding robot using an ultrasonic sensor. In addition, it also has the ability to wait for an infrared remote to give it the signal to either start or stop. The main motor  is connected to the front axle and drives the front two wheels whereas the rear servo motor is vertical to steer the rear two wheels. This type of configuration (stepper motor in the front and servo motor in the rear controlling steering) allows for very precise maneuvers around potential obstacles.

The ultrasonic sensor that is mounted in the front updates every 1.5 seconds to give accurate distance reading while not overwhelming the Arduino with too much unused data. If object is farther away, the stepper motor slows down waiting for the ultrasonic signal to reach back the sensor, so the default value is 20 cm if it takes more than 1 second. On the infrared remote, I have designated one button for Start/Stop which works at any point throughout the application.


### Known Issues

- Once in a while, the ultrasonic sensor will return garbage values (often caused by irregular reflections) which might momentarily slow down the stepper motor

- Due to there being only one ultrasonic sensor mounted in the front and no feedback circuitry in the stepper motor, while reversing it does not check for obstacles behind and will run into them

- The servo motor reorients itself when the program is starting for the first time and may change the steering of the rear axle
