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

/// поиск паттерна в строке
void finder::find(std::string p, int posInNeedle) {
  int index = 0;
  bool finded = false;
  while (index != _haystack.npos) {
    index = _haystack.find(p, index);

    if (checkRepeat(index, posInNeedle)) {
      _longer--;
      index = index + 1;
    } else if (index != _haystack.npos) {
      int what = checkLongerWord(index + _threshold, posInNeedle + _threshold);
      _longer = what;
      finded = true;
      std::cout << "sequence of length = " << _threshold + what;
      std::cout << " found at haystack offset " << index;
      std::cout << ", needle offset " << posInNeedle << std::endl;
      index = index + what + 1;
    }
  }
  _isFindedBefore = finded;
  if (_longer != 0) _isFindedBefore = true;
}

finder::finder(std::string& haystack, std::string needle, int& threshold) {
  _haystack = haystack;
  _threshold = threshold;
  _needle = needle;
}
finder::finder() {}

void ExtendedSearch(std::string haystack, std::string needle, int threshold) {
  finder obj(haystack, needle, threshold);
  int len = needle.length();
  for (int counter = len - threshold + 1, shift = 0; counter - shift > 0;
       shift++) {
    obj.find(needle.substr(shift, threshold - 1 + shift), shift);
  }
}
void finder::FindSearch() {
  int len = _needle.length();
  for (int counter = len - _threshold + 1, shift = 0; counter - shift > 0;
       shift++) {
    find(_needle.substr(shift, _threshold - 1 + shift), shift);
  }
}
// int main() {
//   unsigned int start_time = std::clock();
//   std::string haystack = "abcddab";
//   std::string needle = "abcd";
//   haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
//   needle = "abcd1234";
//   int threshold = 3;
//   for (int i = 0; i < 1000; i++) ExtendedSearch(haystack, needle, threshold);

//   std::cout << std::clock() - start_time;
// }