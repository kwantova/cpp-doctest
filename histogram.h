#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include "histogram_internal.h"
using namespace std;
vector <size_t> make_histogram(const vector <double> &numbers, size_t bin_count);

#endif // HISTOGRAM_H_INCLUDED
