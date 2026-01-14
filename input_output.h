#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H
#include <string>
#include <vector>
#include <chrono>
std::vector<std::string> generate_random_words(int num_words, std::vector<std::string> &file_words);
void display_random_words(const std::string &filename, int num_words, std::vector<std::string> &display_words);
bool input_typed_words(int num_words, std::vector<std::string> &inp_words,const std::chrono::steady_clock::time_point end_time);
void display_session_summary(const struct SessionData &session_data);
std::tuple<std::string, std::string> get_difficulty_level();
int get_timer_choice();
int get_num_words();
int get_start_choice();
int get_save_choice();
int get_view_leaderboard_choice();
struct SessionConfig {
    std::string difficulty;
    std::string filename;
    int timer_seconds;
    int num_words;
};
SessionConfig setup_session_config();
bool run_typing_phase(int timer_seconds,int num_words,const std::string& filename,std::vector<std::string>& display_words,std::vector<std::string>& inp_words
);
bool main_session_running(int timer_seconds, std::vector<std::string> &display_words, std::vector<std::string> &inp_words,const std::string &filename,int num_words);
SessionData process_anaytics(int timer_seconds,const std::string &difficulty,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words,std::vector<std::string> &data,std::vector<std::string> &incorrect_words);
bool save_session_data(const std::vector<std::string> &data,const std::vector<std::string> &incorrect_words,const SessionData &session_data);
void display_leaderboard(const std::string &difficulty,int top_n);
void show_leaderboard(const std::string &difficulty);
#endif  // INPUT_OUTPUT_H