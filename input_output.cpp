#include "file_handler.h"
#include "timer.h"
#include "input_output.h"
#include "analytics.h"
#include <iostream>
#include <random>
#include <tuple>

std::vector<std::string> generate_random_words(int num_words, std::vector<std::string> &file_words){

    /** Generates a random set of words from a given file.
    args:
        num_words (int): The number of words to generate.
        file_words (std::vector<std::string>): The vector of strings to generate words from.
    returns:
        std::vector<std::string>: A vector of strings containing the generated words.
    */
    std::vector<std::string> per_linewords;
    std::mt19937 gen(std::random_device{}());
    for (int i = 0; i < num_words && i < file_words.size(); ++i) {
        // Generate a random index to select a word
        std::uniform_int_distribution<> distr(0, static_cast<int>(file_words.size()) - 1);   
        int random = distr(gen);
        per_linewords.push_back(file_words[random]);
    }
    return per_linewords;
}
void display_random_words(const std::string &filename, int num_words, std::vector<std::string> &display_words)
/**
 * @brief Displays a specified number of random words in same line from a given file randomnly.
 *
 * @param filename The name of the file containing the words.
 * @param num_words The number of random words to display.
 * @return void
 */
 {  std::vector<std::string> file_words;
    bool success= false;

    std::tie(success,file_words) = read_words_from_file(filename);
    if (!success) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::vector<std::string> per_linewords = generate_random_words(num_words, file_words);
    for (int i = 0; i < per_linewords.size(); ++i) {
        display_words.push_back(per_linewords[i]);
        std::cout << per_linewords[i] << " ";
    }
    std::cout<<'\n';
}

bool input_typed_words(int num_words, std::vector<std::string> &inp_words,std::chrono::steady_clock::time_point end_time)
/**
 * @brief Takes a specified number of words as input , and takes so many words in one line and then stores each word one by one into the vector.
 * at any point if the time is up or the user enters an empty word, the function returns false
 * otherwise it returns true
 * @param num_words The number of words to input.
 * @param inp_words A reference to a vector where the input words will be stored.
 * @param end_time The end time of the typing session.
 * @return bool
 */
{
    for (int i = 0; i < num_words; ++i) {
        std::string word;
        std::cin >> word;  // blocking

        if (std::chrono::steady_clock::now() >= end_time) {
            return false;  // stop accepting further words
        }

        inp_words.push_back(word);
    }
    return true;
}

void display_session_summary(struct SessionData &session_data)
/**
 * @brief Displays a summary of the typing session based on the provided data.
 *
 * @param session_data A struct containing the session data.
 * @return void
 */
{ 
    std::cout << "Session Summary:" << std::endl; 
    std::cout << "Date and Time: " << session_data.start_data_time << std::endl;
    std::cout << "Time Taken (seconds): " << session_data.timestamp << std::endl;
    std::cout << "Difficulty Level: " << session_data.difficulty_level << std::endl;
    std::cout << "raw words per minute (WPM): " << session_data.raw_wpm << std::endl;
    std::cout << "net words per minute (WPM): " << session_data.net_wpm << std::endl;
    std::cout << "raw characters per minute (CPM): " << session_data.raw_cpm << std::endl;
    std::cout << "net characters per minute (CPM): " << session_data.net_cpm << std::endl;
    std::cout << "Word Accuracy (%): " << session_data.accuracy_words << std::endl;
    std::cout << "Character Accuracy (%): " << session_data.accuracy_chars << std::endl;
    std::cout << "Incorrect words : ";
    for (int i = 0; i < session_data.incorrect_words.size(); ++i) {
        std::cout << session_data.incorrect_words[i] << " ";
        }
    std::cout<<"\n";
}

