/**
 * @author Timothe Watteau
 * @file Light.cpp
 * @date 25/09/2022
 * @brief Light sensor
 */
#include "Light.hpp"

Light::Light()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_unit = "";
	this->m_measuresPeriod = 2;
	this->m_minValue = 0;
	this->m_maxValue = 2;
	this->m_name = "light";
}
