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
    std::cout<<"Typing session will start in: ";
    for (int i=3; i>=0; i--){
        std::cout << i <<std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        //Use carriage return to move the cursor back to the beginning of the line
        // and overwrite the previous number with spaces to clear it, then flush the output.
        std::cout<< "\r";
    }
    std::cout<<"\nStarting typing now\n";
}


void remaining_time(std::chrono::steady_clock::time_point end_time){
    /**
     * @brief Calculates the remaining time for the typing session, and displays it on the screen
     * @param end_time The end time of the typing session.
     * @return the remaining time in seconds
     */
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::seconds remaining = std::chrono::duration_cast<std::chrono::seconds>(end_time - current_time);
    std::cout << "\rTime remaining: " << remaining.count() << " seconds" << std::flush; // Print on the same line
    // Sleep for a short duration to prevent busy waiting and control tick rate
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
}