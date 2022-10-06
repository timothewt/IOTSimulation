/**
 * @author Timothe Watteau
 * @file Pressure.cpp
 * @date 25/09/2022
 * @brief Pressure sensor
 */
#include "Pressure.hpp"

Pressure::Pressure()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_unit = "kPa";
	this->m_measuresPeriod = 2;
	this->m_minValue = 75; // average pressure in a plane is 54kPa-65kPa
	this->m_maxValue = 83;
	this->m_name = "pressure";
}

