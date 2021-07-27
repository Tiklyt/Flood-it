#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <string>

/**
 * @brief The FileManager class manage File writing and reading scores
 */
class FileManager {
private:
  std::string st1;
  std::string st2;
  std::fstream files;

public:
  /**
   * @brief FileManager Managing for writing score and reading score
   * @param st1         first char of the name of the file.
   * @param st2         second char of the name of the file.
   */
  FileManager(std::string st1, std::string st2) : st1(st1), st2(st2) {}

  /**
   * @brief writeIndex change name file
   * @param idx1       the first char of the name of the file
   * @param idx2       the second char of the name of the file
   */
  void writeIndex(std::string &idx1, std::string &idx2) {
    this->st1 = idx1;
    this->st2 = idx2;
  }

  /**
   * @brief getScore get the score from the file
   */
  unsigned getScore() {
    files.clear();
    char buffer[10];
    std::string value = "./data/" + st1 + st2 + ".txt";
    files.open(value);
    files.read(buffer, 10);
    files.close();
    std::string s = std::string(buffer);
    return std::stoi(s);
  }

  /**
   * @brief writeScore write the best score in the file
   * @param score      the unsigned score
   */
  void writeScore(unsigned score) {
    files.clear();
    std::string value = "./data/" + st1 + st2 + ".txt";
    files.open(value, std::ios::in | std::ios::out);
    std::string s = std::to_string(score);
    files.write(s.c_str(), sizeof(s.c_str()));
    files.close();
  }
};

#endif // FILEMANAGER_H
