#include "analytics.h"
#include "input_output.h"
#include "file_handler.h"
#include "analytics.h"
#include "timer.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

// Forward declaration
bool input_typed_words(int num_words, std::vector<std::string>& inp_words, std::chrono::steady_clock::time_point end_time);
void display_random_words(const std::string& filename, int num_words, std::vector<std::string> & display_words);
void display_session_summary(const std::vector<std::string> &data, const std::vector<std::string> &incorrect_words);
bool write_analytics_csvfile(const std::string &filename, const std::vector<std::string> &data);
bool write_incorrect_words_txtfile(std::vector<std::string> &incorrect_words, const std::string &filename,struct SessionData &session_data);
std::tuple <std::vector<std::string>, std::vector<std::string>> create_vector_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
std::tuple<std::string, std::string> get_difficulty_level();
int get_timer_choice();
int get_num_words();
int get_start_choice();
int get_save_choice();
int get_view_leaderboard_choice();
bool main_session_running(int timer_seconds, std::vector<std::string> &display_words, std::vector<std::string> &inp_words,std::string &filename,int num_words);
void display_leaderboard(std::string difficulty,int top_n);
void start_countdown();

int main(){
    std::vector<std::string> display_words;
    std::vector<std::string> inp_words;
    std::vector<std::string> incorrect_words;
    std::vector<std::string> data;
    std::string filename;
    int num_words;
    int timer_seconds;
    std::string difficulty;
    int start_choice;
    int save_choice;
    bool execute = false;
    int leaderboard_choice;
    std::cout<<"WELCOME TO SPEED TYPE TESTER\n";
    std::tie(difficulty, filename) = get_difficulty_level();
    timer_seconds = get_timer_choice();
    num_words = get_num_words();

    start_choice = get_start_choice();
    if (start_choice == 1){
        start_countdown();
        execute = main_session_running(timer_seconds,display_words,inp_words,filename,num_words);
    }
    else{
        return 0;
    }   
    if(execute){
        std::cin.ignore(1000, '\n');
        save_choice = get_save_choice();
        if (save_choice == 1){
            SessionData session_data;
            if(write_analytics_csvfile("speed_type_tester_analytics.csv",data) && write_incorrect_words_txtfile(incorrect_words,"speed_type_tester_incorrect_words.txt",session_data))
            {
                std::cout<<"Data Saved Successfully\n";
            }
            else{
                std::cout<<"Couldn't Save Data\n";
            }
        }
        else{
            return 0;
        }
    }
    if (execute){
        leaderboard_choice = get_view_leaderboard_choice();
        if (leaderboard_choice == 1){
            display_leaderboard(difficulty,3);//display the top 3 entries
        }
        else{
            return 0;
        }    
    }
    return 0;    
}
