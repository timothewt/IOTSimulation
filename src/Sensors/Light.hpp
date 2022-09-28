/**
 * @author Timothe Watteau
 * @file Light.hpp
 * @date 25/09/2022
 * @brief Light sensor
 */

#ifndef AP4A_LIGHT_HPP
#define AP4A_LIGHT_HPP

#include "Sensor.hpp"
#include "Sensor.cpp"

class Light : public Sensor<bool>
{
private:
	/**
	 * @brief Generates a random boolean (true or false), overwrites the method of the Sensor class to return a boolean
	 */
	bool generateRandomValue();
public:
	/**
	 * @brief Default constructor
	 */
	Light();

	/**
	 * @brief Retrieves data from the sensor, overwrites the method of the Sensor class to return a boolean
	 * @return the value of the sensor
	 */
	bool getData();
};

#endif //AP4A_LIGHT_HPP