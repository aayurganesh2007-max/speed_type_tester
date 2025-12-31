#include "file_handler.h"
#include "input_output.h"
#include "analytics.h"
#include <iostream>
#include <random>
#include <chrono>
void display_random_words(const std::string &filename, int num_words, std::vector<std::string> &display_words)
/**
 * @brief Displays a specified number of random words in same line from a given file randomnly.
 *
 * @param filename The name of the file containing the words.
 * @param num_words The number of random words to display.
 * @return void
 */
 {  std::vector<std::string> words;
    bool success= false;

    std::tie(success, words) = read_words_from_file(filename);
    if (!success) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < num_words && i < words.size(); ++i) {
        // Generate a random index to select a word
        std::uniform_int_distribution<> distr(0, words.size() - 1);
        int random = distr(gen);
        display_words.push_back(words[random]);
        std::cout << words[random] << " ";
    }
    std::cout<<'\n';
}

void input_typed_words(int num_words, std::vector<std::string> &inp_words,std::chrono::steady_clock::time_point end_time)
/**
 * @brief Takes a specified number of words as input , and takes so many words in one line and then stores each word one by one into the vector.
 *
 * @param num_words The number of words to input.
 * @param inp_words A reference to a vector where the input words will be stored.
 * @param end_time The end time of the typing session.
 * @return void
 */
{
    std::string word;
    int i = 0;
    while (i<num_words && std::chrono::steady_clock::now() < end_time) {
        std::cin >> word;
        inp_words.push_back(word);
        i++;
    }
    std::cout<<'\n';
}

void display_session_summary(const std::vector<std::string> &data, const std::vector<std::string> &incorrect_words)
/**
 * @brief Displays a summary of the typing session based on the provided data.
 *
 * @param data A vector of strings containing the session data.
 * @param incorrect_words_list A vector of strings containing the incorrectly typed words.
 * @return void
 */
{
    if (data.size() <6) {
        std::cerr << "Error: Insufficient data to display session summary." << std::endl;
        return;
    }
    std::cout << "Session Summary:" << std::endl;
    std::cout << "Date and Time: " << data[0] << std::endl;
    std::cout << "Time Taken (seconds): " << data[1] << std::endl;
    std::cout << "Words Per Minute (WPM): " << data[2] << std::endl;
    std::cout << "Characters Per Minute (CPM): " << data[3] << std::endl;
    std::cout << "Word Accuracy (%): " << data[4] << std::endl;
    std::cout << "Character Accuracy (%): " << data[5] << std::endl;
    for (int i = 0; i < incorrect_words.size(); ++i) {
        std::cout << incorrect_words[i] << " ";
    }   
} 