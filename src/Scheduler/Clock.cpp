/**
 * @author Timothe Watteau
 * @file Clock.cpp
 * @date 25/09/2022
 * @brief Clock class, to time the log of all the sensors values
 */

#include "Clock.hpp"

Clock::Clock() : m_startTime() {};
Clock::Clock(const Clock& clock) = default;
Clock::~Clock() = default;
Clock& Clock::operator=(const Clock &clock) = default;

void Clock::setStartTime() {
	this->m_startTime = clock();
}
long Clock::getTime() const {
	return (clock() - m_startTime) / 1000;
}
