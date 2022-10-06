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
public:
	/**
	 * @brief Default constructor
	 */
	Light();
	/**
	 * generates a random boolean
	 * @param min minimum value
	 * @param max maximum value
	 * @return a random boolean, true or false
	 */
	bool generateRandomValue(bool min, bool max) override
	{
		return std::rand() % 2;
	}
};

#endif //AP4A_LIGHT_HPP