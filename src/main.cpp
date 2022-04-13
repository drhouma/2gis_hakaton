#include "finder.h"
#include "interface.h"

int main() {
  finder model;
  interface Menu(&model);
  Menu.MainLoop();
}