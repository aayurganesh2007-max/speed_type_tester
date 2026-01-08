#include "analytics.h"
#include <algorithm>
#include <cctype>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>

int net_words_per_minute(int timer_seconds,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
 * @brief Calculates the number of correct words typed per minute.(Only the correct words are counted)
 * 
 * @param seconds The total time taken to type the words.
 * @param display_words A vector of strings containing the words to be typed.
 * @param inp_words A vector of strings containing the words typed by the user.
 * @return The number of words typed per minute.
 * If seconds is zero, returns zero to avoid division by zero.
 * Otherwise, returns the number of correct words typed per minute.
 */
    if (timer_seconds == 0){
       return 0; // to avoid division by zero
    }
    std::vector<std::string> correct_words;
    std::vector<std::string> incorrect_words;
    std::tie(correct_words,incorrect_words) = correct_words_check(display_words, inp_words);
    return (correct_words.size() * 60) /timer_seconds;
}

int raw_words_per_minute(int timer_seconds,const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /** 
     * @brief Calculates the number of correct words typed per minute.(All words typed are counted)
     * 
     * @param seconds The total time taken to type the words.
     * @param display_words A vector of strings containing the words to be typed.
     * @param inp_words A vector of strings containing the words typed by the user.
     * @return The number of words typed per minute.
     * If seconds is zero, returns zero to avoid division by zero.
     * Otherwise, returns the number of correct words typed per minute.
     */
    if (timer_seconds == 0){
       return 0; // to avoid division by zero
    }
    std::vector<std::string> correct_words;
    std::vector<std::string> incorrect_words;
    std::tie(correct_words,incorrect_words) = correct_words_check(display_words, inp_words);
    return (correct_words.size() + incorrect_words.size()) * 60 /timer_seconds;
}

int net_chars_per_minute(int timer_seconds, const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
     * @brief Calculates the number of correct characters typed per minute.(Only correctly typed characters are counted)
     * 
     * @param seconds The total time taken to type the characters.
     * @param display_words A vector of strings containing the words to be typed.
     * @param inp_words A vector of strings containing the words typed by the user.
     * @return The number of characters typed per minute.
     * If seconds is zero, returns zero to avoid division by zero.
     * Otherwise, returns the number of correct characters typed per minute.
     */
   if (timer_seconds == 0){
       return 0; // to avoid division by zero
   }
   int total_chars = 0;
   int correct_chars = 0;
   std::tie(total_chars, correct_chars) = correct_chars_check(display_words, inp_words);
   return (correct_chars * 60) / timer_seconds;

}

int raw_chars_per_minute(int timer_seconds, const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
     * @brief Calculates the number of correct characters typed per minute.(All characters typed are counted)
     * 
     * @param seconds The total time taken to type the characters.
     * @param display_words A vector of strings containing the words to be typed.
     * @param inp_words A vector of strings containing the words typed by the user.
     * @return The number of characters typed per minute.
     * If seconds is zero, returns zero to avoid division by zero.
     * Otherwise, returns the number of correct characters typed per minute.
     */
   if (timer_seconds == 0){
       return 0; // to avoid division by zero
   }
   int total_chars = 0;
   int correct_chars = 0;
   std::tie(total_chars, correct_chars) = correct_chars_check(display_words, inp_words);
   return (total_chars * 60) / timer_seconds;
}
std::tuple<std::vector<std::string>, std::vector<std::string>> correct_words_check(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
    * @brief Checks the number of correct and incorrect words typed by the user (case sensitive)
    * 
    * @param display_words A vector of strings containing the words to be typed
    * @param inp_words A vector of strings containing the words typed by the user
    * 
    * @return A tuple containing two vectors - one for correct words and another for incorrect words
    */
    std::vector<std::string> correct_words;
    std::vector<std::string> incorrect_words;

   //min ensures that we do not go out of bounds if user types less or more words than displayed
   int total_words = std::min(display_words.size(), inp_words.size());
   for(int i=0; i<total_words; i++){
       if(display_words[i] == inp_words[i]){
           correct_words.push_back(display_words[i]);
       }
       else{
           incorrect_words.push_back(display_words[i]);
       }
   }
   return std::make_tuple(correct_words, incorrect_words);
}
std::tuple<int, int> correct_chars_check(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
    * @brief Checks the number of correct characters typed by the user
    * 
    * @param display_words A vector of strings containing the words to be typed
    * @param inp_words A vector of strings containing the words typed by the user
    * 
    * @return A tuple containing total characters typed and correct characters typed
    */
   int total_chars = 0;
   int correct_chars = 0;


   //min ensures that we do not go out of bounds if user types less or more words than displayed
   int total_words = std::min(display_words.size(), inp_words.size());
   for(int i=0; i<total_words; i++){
       if (display_words[i].length()>inp_words[i].length()){
           total_chars += display_words[i].length();
       }
       else{
           total_chars += inp_words[i].length();
       }
       
       //check character by character
       int word_length = std::min(display_words[i].length(), inp_words[i].length());
       for(int j=0; j<word_length; j++){
           if(display_words[i][j] == inp_words[i][j]){
               correct_chars++;
           }
       }
   }
   return std::make_tuple(total_chars, correct_chars);
}

