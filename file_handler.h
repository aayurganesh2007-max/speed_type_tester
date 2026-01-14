#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>
#include <tuple>

std::tuple<bool, std::vector<std::string>> read_words_from_file(const std::string &filename);
bool write_analytics_csvfile(const std::string &filename, const std::vector<std::string> &data);
bool write_incorrect_words_txtfile(const std::vector<std::string> &incorrect_words, const std::string &filename, const struct SessionData &session_data);
struct LeaderboardEntry {
    std::string date_time;
    std::string difficulty;
    int net_wpm;
    int accuracy_words;
};
std::tuple<bool, std::vector<LeaderboardEntry>> read_leaderboard_from_file(const std::string &filename,const std::string &difficulty);
#endif // FILE_HANDLER_H
