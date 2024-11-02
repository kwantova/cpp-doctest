#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "histogram_internal.h"
#include "histogram.h"

TEST_CASE("distinct positive numbers") {
    double min = 0;
    double max = 0;
    find_minmax({1,2}, min, max);
    CHECK(min == 1);
    CHECK(max == 2);
}

TEST_CASE("null vector") {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    CHECK(min == 0);
    CHECK(max == 0);
}

TEST_CASE("negative elements vector") {
    double min = 0;
    double max = 0;
    find_minmax({-1,-3,-5}, min, max);
    CHECK(min == -5);
    CHECK(max == -1);
}


TEST_CASE("identical elements vector") {
    double min = 0;
    double max = 0;
    find_minmax({8, 8, 8}, min, max);
    CHECK(min == 8);
    CHECK(max == 8);
}
/*TEST_CASE("null vector") {
    size_t bin_count = 0;
    vector <size_t> bins (bin_count);
}*/
