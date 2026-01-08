#include "file_handler.h"
#include <fstream>
#include <cctype>
#include <chrono>
#include <ctime>
std::tuple<bool, std::vector<std::string>> read_words_from_file(const std::string &filename){
    /**
     * @brief Reads all the words from a file at once and stores them in a vector.
     * 
     * @param filename The name of the file to read from.
     * @return A tuple containing a boolean indicating success or failure, and a vector of strings containing the words.
     * If the file is opened successfully, returns true and the vector of words.
     * If the file cannot be opened, returns false and an empty vector.
     */
    std::ifstream file(filename);
    std::vector<std::string> words;
    if (!file.is_open()) {
        return std::make_tuple(false, words);
    }
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return std::make_tuple(true, words);
}

bool write_analytics_csvfile(const std::string &filename, const std::vector<std::string> &data) {
    /**
     * @brief first reads the file, if the file doesnt not exist it creates a file 
     * Then checks if the header date_time,timestamp, difficulty_level,net_wpm, raw_wpm,net_cpm_raw_cpm,accuracy_words,accuracy_chars, already exists in the file
     * then it writes onto the file
     * By updating the file every time it is called keeping the original data intact.
     * it writes the each row of data in a new line, under respective headers.
     * 
     * @param filename The name of the file to write to.
     * @param data The vector of strings to write to the file (only row in one call).
     * @return true if the file is written successfully, false otherwise.
     */

    std::ifstream infile(filename);
    bool file_exists = infile.good();// Check if file exists returns true if file is open
    bool header_exists = false;
    if (!file_exists) {
        // If file doesn't exist, create it
        std::ofstream create_file(filename);
        create_file.close();
    }
    else{
        // first check if the file is empty
        infile.seekg(0, std::ios::end);
        if (infile.tellg() == 0) {
            header_exists = false;
            infile.close(); // File is empty
        }
        else{
            infile.seekg(0, std::ios::beg); // Reset to beginning of file
            std::string header;
            std::getline(infile, header);
            //check if the getline worked fine before comparing
            if (header == "date_time,timestamp,difficulty_level,net_wpm,raw_wpm,net_cpm,raw_cpm,accuracy_words,accuracy_chars") {
                header_exists = true;
            }
        }
        
    }
    infile.close();

    std::ofstream outfile(filename, std::ios::app);
    if (!outfile.is_open()) {
        return false;
    }
    if (!header_exists) {
        outfile << "date_time,timestamp,difficulty_level,net_wpm,raw_wpm,net_cpm,raw_cpm,accuracy_words,accuracy_chars\n";
    }
    for (size_t i = 0; i < data.size(); ++i) {
        outfile << data[i];
        if (i != data.size() - 1) {
            outfile << ",";
        }
    }
    outfile << "\n";
    outfile.close();
    return true;
}

bool write_incorrect_words_txtfile(std::vector<std::string> &incorrect_words, const std::string &filename, struct SessionData &session_data) {
    /**
     * @brief Writes the incorrect words to a text file with date and time 
     * In each row it consists of teh date time followed by all the incorrect words of a particular session
     * if the file never existed it creates a new file. or else appends the new data with the existing data
     * 
     * @param incorrect_words A vector of strings containing the incorrect words
     * @param filename The name of the file to write to
     * @return true if the file is written successfully, false otherwise
     */
    std::ofstream outfile(filename,std::ios::app);
    if (!outfile.is_open()) {
        return false;
    }
    std::string time_str = session_data.start_data_time;
    outfile<<time_str<<"|"; // extract the start date and time
    for (const auto &word : incorrect_words) {
        outfile << word << " ";
    }
    outfile << "\n";
    outfile.close();
    return true;
}
   

    