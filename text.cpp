#include <iostream>
#include <vector>
#include <cmath>
#include "text.h"
const size_t WINDOW_WIDTH = 80;
const size_t MAX_VALUE = WINDOW_WIDTH - 3 - 1;
using namespace std;
void
show_histogram_text(const vector <size_t> &bins){
    size_t max_count = 0;
    for (auto now: bins)
        {if (now > max_count) {max_count = now;}}
    cout << "mc = " << max_count << endl;
    for (size_t now : bins){
        if (now < 100) {cout << ' ';} if (now < 10) {cout << ' ';}           //форматирование строк
        cout << now << "|";
        int height;
        if (now == max_count) {height = MAX_VALUE * 1.0;}
        else {height = MAX_VALUE * (static_cast <double> (now) / max_count);}
        for (int i = 0; i < round(height); i++) {cout << "*";}
        cout << endl;
    }
}
