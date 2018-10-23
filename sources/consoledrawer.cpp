#include "headers/consoledrawer.h"
#include <iostream>
void ConsoleDrawer::DrawBorder(unsigned long rows, unsigned long cols) const {
    std::cout << "DrawBorder" << std::endl;
}


void ConsoleDrawer::DrawItem(unsigned long rows, unsigned long cols, int val) const {
    std::cout << "DrawItem: " << val << std::endl;
}
