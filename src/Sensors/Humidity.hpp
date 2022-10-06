/**
 * @author Timothe Watteau
 * @file Humidity.hpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */

#ifndef AP4A_HUMIDITY_HPP
#define AP4A_HUMIDITY_HPP

#include "Sensor.hpp"
#include "Sensor.cpp"

class Humidity : public Sensor<float>
{
public:
	/**
	 * @brief Default constructor
	 */
	Humidity();
	/**
	 * generates a random float with one decimal between min and max
	 * @param min minimum value
	 * @param max maximum value
	 * @return a random float in [min, max]
	 */
	float generateRandomValue(float min, float max) override
	{
		return static_cast<float> (std::rand() % static_cast <int>(floor(max - min) * 10)) / 10 + min;
	}
};

#endif //AP4A_HUMIDITY_HPP