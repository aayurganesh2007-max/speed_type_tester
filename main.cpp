#include "analytics.h"
#include "input_output.h"
#include "file_handler.h"
#include "analytics.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

// Forward declaration
void input_typed_words(int num_words, std::vector<std::string>& inp_words, std::chrono::steady_clock::time_point end_time);
void display_random_words(const std::string& filename, int num_words, std::vector<std::string> & display_words);
void display_session_summary(const std::vector<std::string> &data, const std::vector<std::string> &incorrect_words);
bool write_analytics_csvfile(const std::string &filename, const std::vector<std::string> &data);
bool write_incorrect_words_txtfile(std::vector<std::string> &incorrect_words, const std::string &filename);
std::tuple <std::vector<std::string>, std::vector<std::string>> create_vector_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);


int main(){
    std::vector<std::string> display_words;
    std::vector<std::string> inp_words;
    std::vector<std::string> incorrect_words;
    std::vector<std::string> data;
    std::string filename;
    int num_words;
    int timer_seconds;
    int difficulty_choice; 
    string difficulty;
    int timer_choice;  
    int start_choice;
    int save_choice;
    bool execute = false;
    std::cout<<"WELCOME TO SPEED TYPE TESTER\n";
    std::cout<<"Difficulty level\n1.Easy\n2.Medium\n3.Hard\n4.Ultra Hard\nEnter your choice: ";//menu for difficulty level
    std::cin>> difficulty_choice;
    
    switch(difficulty_choice) {
        case 1:
            filename = "easy_words.txt";
            difficulty = "easy";
            break;
        case 2:
            filename = "medium_words.txt";
            difficulty = "medium";
            break;
        case 3:
            filename = "hard_words.txt";
            difficulty = "hard";
            break;
        case 4:
            filename = "ultrahard_words.txt";
            difficulty = "ultra_hard"
            break;
        default:
            std::cout<<"Invalid choice\n";
            return 0;
            break;
    }
    std::cout<<"Timer Setup\n1.15 seconds\n2.30 seconds\n3.60 seconds\n4.90 seconds\n5.120 seconds\nEnter your choice: ";//menu for timer setup
    std::cin >> timer_choice;

    switch(timer_choice) {
        case 1:
            timer_seconds = 15;
            break;
        case 2:
            timer_seconds = 30;
            break;
        case 3:
            timer_seconds = 60;
            break;
        case 4:
            timer_seconds = 90;
            break;
        case 5:
            timer_seconds = 120;
            break;
        default:
            std::cout<<"Invalid choice\n";
            return 0;
            break;
    }

    std::cout<<"Enter the number of words you want ot display per line: ";//menu for number of words per line
    std::cin>> num_words;

    std::cout<<"Start typing now\n1.Yes \n2.No\nEnter your choice: ";//menu for start typing now.
    std::cin>>start_choice;


    
    switch(start_choice) {
        case 1:
        {   
            auto start_time = std::chrono::steady_clock::now();
            auto end_time = start_time + std::chrono::seconds(timer_seconds);
            int round_no = 1;
            while (std::chrono::steady_clock::now() < end_time ){
            // Calculate remaining time and print it every second
            auto current_time = std::chrono::steady_clock::now();
            std::chrono::seconds remaining = std::chrono::duration_cast<std::chrono::seconds>(end_time - current_time);
            std::cout << "\rTime remaining: " << remaining.count() << " seconds" << std::flush; // Print on the same line
            // Sleep for a short duration to prevent busy waiting and control tick rate
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\n--- Round " << round_no << " ---" <<'\n';
            display_random_words(filename,num_words,display_words);
            input_typed_words(num_words,inp_words,end_time);
            if (std::chrono::steady_clock::now() >= end_time) break;
            round_no++;
            }
            std::cout << "\n\n=== TIME IS UP! ===" <<'\n'<<'\n';
            std::tie(data,incorrect_words)=create_vector_data(timer_seconds,display_words,inp_words);
            display_session_summary(data,incorrect_words);
            std::cout<<'\n';
            execute = true;
            break;
        }
        case 2:
            return 0;
            break;
        default:
            std::cout<<"Invalid choice\n";
            return 0;
            break;
    }
    
    if(execute){
        std::cin.ignore(1000, '\n');
        std::cout<<"Save Data\n1.Yes \n2.No\nEnter your choice:";
        std::cin>>save_choice;
        switch(save_choice){
            case 1: {
                // Removed the semicolon from the end of this line
                if(write_analytics_csvfile("speed_type_tester_analytics.csv",data) && write_incorrect_words_txtfile(incorrect_words,"speed_type_tester_incorrect_words.txt"))
                {
                    std::cout<<"Data Saved Successfully\n";
                }
                else{
                    std::cout<<"Couldn't Save Data\n";
                }
                break; // Break belongs here to end case 1
            }
            case 2:
                return 0;
                break;
            default:
                std::cout<<"Invalid choice\n";
                return 0;
                break;
        }
    }

    return 0;
    
}
 
    

     
    
 
    

     
    