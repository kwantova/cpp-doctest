#include <iostream>
#include <vector>
#include "histogram.h"
#include "histogram_internal.h"

using namespace std;
void
find_minmax(const vector <double> &numbers, double &min, double &max){
    if (numbers.size() == 0){min = 0; max = 0;}
    else{
        min = numbers[0];
        max = numbers[0];
        for (float now: numbers){
            if (now < min) {min = now;}
            if (now > max) {max = now;}
        }
        return;
    }
}

vector <size_t>
make_histogram(const vector <double> &numbers, size_t bin_count){
    vector <size_t> bins(bin_count);
    double min = 0, max = 0;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    double lo = min, hi = min + bin_size;
    for (size_t i = 0; i < bin_count; i++){
        for (auto now : numbers){
            if (i == bin_count - 1) {
                if ((now >= lo) && (now <= hi)) {bins[i]++;}
            }
            else {
                if ((now >= lo) && (now < hi)) {bins[i]++;}
            }
        }
        lo = hi; hi += bin_size;
    }
    return bins;
}
