#include "finder.h"

const int NOT_FOUND = -1;

std::vector<int> finder::PrefixFunction(const std::string& pattern) {
  int len = pattern.length();
  std::vector<int> out(len);
  for (int i = 1, j = 0; i < len;) {
    if (pattern[i] != pattern[j]) {
      if (j == 0) {
        out[i] = 0;
        i++;
      } else {
        j = out[j - 1];
      }
    } else {
      out[i] = j + 1;
      i++;
      j++;
    }
  }
  return out;
}

int finder::KMPSearch(std::string& pattern, int haystackIndex) {
  int indexHS = haystackIndex;
  int indexPattern = 0;
  int patternLen = pattern.length();
  int haystackLen = _haystack.length();
  int ret = NOT_FOUND;
  bool finded = false;
  std::vector<int> prefix = PrefixFunction(pattern);

  while (!finded) {
    if (_haystack[indexHS] == pattern[indexPattern]) {
      indexHS++;
      indexPattern++;
      if (indexPattern == patternLen) finded = true;
    } else {
      if (indexPattern == 0) {
        // паттерна нет в строке
        if (indexHS == haystackLen) break;
        indexHS++;
      } else {
        indexPattern = prefix[indexPattern - 1];
      }
    }
  }
  // индекс на начало вхождения паттерна
  if (finded) ret = indexHS - _threshold;
  return ret;
}

void finder::SearchLongerPatterns(std::string p, int posInNeedle) {
  /// startIndex - индекс символа, с которого начинается поиск в строке
  int startIndex = 0;
  bool finded = false;
  while (startIndex != NOT_FOUND) {
    startIndex = KMPSearch(p, startIndex);

    if (checkRepeat(startIndex, posInNeedle)) {
      startIndex = startIndex + 1;
    } else if (startIndex != -1) {
      int deltaLen =
          checkLongerWord(startIndex + _threshold, posInNeedle + _threshold);
      _longer = deltaLen;
      finded = true;
      std::cout << "sequence of length = " << _threshold + deltaLen;
      std::cout << " found at haystack offset " << startIndex;
      std::cout << ", needle offset " << posInNeedle << std::endl;
      startIndex = startIndex + deltaLen + 1;
    }
  }
  _isFindedBefore = finded;
  if (_longer != 0) _isFindedBefore = true;
  _longer--;
}

void finder::ExtendedSearchKMP() {
  int len = _needle.length();
  for (int counter = len - _threshold + 1, shift = 0; counter - shift > 0;
       shift++) {
    SearchLongerPatterns(_needle.substr(shift, _threshold), shift);
  }
  this->clearModel();
}

// vnk2435kvabco8awkh125kabcabcjneytbcd12qjhb4acd123xmnbqwnw4tcd12332nkjghkgjfnqliuthlj2qbfkti2§uythkhqfhtu34hrgewlp;['pkdszfghjl;'[lpkvdcszdxfcghjkop;l[oi98r5egsdvz]]]14gouiflqhjk,bmnsad344qoigulhwje

// int main() {
//   std::string haystack = "abcabeabcabcabd";
//   std::string pattern = "abbaabbab";
//   std::vector<int> vec = PrefixFunction(pattern);
//   for (int i = 0; i < pattern.length(); i++) {
//     std::cout << vec[i] << std::endl;
//   }
// }