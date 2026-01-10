#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H
#include <string>
#include <vector>
#include <chrono>
std::vector<std::string> generate_random_words(int num_words, std::vector<std::string> &file_words);
void display_random_words(const std::string &filename, int num_words, std::vector<std::string> &display_words);
bool input_typed_words(int num_words, std::vector<std::string> &inp_words,std::chrono::steady_clock::time_point end_time);
void display_session_summary(const std::vector<std::string> &data, const std::vector<std::string> &incorrect_words);
std::tuple<std::string, std::string> get_difficulty_level();
int get_timer_choice();
int get_num_words();
int get_start_choice();
int get_save_choice();
int get_view_leaderboard_choice();
bool main_session_running(int timer_seconds, std::vector<std::string> &display_words, std::vector<std::string> &inp_words,std::string &filename,int num_words);
void display_leaderboard(std::string difficulty,int top_n);
#endif  // INPUT_OUTPUT_H