#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include "histogram.h"
#include "text.h"
#include "svg.h"

const size_t WINDOW_WIDTH = 80;
const size_t MAX_VALUE = WINDOW_WIDTH - 3 - 1;
using namespace std;

struct Input{
    vector <double> numbers;
    size_t bin_count = 0;
};

Input
input_data(istream &thread, bool prompt){
       //произошла накладка с именами переменных: при названии потока in ругается на с22, в которой якобы объявляется аргумент
    prompt = false;
    size_t number_count;
    if (prompt) {cerr << "Enter the amount of numbers: " << endl;}
    cin >> number_count;
    Input in;
    in.numbers.resize(number_count);
    if (prompt) {cerr << "Enter the numbers: " << endl;}
    for (size_t i = 0; i < number_count; i++) {
        cin >> in.numbers[i];
    }
    if (prompt) {cerr << "Enter the amount of bins: " << endl;}
    cin >> in.bin_count;
    return in;
}

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    size_t data_size = item_size * item_count;
    (*buffer).write(reinterpret_cast<const char*> (items), data_size);
    return data_size;
}

Input
download(const string& address){
    stringstream buffer;
    CURLcode res;
    CURL *curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(curl);
        cerr << curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, write_data);  //var 8
        if (res != CURLE_OK){
            cerr << curl_easy_strerror(res);
            exit(1);
        }
    return input_data(buffer, false);
    }
    curl_easy_cleanup(curl);
}


int
main(int argc, char* argv[]){
    curl_global_init(CURL_GLOBAL_ALL);
    Input input, in;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = input_data(cin, true);
    }
    curl_global_init(CURL_GLOBAL_ALL);
    //CURLcode curl_global_init(CURL_GLOBAL_ALL);
    size_t font = 0;
    //auto in = input_data(cin, prompt);
    auto bins = make_histogram(in.numbers, in.bin_count);
    //for (auto now: bins) {cout << now << endl;}
    cin >> font;
    if (font < 8) {(cerr << font << "Font value is too small. Please, edit the input file.");}
    else if (font > 32) {(cerr << "Font value is too large. Please, edit the input file.");}
    else {show_histogram_svg(bins, font);}
    return 0;
}

//с клавиатуры в marks.txt, с marks.txt в marks.svg
