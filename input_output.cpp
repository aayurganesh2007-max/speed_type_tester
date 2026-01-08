#include "file_handler.h"
#include "input_output.h"
#include "analytics.h"
#include <iostream>
#include <random>
#include <chrono>


std::vector<std::string> generate_random_words(int num_words, std::vector<std::string> &file_words){

    /** Generates a random set of words from a given file.
    args:
        num_words (int): The number of words to generate.
        file_words (std::vector<std::string>): The vector of strings to generate words from.
    returns:
        std::vector<std::string>: A vector of strings containing the generated words.
    */
    std::vector<std::string> per_linewords;
    for (int i = 0; i < num_words && i < file_words.size(); ++i) {
        // Generate a random index to select a word
        std::uniform_int_distribution<> distr(0, file_words.size() - 1);
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

std::vector<std::string> generate_random_words(int num_words, std::vector<std::string> &file_words){

    /** Generates a random set of words from a given file.
    args:
        num_words (int): The number of words to generate.
        file_words (std::vector<std::string>): The vector of strings to generate words from.
    returns:
        std::vector<std::string>: A vector of strings containing the generated words.
    */
    std::vector<std::string> per_linewords;
    for (int i = 0; i < num_words && i < file_words.size(); ++i) {
        // Generate a random index to select a word
        std::uniform_int_distribution<> distr(0, file_words.size() - 1);
        int random = distr(gen);
        per_linewords.push_back(file_words[random]);
    }
    return per_linewords;
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
    std::cout << "net words per minute (WPM): " << session_data.net_wpm << std::endl;
    std::cout << "raw words per minute (WPM): " << session_data.raw_wpm << std::endl;
    std::cout << "net characters per minute (CPM): " << session_data.net_cpm << std::endl;
    std::cout << "raw characters per minute (CPM): " << session_data.raw_cpm << std::endl;
    std::cout << "Word Accuracy (%): " << session_data.accuracy_words << std::endl;
    std::cout << "Character Accuracy (%): " << session_data.accuracy_chars << std::endl;
    for (int i = 0; i < session_data.incorrect_words.size(); ++i) {
        std::cout << session_data.incorrect_words[i] << " ";
        }
} 