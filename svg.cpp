#include <iostream>
#include <vector>
#include <string>
#include "svg.h"
using namespace std;
void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}
void
svg_text(double left, double baseline, size_t font, string text){
    cout << "<text x='" << left << "' y='" << baseline << "' font-size='" << font << "' >" << text << " </text>" << endl;
    return;
}
void
svg_rect(double x, double y, double width, double height, string stroke = "#ed53a8", string fill = "#9df3a1"){
    cout << "<rect x='" << x << "' y='" << y << "' width= '" << width << "' height= '" << height << "' stroke= '" << stroke << "' fill= '" << fill << "'/>" << endl;
    return;
}

void
show_histogram_svg(const vector <size_t> &bins, size_t &font) {

    const auto IMAGE_WIDTH = 800;
    const auto IMAGE_HEIGHT = 600;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto MAX_VALUE = IMAGE_WIDTH - TEXT_WIDTH;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    size_t max_count = 0;

    for (auto now: bins)
        {if (now > max_count) {max_count = now;}}
    for (size_t bin : bins){
        double bin_width = BLOCK_WIDTH * bin;
        if (bin == max_count) {bin_width = MAX_VALUE * 1.0;}
        else {bin_width = MAX_VALUE * (static_cast <double> (bin) / max_count);}
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, font, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_end();
    return;
}
