/**
 * @author Timothe Watteau
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server class, receives and store data coming from the sensors
 */

#ifndef AP4A_SERVER_HPP
#define AP4A_SERVER_HPP

#include "iostream"
#include "fstream"
#include "Package.hpp"

class Server
{
private:
	bool m_consoleActivation; // indicates if the server will display the sensor values in the console
	bool m_logActivation; // indicates if the server will log the sensor values in the log files

	/**
	 * @brief Writes all the sensors values in the console
	 * @param measures measured values of the 0: temperature, 1: humidity, 2: light, 3: pressure
	 * @param units units of the measures values
	 * @param time time of the measures
	 */
	void consoleWrite(float measures[4], std::string units[4], long time);
	/**
	 * @brief Writes all the sensors measures in the main log file
	 * @param measures values of the 0: temperature, 1: humidity, 2: light, 3: pressure
	 * @param units units of the measures values
	 * @param time time of the measures
	 */
	void fileWrite(float measures[4], std::string units[4], long time);
	/**
	 * @brief Writes a measure from one sensor in the console
	 * @tparam T type of return of the sensor
	 * @param sensor type of sensor (temperature, humidity, light, pressure)
	 * @param unit unit of the measure
	 * @param measures measured value
	 * @param time time of the measure
	 */
	template<typename T>
	void consoleWrite(const std::string& sensor, T measure, const std::string& unit, long time);
	/**
	 * @brief Writes the measure of one sensor in the corresponding log file
	 * @tparam T type of return of the sensor
	 * @param sensor type of sensor (temperature, humidity, light, pressure)
	 * @param unit unit of the measure
	 * @param measure measured value
	 * @param time time of the measure
	 */
	template<typename T>
	void fileWrite(const std::string& sensor, T value, const std::string& unit, long time);

public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Server();
	Server(const Server& server);
	~Server();
	Server& operator=(const Server& server);

	/**
	 * @brief Receives data from the sensors
	 * @param measures measures of the sensors
	 * @param units units of the measures values
	 * @param time time of the measures
	 */
	void DataReceive(float measures[4], std::string units[4], long time);
	/**
	 * @brief Receives data from a single sensor
	 * @tparam T type of return of the sensor
	 * @param dataPackage package containing the sensor's name, the data and the unit of the data
	 * @param time time of the measure
	 */
	template<typename T>
	void DataReceive(Package<T> dataPackage, long time);

	/**
	 * @brief Toggles the console log to true or false
	 */
	void toggleConsoleLog();
	/**
	 * @brief Toggles the files log to true or false
	 */
	void toggleFileLog();
};

// Template functions have to be declared in the header of the class

template<typename T>
void Server::consoleWrite(const std::string& sensor, T measure, const std::string& unit, long time)
{
	std::cout << time << "s | " << sensor << " : " << measure << unit << std::endl;
}

template<typename T>
void Server::fileWrite(const std::string& sensor, T value, const std::string& unit, long time)
{
	std::ofstream logFile("logs/" + sensor + "Log.csv", std::fstream::app); // opens the corresponding log file
	logFile << time << "s," << value << "," << unit << "," << std::endl; // writes in the file
	logFile.close();
}

template<typename T>
void Server::DataReceive(Package<T> dataPackage, long time)
{
	if (m_consoleActivation)
	{
		consoleWrite(dataPackage.getName(), dataPackage.getData(), dataPackage.getUnit(), time);
	}
	if (m_logActivation)
	{
		fileWrite(dataPackage.getName(), dataPackage.getData(), dataPackage.getUnit(), time);
	}
}

#endif //AP4A_SERVER_HPP
