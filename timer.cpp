#include <iostream>
#include <chrono>
#include <thread>

bool start_timer(int duration_seconds) {
    /**
     * @brief Starts a countdown timer for the specified duration.
     * Also prints the remaining time dynamically till the timer ends
     * 
     * @param duration_seconds The total time for the countdown in seconds.
     * @return true if the timer completes without interruption, false if interrupted.
     */

    using namespace std::chrono;
    auto end_time = steady_clock::now() + seconds(duration_seconds);

    while (true) {
        auto now = steady_clock::now();
        if (now >= end_time) break;

        auto remaining = duration_cast<seconds>(end_time - now).count();
        std::cout << "Time remaining: " << remaining << " seconds\r" << std::flush;

        // Sleep until the next 1-second tick to reduce drift and CPU usage
        std::this_thread::sleep_until(now + seconds(1));
    }

    std::cout << "Time remaining: 0 seconds\n";
    return true; // Timer completed
}