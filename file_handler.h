#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>
#include <tuple>

std::tuple<bool, std::vector<std::string>> read_words_from_file(const std::string &filename);
bool write_analytics_csvfile(const std::string &filename, const std::vector<std::string> &data);
bool write_incorrect_words_txtfile(std::vector<std::string> &incorrect_words, const std::string &filename);


#endif // FILE_HANDLER_H
