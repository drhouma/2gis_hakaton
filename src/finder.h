#pragma once

#include <ctime>
#include <iostream>
#include <string>

class finder {
 private:
  std::string _haystack;
  std::string _needle;

  int _threshold = 0;
  bool _isFound = false;
  bool _isFindedBefore = false;
  int _longer;

  int _haystackOffset = 0;
  int _lengthOfWord = 0;

 public:
  finder();
  finder(std::string& haystack, std::string needle, int& threshold);

  void find(std::string p, int posInNeedle);
  int checkLongerWord(int posH, int posN);
  bool checkRepeat(int posH, int posN);

  void SetHaystack(const std::string& str);
  void SetNeedle(const std::string& str);
  void SetThreshold(const int& number);
  void FindSearch();
};