#ifndef HCSR04_H
#define HCSR04_H

#include "Arduino.h"

/**
 * Find the Github repository at {@link https://github.com/Martinsos/arduino-lib-hc-sr04}
 * \brief   HCSR04 - Library for arduino, for HC-SR04 ultrasonic distance sensor.
 * @author Martin Sosic
 * @version 2.0.0, 06/11/2016
 */
class UltraSonicDistanceSensor {
 public:
    /**
     * @param triggerPin  Digital pin that is used for controlling sensor (output).
     * @param echoPin  Digital pin that is used to get information from sensor (input).
     * @param maxDistanceCm  Maximum distance sensor can measure, defaults to 4m for HC-SR04.
     *                       You might want to set this value if you are using different sensor than HC-SR04
     *                       or if you don't care about distances larger than whatever you will set it to
     *                       (therefore reducing time it takes for a single measurement).
     * @param maxTimeoutMicroSec  Single measurement will never take longer than whatever value you provide here.
     *   You might want to do this in order to ensure your program is never blocked for longer than some specific time,
     *   since measurements are blocking.
     *   By default, there is no limit on time (only on distance). By defining timeout, you are again limiting the distance. 
     */
    UltraSonicDistanceSensor(byte triggerPin, byte echoPin, unsigned short maxDistanceCm = 400, unsigned long maxTimeoutMicroSec = 0);

    /**
     * Configures the hardware for the sensor on the microcontroller.  Call this method within `setup()`.
     */
    void begin() const;

    /**
     * Measures distance by sending ultrasonic waves and measuring time it takes them
     * to return.
     * @returns Distance in centimeters, or negative value if distance is greater than 400cm.
     */
    float measureDistanceCm();

    /**
     * Measures distance by sending ultrasonic waves and measuring time it takes them
     * to return. Measurement can not exceed duration calculated with maxDistanceCm or maxTimeoutMicroSec.
     * @param temperature  Temperature in degrees celsius
     * @returns Distance in centimeters, or negative value if distance is greater than 400cm.
     */
    float measureDistanceCm(float temperature);
 private:
    byte triggerPin, echoPin;
    unsigned short maxDistanceCm;
    unsigned long maxTimeoutMicroSec;
};

#endif // HCSR04_H