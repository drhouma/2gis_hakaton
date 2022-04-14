#pragma once
#include <ctime>
#include <iostream>

#include "finder.h"

class interface {
 private:
  /// -1 - program is off, 0 - exit, 1 - enter data, 2 - set search mode, 3 -
  /// search, 4 - enable / disable time show, 10 - user choose mod
  int _status = -1;
  // 1 - find, 2 - KMP
  int _searchMode = 1;

  bool _showTime = false;
  finder *model;

 public:
  interface(finder *obj);
  std::string InputString(const std::string &whatStr);

  int InputNumber(const std::string &whatStr);
  int MainLoop();
};

void ExtendedSearch(std::string haystack, std::string needle, int threshold);