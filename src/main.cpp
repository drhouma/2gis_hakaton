#include <iostream>
#include <string>

class matches {
 private:
  int _threshold = 0;
  bool _isFound = false;

  int _haystackOffset = 0;
  int _needleOffset = 0;
  int _lengthOfWord = 0;
  //   std::string haystack, needle;

 public:
  matches(const int& length);
  int GetIndex(std::string& str, std::string::iterator iter);
  void FindMatch(std::string haystack, std::string needle);
  void FindMatch(std::string& haystack, std::string::iterator& iterH,
                 std::string& needle, std::string::iterator iterN);
  void show();
};

matches::matches(const int& length) { _threshold = length; }

void matches::FindMatch(std::string& haystack, std::string::iterator& iterH,
                        std::string& needle, std::string::iterator iterN) {
  int len = 0;
  _haystackOffset = GetIndex(haystack, iterH);
  _needleOffset = GetIndex(needle, iterN);
  for (; *iterH == *iterN; iterH++, iterN++, len++) {
  }
  if (len >= _threshold) {
    _lengthOfWord = len;
    _isFound = true;
  } else {
    _haystackOffset = 0;
    _needleOffset = 0;
  }
}

int matches::GetIndex(std::string& str, std::string::iterator iter) {
  int ret = 0;
  std::string::iterator start = str.begin(), last = str.end();
  while (start != iter && start != last) {
    if (start == iter) break;
    ret++;
    start++;
  }
  if (start == last) ret = -1;
  return ret;
}

void matches::show() {
  if (_isFound) {
    std::cout << "sequence of length = " << _lengthOfWord;
    std::cout << " found at haystack offset " << _haystackOffset;
    std::cout << ", needle offset " << _needleOffset << std::endl;
  }
}

int main() {
  std::string haystack, needle;
  int threshold;
  std::cout << "enter haystack string" << std::endl;
  //   std::cin >> haystack;
  std::cout << "enter needle string" << std::endl;
  //   std::cin >> needle;
  std::cout << "enter threshold (int number)" << std::endl;
  //   std::cin >> threshold;
  haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
  needle = "abcd1234";
  //   haystack = "abcd";
  //   needle = "ab";
  threshold = 3;

  std::string::iterator iterH = haystack.begin(), endH = haystack.end();

  std::string::iterator endN = needle.end(), beginN = needle.begin(),
                        iterN = beginN;

  for (; iterH != endH; iterH++) {
    iterN = beginN;
    for (; iterN != endN; iterN++) {
      if (*iterN == *iterH) {
        matches finder(threshold);
        finder.FindMatch(haystack, iterH, needle, iterN);
        finder.show();
      }
    }
  }
}
