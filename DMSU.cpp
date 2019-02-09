/**
 *  @author:
 *  @date: 09-02-2019
 *  @version: 1.0
 */
#include <DMSU.h>

DMSU::DMSU(uint8_t pin){
    _pin = pin;
}

/**
 *  @function: read
 *  @summary: read sensor value from analog pin
 *  @parameters:
 *      unit: unit of the returned distance
 *          [CM]: for centimeter
 *          [MM]: for millimeter
 *          [M]: for meter
 *  @return:
 *      float: distance in the specified unit
 *  @description:
 *      v: voltage
        distance = 0.0070634 * v * v + 0.0259679 * v + 0.0025236;
        The coefficient are obtained from linear regression
 */
float DMSU::read(uint8_t unit = CM){
    float distance = 0;
    delay(50);
    float value = analogRead(_pin);
    value = (VCC * value)/1023;
    // compute inverse of the distance in 1/cm
    distance = 0.0070634 * value * value + 0.0259679 * value + 0.0025236;
    distance = 1/distance;
    if(unit == CM) return distance;
    if(unit == MM) return distance * 10;
    else return (distance * 0.01);
}
