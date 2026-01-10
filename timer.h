#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>
#include <iostream>
void start_countdown();
void remaining_time(std::chrono::steady_clock::time_point end_time);
#endif // TIMER_H