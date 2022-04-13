#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class finder {
 private:
  std::string _haystack;
  std::string _needle;
  int _threshold = 0;
  int _lengthOfWord = 0;
  int _haystackOffset = 0;

  bool _isFound = false;
  bool _isFindedBefore = false;
  int _longer;

 public:
  finder();
  finder(std::string& haystack, std::string needle, int& threshold);

  /// methods for FindSearch
  void MyFind(std::string p, int posInNeedle);
  int checkLongerWord(int posH, int posN);
  bool checkRepeat(int posH, int posN);
  void FindSearch();

  /// setters
  void SetHaystack(const std::string& str);
  void SetNeedle(const std::string& str);
  void SetThreshold(const int& number);

  /// methods for Knude_Morris_Prutt search
  std::vector<int> PrefixFunction(const std::string& pattern);
  void namefunc(std::string p, int posInNeedle);
  int KMPSearch(std::string& pattern, int posInNeedle);
  void Search();
};