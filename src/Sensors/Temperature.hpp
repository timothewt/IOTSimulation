/**
 * @author Timothe Watteau
 * @file Temperature.hpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */

#ifndef AP4A_TEMPERATURE_HPP
#define AP4A_TEMPERATURE_HPP

#include "Sensor.hpp"
#include "Sensor.cpp"

class Temperature : public Sensor<float>
{
public:
	/**
	 * @brief Default constructor
	 */
	Temperature();
};

#endif //AP4A_TEMPERATURE_HPP