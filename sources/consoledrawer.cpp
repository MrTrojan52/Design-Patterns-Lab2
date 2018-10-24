#include "headers/consoledrawer.h"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;
void ConsoleDrawer::DrawBorder(unsigned long rows, unsigned long cols) const {
    cout << "\033[0;0H";
    int cell_width = 6;
    char vDelim = '+';
    char hDelim = '-';
    char vBar = '|';
    std::string row = "";

    for(unsigned long c = 0; c < cols; ++c) {
        row += vDelim;
        for(int i = 0; i < cell_width; ++i)
            row += hDelim;
    }
    row += vDelim;
    for(unsigned long r = 0; r < rows; ++r) {
        cout << row << endl;
        for(int i = 0; i < cols + 1; ++i)
            cout << vBar << std::setw(cell_width + 1);
        cout << endl;
    }
    cout << row << endl;
}


void ConsoleDrawer::DrawItem(unsigned long row, unsigned long col, int val) const {
    cout << "\033[s";
    int cell_width = 6;
    std::string offset = "";
    offset = "\033[" + std::to_string(row * 2 + 2) + ';' + std::to_string(col * (cell_width+1) + 2) + 'H';
    cout << offset;
    cout << val;
    cout << "\033[u";
    cout.flush();
}
