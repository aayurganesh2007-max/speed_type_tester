#include "timer.h"
#include <chrono>
#include <thread>
#include <iostream>

void start_countdown(){
    /**
     * @brief Starts the countdown timer for the user before starting the typing session.
     * @param none
     * @return none
     */
    std::cout<<"Typing session will start in: \n";
    for (int i=3; i>0; i--){
        std::cout << i <<"...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<"\nStarting typing now\n";
}


void remaining_time(const std::chrono::steady_clock::time_point end_time){
    /**
     * @brief Calculates the remaining time for the typing session, and displays it on the screen
     * @param end_time The end time of the typing session.
     * @return the remaining time in seconds
     */
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::seconds remaining = std::chrono::duration_cast<std::chrono::seconds>(end_time - current_time);
    std::cout << "\nTime remaining: " << remaining.count() << " seconds"; // Print on the same line
    // Sleep for a short duration to prevent busy waiting and control tick rate
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

std::string get_date_time(){
    /**
     * @brief Returns the current date and time in the format "YYYY-MM-DD HH:MM:SS"
     * @param none
     * @return the current date and time in the format "YYYY-MM-DD HH:MM:SS"
     */
    
    auto now = std::chrono::system_clock::now();
    auto current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* time = std::localtime(&current_time);
    std::ostringstream oss;
    oss << std::put_time(time, "%Y-%m-%d %H:%M:%S");
    std::string time_str = oss.str();
    return time_str;
}