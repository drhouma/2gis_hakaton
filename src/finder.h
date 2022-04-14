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

  /// methods for ExtendedSearchStrFind
  void MyFind(std::string p, int posInNeedle);
  void ExtendedSearchStrFind();

  /// common methods
  int checkLongerWord(int posH, int posN);
  bool checkRepeat(int posH, int posN);

  /// setters
  void SetHaystack(const std::string& str);
  void SetNeedle(const std::string& str);
  void SetThreshold(const int& number);

  /// methods for Knude_Morris_Prutt search
  std::vector<int> PrefixFunction(const std::string& pattern);
  void SearchLongerPatterns(std::string pattern, int posInNeedle);

  /// возвращает индекс первого символа вхождения pattern в haystack
  int KMPSearch(std::string& pattern, int haystackStartIndex);
  void ExtendedSearchKMP();

  /// model help functions

  void clearModel();
};