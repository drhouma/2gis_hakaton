#include <ctime>
#include <iostream>

using namespace std;

/**
 * @brief находит все вхождения строки p в строку h, записывает индекс начала
 * вхождения в _haystackOffset
 *
 * @param h
 * @param p
 * @return bool - find or not find
 */

// void find(string h, string p, string needle, int posInNeedle, int threshold)
// {
//   int index = 0, longer = 0;
//   while (index != h.npos) {
//     index = h.find(p, index);
//     if (longer > 0) {
//     }

//     if (index != h.npos) {
//       longer =
//           check_after(h, needle, index + threshold, posInNeedle + threshold);
//       std::cout << "sequence of length = " << threshold + longer;
//       std::cout << " found at haystack offset " << index;
//       std::cout << ", needle offset " << posInNeedle << std::endl;
//       index = index + longer + 1;
//     }
//   }
// }

class finder {
 private:
  string _haystack;
  string _needle;

  int _threshold = 0;
  bool _isFound = false;
  bool _isFindedBefore = false;
  int _longer;

  int _haystackOffset = 0;
  int _lengthOfWord = 0;

 public:
  finder(string& haystack, string needle, int& threshold);
  void find(string p, int posInNeedle);
  int check_after(int posH, int posN);
  bool check_before(int posH, int posN);

  void ExtendedSearch(string haystack, string needle, int threshold) {
    _haystack = haystack;
    _needle = needle;
    _threshold = threshold;
    int len = needle.length();
    for (int counter = len - threshold + 1, shift = 0; counter - shift > 0;
         shift++) {
      find(needle.substr(shift, threshold - 1 + shift), shift);
    }
  }
};
bool finder::check_before(int posH, int posN) {
  bool res = true;
  if (_isFindedBefore) {
    if (_haystack[posH - 1] == _needle[posN - 1]) res = false;
  }
  return res;
}

int finder::check_after(int posH, int posN) {
  int res = 0;
  for (int i = 0; _haystack[posH + i] == _needle[posN + i]; i++) {
    res++;
  }
  return res;
}

void finder::find(string p, int posInNeedle) {
  int index = 0;
  bool finded = false;
  while (index != _haystack.npos) {
    index = _haystack.find(p, index);

    if (!check_before(index, posInNeedle)) {
      _longer--;
      index = index + 1;
    } else if (index != _haystack.npos) {
      int what = check_after(index + _threshold, posInNeedle + _threshold);
      _longer = what;
      finded = true;
      //   std::cout << "sequence of length = " << _threshold + what;
      //   std::cout << " found at haystack offset " << index;
      //   std::cout << ", needle offset " << posInNeedle << std::endl;
      index = index + what + 1;
    }
  }
  _isFindedBefore = finded;
  if (_longer != 0) _isFindedBefore = true;
}

finder::finder(string& haystack, string needle, int& threshold) {
  _haystack = haystack;
  _threshold = threshold;
  _needle = needle;
}

void ExtendedSearch(string haystack, string needle, int threshold) {
  finder obj(haystack, needle, threshold);
  int len = needle.length();
  for (int counter = len - threshold + 1, shift = 0; counter - shift > 0;
       shift++) {
    obj.find(needle.substr(shift, threshold - 1 + shift), shift);
  }
}

int main() {
  unsigned int start_time = clock();
  string haystack = "abcddab";
  string needle = "abcd";
  haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
  needle = "abcd1234";
  int threshold = 3;
  for (int i = 0; i < 1000; i++) ExtendedSearch(haystack, needle, threshold);
  unsigned int end_time = clock();
  cout << end_time - start_time;
}