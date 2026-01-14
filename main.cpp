#include "input_output.h"
#include "file_handler.h"
#include "analytics.h"
#include "timer.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>


SessionConfig setup_session_config();
bool run_typing_phase(int timer_seconds,int num_words,const std::string& filename,std::vector<std::string>& display_words,std::vector<std::string>& inp_words);
SessionData process_anaytics(int timer_seconds,const std::string &difficulty,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words,std::vector<std::string> &data,std::vector<std::string> &incorrect_words);
bool save_session_data(const std::vector<std::string> &data,const std::vector<std::string> &incorrect_words,const SessionData &session_data);
void show_leaderboard(const std::string &difficulty);

int main(){
    std::cout<<"WELCOME TO SPEED TYPE TESTER\n";
    
    std::vector<std::string> display_words;
    std::vector<std::string> inp_words;
    std::vector<std::string> incorrect_words;
    std::vector<std::string> data;

    SessionConfig cfg = setup_session_config();
    bool executed = run_typing_phase(cfg.timer_seconds,cfg.num_words,cfg.filename,display_words,inp_words);
    if (!executed) return 0;

    SessionData session_data = process_anaytics(cfg.timer_seconds,cfg.difficulty,display_words,inp_words,data,incorrect_words);
    save_session_data(data,incorrect_words,session_data);
    show_leaderboard(cfg.difficulty);
    return 0;    
}
