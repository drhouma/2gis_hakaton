#include "finder.h"

/// flushes auxiliary parameters
void finder::clearModel() {
  _lengthOfWord = 0;
  _isFindedBefore = false;
  _longer = 0;
  _isFound = false;
}