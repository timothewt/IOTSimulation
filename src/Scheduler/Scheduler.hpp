/**
 * @author Timothe Watteau
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the server in order to
 * store and display them
 */

#ifndef AP4A_SCHEDULER_HPP
#define AP4A_SCHEDULER_HPP

#include "ctime"
#include "chrono"
#include "thread"
#include "Clock.hpp"
#include "../Server/Server.hpp"
#include "../Sensors/Temperature.hpp"
#include "../Sensors/Humidity.hpp"
#include "../Sensors/Light.hpp"
#include "../Sensors/Pressure.hpp"

class Scheduler
{
private:
	Clock m_clock; // Clock object to time the measures
	Server m_server; // Server to store and display the measures
	Temperature m_temperatureSensor; // Temperature sensor
	Humidity m_humiditySensor; // Humidity sensor
	Light m_lightSensor; // Light sensor
	Pressure m_pressureSensor; // Pressure sensor
	float m_measures[4] = {0, 0, 0, 0}; // Measures of the sensors
	std::string m_units[4] = {m_temperatureSensor.getUnit(), m_humiditySensor.getUnit(), m_lightSensor.getUnit(), m_pressureSensor.getUnit()}; // units of the sensors

public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Scheduler();
	Scheduler(const Scheduler& scheduler);
	~Scheduler();
	Scheduler& operator=(const Scheduler& scheduler);

	/**
	 * @brief Starts the schedule, therefore the simulation
	 */
	void LaunchScheduler();
	/**
	 * @brief Asks the user if he wants to enable or disable the file and console log of the sensors
	 */
	void askUserForOutput();
	/**
	 * @brief Asks the user for the simulation duration
	 * @return The time that the simulation lasts in seconds
	 */
	long askUserForSimulationTime();
	/**
	 * @brief Retrieves all data of the sensors into the m_measures attribute, used if all the data is of the same type (even though float can contain booleans and int)
	 */
	void RetrieveAllData();
	/**
	 * @brief Sends the data of a sensor to the server periodically until the end of the simulation. There is a thread per sensor.
	 * @tparam T type of return of the sensor
	 * @param sensor sensor from which we log the data
	 * @param simDuration duration of the simulation
	 */
	template<typename T>
	void startSensorTransmission(Sensor<T> sensor, long simDuration);
	/**
	 * @brief Puts the thread to sleep for t milliseconds
	 * @param t time to sleep in milliseconds
	 */
	void sleepForMs(long t) const;
};

template<typename T>
void Scheduler::startSensorTransmission(Sensor<T> sensor, long simDuration)
{
	while(m_clock.getTime() <= simDuration) // Loops until the simulation duration is over
	{
		m_server.DataReceive(sensor.getName(), sensor.getUnit(), sensor.getData(), m_clock.getTime()); // sends the data to the server
		std::this_thread::sleep_for(std::chrono::seconds(sensor.getMeasurePeriod())); // Puts the thread to sleep until the next measure
	}
}

#endif //AP4A_SCHEDULER_HPP
