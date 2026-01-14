#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
void start_countdown();
void remaining_time(const std::chrono::steady_clock::time_point end_time);
std::string get_date_time();
#endif // TIMER_H