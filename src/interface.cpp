#include "interface.h"

#include "finder.h"

void showRuntime(size_t start_time) {
  size_t runtime = (double)(std::clock() - start_time) / 1000.0;
  std::cout << "runtime = " << runtime << std::endl;
}

interface::interface(finder *obj) {
  _status = 10;
  model = obj;
}

std::string interface::InputString(const std::string &whatInInput) {
  std::string ret;
  std::cout << "enter " << whatInInput << " string" << std::endl;
  std::cin >> ret;
  return ret;
}

int interface::InputNumber(const std::string &whatInInput) {
  int ret;
  std::cout << "enter " << whatInInput << " number" << std::endl;
  std::cin >> ret;
  return ret;
}

int interface::MainLoop() {
  while (_status != 0) {
    if (_status == 10) {
      std::cout << "*---------------------------*" << std::endl;
      std::cout << "|         Menu modes        |" << std::endl;
      std::cout << "|0 - exit                   |" << std::endl;
      std::cout << "|1 - enter data             |" << std::endl;
      std::cout << "|2 - set search mode        |" << std::endl;
      std::cout << "|3 - search                 |" << std::endl;
      if (_showTime == false) {
        std::cout << "|4 - enable time show       |" << std::endl;
      } else {
        std::cout << "|4 - disable time show      |" << std::endl;
      }
      if (_searchMode == 1) {
        std::cout << "|Search mode - string.find  |" << std::endl;
      } else {
        std::cout << "|Search mode - KMP search   |" << std::endl;
      }

      std::cout << "|___________________________|" << std::endl;
      std::cin >> _status;
      if (_status != 0 && _status != 1 && _status != 2 && _status != 3 &&
          _status != 4) {
        std::cout << "there is no mode " << _status << std::endl;
        _status = 10;
      }
    } else if (_status == 1) {
      model->SetHaystack(InputString("haystack"));
      model->SetNeedle(InputString("needle"));
      model->SetThreshold(InputNumber("threshold"));
      _status = 10;
    } else if (_status == 2) {
      std::cout << "*---------------------------*" << std::endl;
      std::cout << "|        Search modes       |" << std::endl;
      std::cout << "|0 - exit                   |" << std::endl;
      std::cout << "|1 - string.find() search   |" << std::endl;
      std::cout << "|2 - KMP search             |" << std::endl;
      std::cout << "|___________________________|" << std::endl;
      _searchMode = InputNumber("search mode");
      if (_searchMode == 0) {
        _status = 10;
      } else {
        if (_searchMode != 1 && _searchMode != 2) {
          std::cout << "there is no search mode " << _searchMode << std::endl;
          _status = 2;
        } else {
          _status = 10;
        }
      }
    } else if (_status == 3) {
      if (_searchMode == 1) {
        size_t start_time = std::clock();
        model->ExtendedSearchStrFind();
        if (_showTime) showRuntime(start_time);
      } else if (_searchMode == 2) {
        size_t start_time = std::clock();
        model->ExtendedSearchKMP();
        if (_showTime) showRuntime(start_time);
      }
      _status = 10;
    } else if (_status == 4) {
      _showTime = !_showTime;
      _status = 10;
    }
  }
  return 0;
}
