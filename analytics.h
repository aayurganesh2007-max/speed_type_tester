#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <string>
#include <vector>
#include <tuple>

int words_per_minute(int timer_seconds,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
int chars_per_minute(int timer_seconds, const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::tuple<std::vector<std::string>, std::vector<std::string>> correct_words_check(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::tuple<int, int> correct_chars_check(const std::vector<std::string> & display_words,const std::vector<std::string> &inp_words);
int accuracy_words(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words);
std::vector<std::string> incorrect_words_list(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
int accuracy_chars(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
std::tuple<std::vector<std::string>, std::vector<std::string>> create_vector_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words);
#endif // ANALYTICS_H