/**
 * @author Timothe Watteau
 * @file Temperature.cpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */
#include "Temperature.hpp"

Temperature::Temperature()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_unit = "\370C";
	this->m_measuresPeriod = 1;
	this->m_minValue = 20; // airplanes temperature is maintained around 22°C
	this->m_maxValue = 25;
	this->m_name = "temperature";
}
