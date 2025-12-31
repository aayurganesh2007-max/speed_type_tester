#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H
#include <string>
#include <vector>
#include <chrono>

void display_random_words(const std::string &filename, int num_words, std::vector<std::string> &display_words);
void input_typed_words(int num_words, std::vector<std::string> &inp_words,std::chrono::steady_clock::time_point end_time);
void display_session_summary(const std::vector<std::string> &data, const std::vector<std::string> &incorrect_words);
#endif  // INPUT_OUTPUT_H