std::tuple<std::string, std::string> get_difficulty_level() {
    /**
     * @brief Takes input from user as long as the input is valid and returns a tuple of difficulty choice and filename
     * @param none
     * @return std::tuple<std::string, std::string>
     */
    while (true) {
        std::cout
            << "Difficulty level\n"
            << "1. Easy\n"
            << "2. Medium\n"
            << "3. Hard\n"
            << "4. Ultra Hard\n"
            << "Enter your choice: ";

        std::string difficulty_choice;
        std::cin >> difficulty_choice;

        try {
            int choice = std::stoi(difficulty_choice);

            switch (choice) {
                case 1:
                    return {"easy", "easy_words.txt"};
                case 2:
                    return {"medium", "medium_words.txt"};
                case 3:
                    return {"hard", "hard_words.txt"};
                case 4:
                    return {"ultra_hard", "ultrahard_words.txt"};
                default:
                    std::cout << "Invalid choice. Try again.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}

int get_timer_choice() {
    /**
     * @brief Takes input from user as long as the input is valid and returns int of timer choice
     * @param none
     * @return int
     */
    while (true) {
        std::cout
            << "Timer Setup\n"
            << "1. 15 seconds\n"
            << "2. 30 seconds\n"
            << "3. 60 seconds\n"
            << "4. 90 seconds\n"
            << "5. 120 seconds\n"
            << "Enter your choice: ";
        std::string timer_choice;
        std::cin >> timer_choice;
        try {
            int choice = std::stoi(timer_choice);
            switch (choice) {
                case 1:
                    return 15;
                case 2:
                    return 30;
                case 3:
                    return 60;
                case 4:
                    return 90;
                case 5:
                    return 120;
                default:
                    std::cout << "Invalid choice. Try again.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}

int get_num_words() {
    /**
     * @brief Takes input from user as long as the input is valid and returns a int of num_words
     * @param none
     * @return int
     */
    while (true) {
        std::cout<<"Enter the number of words you want to display per line: ";
        std::string num;
        std::cin>> num;
        try {
            int num_words = std::stoi(num);
            if (num_words > 0) {
                return num_words;
            }
            else {
                std::cout << "Number must be greater than 0.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}   

int get_start_choice(){
    /**
     * @brief Takes input from user as long as the input is valid and returns int of timer choice
     * @param none
     * @return int
     */
    while (true) {
        std::cout
            << "Start typing now\n1.Yes \n2.No\nEnter your choice: ";
        std::string start_choice;
        std::cin >> start_choice;
        try {
            int choice = std::stoi(start_choice);
            switch (choice) {
                case 1:
                    return 1;
                case 2:
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}

int get_save_choice(){
        /**
     * @brief Takes input from user as long as the input is valid and returns int of timer choice
     * @param none
     * @return int
     */
    while (true) {
        std::cout
            << "Save Data\n1.Yes \n2.No\nEnter your choice: ";
        std::string save_choice;
        std::cin >> save_choice;
        try {
            int choice = std::stoi(save_choice);
            switch (choice) {
                case 1:
                    return 1;
                case 2:
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}

int get_view_leaderboard_choice(){
    /**
     * @brief Takes input from user as long as the input is valid and returns int of timer choice
     * @param none
     * @return int
     */
    while (true) {
        std::cout
            << "View Leaderboard\n1.Yes \n2.No\nEnter your choice: ";
        std::string view_leaderboard_choice;
        std::cin >> view_leaderboard_choice;
        try {
            int choice = std::stoi(view_leaderboard_choice);
            switch (choice) {
                case 1:
                    return 1;
                case 2:
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again.\n\n";
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Please enter a number.\n\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Number out of range.\n\n";
        }
    }
}

bool main_session_running(int timer_seconds, std::vector<std::string> &display_words, std::vector<std::string> &inp_words,std::string &filename,int num_words){
    /**
     * @brief Integrates all the functions, basically calls the display_random_words function and the input_typed_words function as long as the timer is not up
     * also diplays the remaining time while typing
     * @param none
     * @return a boolean value if it has runned successfully or not
     */
    int round_no = 1;
    bool running = true;
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(timer_seconds);
    while (std::chrono::steady_clock::now() < end_time ){
        remaining_time(end_time);
        std::cout<<"\n--- Round " << round_no << " ---" <<'\n';
        display_random_words(filename,num_words,display_words);
        running = input_typed_words(num_words,inp_words,end_time);
        if (!running) break;
        round_no++;
    }
    return true;
}

void display_leaderboard(std::string difficulty,int top_n){
    /**
     * @brief Displays the leaderboard based on the difficulty level
     * @param difficulty The difficulty level of the session
     * @return none
     */
    std::vector<LeaderboardEntry> entries = read_leaderboard_from_file("speed_type_tester_analytics.csv",difficulty);
    if (entries.empty()) {
        std::cout << "No entries found.\n";
        return;
    }
    std::cout << "\nLeaderboard\n";
    std::cout << "Date and Time,Difficulty,Net WPM,Accuracy\n";
    for (int i = 0; i < top_n && i < entries.size(); ++i) {
        std::cout << entries[i].date_time << "," << entries[i].difficulty << "," << entries[i].net_wpm << "," << entries[i].accuracy_words << "\n";
    }
}   

