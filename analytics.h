#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <string>
#include <vector>
#include <tuple>

int net_words_per_minute(int timer_seconds,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
int raw_words_per_minute(int timer_seconds,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
int net_chars_per_minute(int timer_seconds, const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
int raw_chars_per_minute(int timer_seconds, const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::tuple<std::vector<std::string>, std::vector<std::string>> correct_words_check(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::tuple<int, int> correct_chars_check(const std::vector<std::string> & display_words,const std::vector<std::string> &inp_words);
int accuracy_words(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::vector<std::string> incorrect_words_list(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
int accuracy_chars(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
struct SessionData {
    std::string start_data_time;
    int timestamp;
    std::string difficulty_level;
    int raw_wpm;
    int net_wpm;
    int raw_cpm;
    int net_cpm;
    int accuracy_words;
    int accuracy_chars;
    std::vector<std::string> incorrect_words;
};
void create_session_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words, std::string difficulty, struct SessionData &session_data);
std::tuple <std::vector<std::string>, std::vector<std::string>> create_vector_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words, std::string difficulty);
#endif // ANALYTICS_H