int accuracy_words(const std::vector<std::string> &display_words,const std::vector<std::string> &inp_words){
    /**
     * @brief It returns the accuracy of correctly typed words in percentage
     * 
     * @param display_words A vector of strings containing the words to be typed
     * @param inp_words A vector of strings containing the words typed by the user
     * @return The accuracy of typed words in percentage
     * If no words were typed, returns zero to avoid division by zero.
     * Otherwise, returns the percentage of correct words typed.
     */
    std::vector<std::string> correct_words;
    std::vector<std::string> incorrect_words;
    std::tie(correct_words, incorrect_words) = correct_words_check(display_words, inp_words);
    int total_typed_words = correct_words.size() + incorrect_words.size();
    if(total_typed_words == 0){
        return 0; // to avoid division by zero
    }
    return (correct_words.size() * 100) / total_typed_words;
}
    

std::vector<std::string> incorrect_words_list(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words){
    /**
     * @brief It returns a list of incorrectly typed words by the user
     * @param display_words A vector of strings containing the words to be typed
     * @param inp_words A vector of strings containing the words typed by the user
     * @return A vector of strings containing the incorrectly typed words
     */
    std::vector<std::string> correct_words;
    std::vector<std::string> incorrect_words;
    std::tie(correct_words, incorrect_words) = correct_words_check(display_words, inp_words);
    return incorrect_words;
}

int accuracy_chars(const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words){
    /**
     * @brief It returns the accuracy of typed characters in percentage
     * @param display_words A vector of strings containing the words to be typed
     * @param inp_words A vector of strings containing the words typed by the user
     * @return The accuracy of typed characters in percentage
     * If no characters were typed, returns zero to avoid division by zero.
     * Otherwise, returns the percentage of correct characters typed.
    */
   int total_chars = 0;
   int correct_chars = 0;
   std::tie(total_chars, correct_chars) = correct_chars_check(display_words, inp_words);
   if(total_chars == 0){
       return 0; // to avoid division by zero
   }
   return (correct_chars * 100) / total_chars;
}


void create_session_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words, std::string difficulty, struct SessionData &session_data) {
    /**
     * @brief Creates a struct containing the relevant data for analytics.(Only called by create_vector_data)
     *    
     * @param display_words A vector of strings containing the words to be typed
     * @param inp_words A vector of strings containing the words typed by the user
     * @param difficulty The difficulty level of the session
     * @param session_data A struct containing the relevant data for analytics.
     * returns:
     * None
     */
    auto now = std::chrono::system_clock::now();
    auto current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* time = std::localtime(&current_time);
    std::ostringstream oss;
    oss << std::put_time(time, "%Y-%m-%d %H:%M:%S");
    std::string time_str = oss.str();
    session_data.start_data_time = time_str; // extract the start date and time
    session_data.timestamp = timer_seconds;// timestamp
    session_data.difficulty_level = difficulty;
    session_data.raw_wpm = raw_words_per_minute(timer_seconds,display_words, inp_words);
    session_data.net_wpm = net_words_per_minute(timer_seconds,display_words, inp_words);
    session_data.raw_cpm = raw_chars_per_minute(timer_seconds, display_words, inp_words);
    session_data.net_cpm = net_chars_per_minute(timer_seconds, display_words, inp_words);
    session_data.accuracy_words = accuracy_words(display_words, inp_words);
    session_data.accuracy_chars = accuracy_chars(display_words, inp_words);
    session_data.incorrect_words = incorrect_words_list(display_words, inp_words);
}

std::tuple <std::vector<std::string>, std::vector<std::string>> create_vector_data(int timer_seconds,const std::vector<std::string> &display_words, const std::vector<std::string> &inp_words, std::string difficulty) {
    /**
     * @brief Creates a vector of strings containing the relevant data for analytics, from struct SessionData.
     * and returns the data and incorrect words list.
     *    
     * @param display_words A vector of strings containing the words to be typed
     * @param inp_words A vector of strings containing the words typed by the user
     * @return tuple of two vectors- first one with data analytics, second one with incorrect words list.
     */
    struct SessionData session_data;
    create_session_data(timer_seconds,display_words, inp_words, difficulty, session_data);
    std::vector<std::string> data;
    data.push_back(session_data.date);
    data.push_back(std::to_string(session_data.timestamp));
    data.push_back(session_data.difficulty_level);
    data.push_back(std::to_string(session_data.raw_wpm));
    data.push_back(std::to_string(session_data.net_wpm));
    data.push_back(std::to_string(session_data.raw_cpm));
    data.push_back(std::to_string(session_data.net_cpm));
    data.push_back(std::to_string(session_data.accuracy_words));
    data.push_back(std::to_string(session_data.accuracy_chars));
    return std::make_tuple(data, session_data.incorrect_words);
}

