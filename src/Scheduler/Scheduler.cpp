/**
 * @author Timothe Watteau
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the sensors and the server
 * in order to store and display them.
 */

#include "chrono"
#include "thread"
#include "Scheduler.hpp"

Scheduler::Scheduler() = default;
Scheduler::Scheduler(const Scheduler& scheduler) = default;
Scheduler::~Scheduler() = default;
Scheduler& Scheduler::operator=(const Scheduler &scheduler) = default;

void Scheduler::LaunchScheduler()
{
	askUserForOutput();

	long simDuration = askUserForSimulationTime();

	std::cout << "Starting the simulation ..." << std::endl;

	m_clock.setStartTime();

	// The program uses a thread per sensor, therefore it just has to put to sleep one thread between each measure for each sensor
	std::thread threads[4];
	threads[0] = std::thread(&Scheduler::startSensorTransmission<float>, this, &m_temperatureSensor, simDuration);
	sleepForMs(100);	// Adding delay between threads, otherwise the console prints intertwine
	threads[1] = std::thread(&Scheduler::startSensorTransmission<float>, this, &m_humiditySensor, simDuration);
	sleepForMs(100);
	threads[2] = std::thread(&Scheduler::startSensorTransmission<bool>, this, &m_lightSensor, simDuration);
	sleepForMs(100);
	threads[3] = std::thread(&Scheduler::startSensorTransmission<int>, this, &m_pressureSensor, simDuration);

	for (int i = 0; i < 4; ++i) {
		threads[i].join();
	}
}

void Scheduler::sleepForMs(long t) const
{
	std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void Scheduler::askUserForOutput()
{
	char consoleActivation;
	char logsActivation;
	std::cout << "Do you want to activate the console write ? [Y/N] :" << std::endl;
	std::cin >> consoleActivation;
	std::cout << "Do you want to activate the log write ? [Y/N] :" << std::endl;
	std::cin >> logsActivation;

	if (consoleActivation != 'Y' and consoleActivation != 'y') // if the user says no
	{
		m_server.toggleConsoleLog(); // toggles to false, console log is set to true by default
	}
	if (logsActivation != 'Y' and logsActivation != 'y') // if the user says no
	{
		m_server.toggleFileLog(); // toggles to false, file log is set to true by default
	}
}

long Scheduler::askUserForSimulationTime()
{
	long simDuration = 0;
	std::cout << "How much time (in seconds) do you want the simulation to last ? (type a negative value for an indefinite time) :" << std::endl;
	std::cin >> simDuration;
	if (simDuration < 0)
	{
		simDuration = 2147483647;
	}
	return simDuration;
}

void Scheduler::RetrieveAllData()
{
	m_measures[0] = m_temperatureSensor.getData();
	m_measures[1] = m_humiditySensor.getData();
	m_measures[2] = static_cast<float>(m_lightSensor.getData());
	m_measures[3] = static_cast<float>(m_pressureSensor.getData());
}
