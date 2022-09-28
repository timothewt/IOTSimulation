/**
 * @author Timothe Watteau
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor class, retrieves data from the sensors processes them
 */

#ifndef AP4A_SENSOR_HPP
#define AP4A_SENSOR_HPP

#include "iostream"
#include "cmath"

template<typename T>
class Sensor
{
private:
protected:
	std::string m_unit; // SI unit of the measures
	int m_measuresPeriod; // time in seconds between each measure
	float m_minValue, m_maxValue; // minimum and maximum value generated by the sensor
	std::string m_name; // m_name of the sensor

	/**
	 * @brief Generates random value to simulate the sensor
	 * @param min minimum value
	 * @param max maximum value
	 * @return a random float between min and max
	 */
	T generateRandomValue(float min, float max);
public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Sensor<T>();
	Sensor<T>(const Sensor<T>& sensor);
	~Sensor<T>();
	Sensor<T>& operator=(const Sensor<T>& sensor);

	/**
	 * @brief Retrieves data from the sensor
	 * @return the value of the sensor
	 */
	virtual T getData();
	/**
	 * @brief Gives the measures period which is the interval of time between each measure
	 * @return the measures period
	 */
	int getMeasurePeriod();
	/**
	 * @brief Gets the unit of the measures
	 * @return the string containing the unit of the measure of this sensor
	 */
	std::string getUnit();
	/**
	 * @brief Gets the name of the sensor
	 * @return the name of the sensor
	 */
	std::string getName();
};

/**
 * The template functions have to be defined in the Sensor.hpp (header) file
 */

template<typename T>
Sensor<T>::Sensor()
{
	this->m_unit = "";
	this->m_measuresPeriod = 1;
	this->m_minValue = 0;
	this->m_maxValue = 1;
}

template<typename T> Sensor<T>::Sensor(const Sensor<T>& sensor) = default;
template<typename T> Sensor<T>::~Sensor<T>() = default;
template<typename T> Sensor<T>& Sensor<T>::operator=(const Sensor<T> &sensor) = default;

template<typename T>
T Sensor<T>::generateRandomValue(float min, float max)
{
	return static_cast <float> (std::rand() % static_cast <int>(floor(max - min) * 100)) / 100 + min;
}
template<typename T>
T Sensor<T>::getData()
{
	return this->generateRandomValue(this->m_minValue, this->m_maxValue);
}

template<typename T>
int Sensor<T>::getMeasurePeriod()
{
	return this->m_measuresPeriod;
}

template<typename T>
std::string Sensor<T>::getUnit()
{
	return this->m_unit;
}

template<typename T>
std::string Sensor<T>::getName()
{
	return this->m_name;
}

#endif //AP4A_SENSOR_HPP