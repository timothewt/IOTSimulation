/**
 * @author Timothe Watteau
 * @file Package.cpp
 * @date 05/10/2022
 * @brief Package used to send data from the scheduler to the server
 */

#ifndef AP4A_PACKAGE_HPP
#define AP4A_PACKAGE_HPP

#include "iostream"

template<typename T>
class Package {
private:
	std::string sensorName;
	T sensorData;
	std::string sensorUnit;
public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Package<T>();
	Package<T>(const Package<T>& package);
	Package<T>(const std::string& sensorName, T sensorData, const std::string& sensorUnit);
	~Package<T>();
	Package<T>& operator=(Package<T> package);
	/**
	 * Getters for the sensor's name, the sensor's data and the sensor's unit
	 */
	std::string getName();
	T getData();
	std::string getUnit();
};


template<typename T> Package<T>::Package() = default;
template<typename T> Package<T>::Package(const Package<T>& package) = default;
template<typename T> Package<T>::Package(const std::string& sensorName, T sensorData, const std::string& sensorUnit) {
	this->sensorName = sensorName;
	this->sensorData = sensorData;
	this->sensorUnit = sensorUnit;
}
template<typename T> Package<T>::~Package() = default;

template<typename T>
std::string Package<T>::getName() {
	return this->sensorName;
}
template<typename T>
T Package<T>::getData() {
	return this->sensorData;
}
template<typename T>
std::string Package<T>::getUnit() {
	return this->sensorUnit;
}

#endif //AP4A_PACKAGE_HPP
