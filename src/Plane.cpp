/**
 * @author Timothe Watteau
 * @file Plane.cpp
 * @date 25/09/2022
 * @brief Plane class, ecosystem of the simulation
 */

#include "Plane.hpp"
#include "iostream"

Plane::Plane() = default;
Plane::Plane(const Plane& plane) = default;
Plane::~Plane() = default;
Plane& Plane::operator=(const Plane &plane) = default;

void Plane::LaunchSimulation()
{
	std::cout << "__ PLANE SENSORS SIMULATION - IOT ECOSYSTEM __" << std::endl << std::endl;

	this->m_scheduler.LaunchScheduler();
}
