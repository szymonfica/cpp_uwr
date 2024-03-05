#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define BOOST ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const vector<pair<int, string> > roman = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

string toroman(int x) {
    string res = "";
    for(unsigned int i=0; i<roman.size(); i++) {
        while(x >= roman[i].first) {
            res += roman[i].second;
            x -= roman[i].first;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    BOOST

    for(int i=1; i<argc; i++) {
        int x=0;
        try {
            x = stoi(argv[i], nullptr, 10);
            if(x < 1 || x > 3999) throw 1;
        }
        catch(...) {
            clog<< "Error: Incorrect input!\n";
            continue;
        }
        cout<< toroman(x) << '\n';
    }

    return 0;
}