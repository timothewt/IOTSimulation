/**
 * @author Timothe Watteau
 * @file Humidity.cpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */
#include "Humidity.hpp"

Humidity::Humidity()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_unit = "%";
	this->m_measuresPeriod = 3;
	this->m_minValue = 10; // average humidity in a plane is 10%-20%
	this->m_maxValue = 20;
	this->m_name = "humidity";
}