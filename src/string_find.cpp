#include "finder.h"

/// setters

void finder::SetHaystack(const std::string& str) { _haystack = str; }
void finder::SetNeedle(const std::string& str) { _needle = str; }
void finder::SetThreshold(const int& number) { _threshold = number; }

/// определяет, входит ли паттерн в уже найденные паттерны
/// возвращает true если паттерн повторяется
bool finder::checkRepeat(int posH, int posN) {
  bool res = false;
  if (_isFindedBefore) {
    if (_haystack[posH - 1] == _needle[posN - 1]) res = true;
  }
  return res;
}

/// проверяет, есть ли паттерн длиннее чем найденный, который включает в себя
/// найденный паттерн
int finder::checkLongerWord(int posH, int posN) {
  int res = 0;
  for (int i = 0; _haystack[posH + i] == _needle[posN + i]; i++) {
    res++;
  }
  return res;
}
// abcdvnk2435kvbcdo8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4tcd123
/// поиск паттерна в строке
void finder::MyFind(std::string p, int posInNeedle) {
  int index = 0, len = _haystack.length();
  bool finded = false;
  while (index < len && index != _haystack.npos) {
    index = _haystack.find(p, index);

    if (checkRepeat(index, posInNeedle)) {
      index = index + 1;
    } else if (index != _haystack.npos) {
      int deltaLen =
          checkLongerWord(index + _threshold, posInNeedle + _threshold);
      _longer = deltaLen;
      finded = true;
      std::cout << "sequence of length = " << _threshold + deltaLen;
      std::cout << " found at haystack offset " << index;
      std::cout << ", needle offset " << posInNeedle << std::endl;
      index = index + deltaLen + 1;
    }
  }
  _isFindedBefore = finded;
  if (_longer != 0) _isFindedBefore = true;
  _longer--;
}

finder::finder(std::string& haystack, std::string needle, int& threshold) {
  _haystack = haystack;
  _threshold = threshold;
  _needle = needle;
}
finder::finder() {}

void finder::ExtendedSearchStrFind() {
  int len = _needle.length();
  for (int counter = len - _threshold + 1, shift = 0; counter - shift > 0;
       shift++) {
    MyFind(_needle.substr(shift, _threshold), shift);
  }
  this->clearModel();
}
