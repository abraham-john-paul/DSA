#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<string, string> monthLookup = {
    {"Jan", "01"},
    {"Feb", "02"},
    {"Mar", "03"},
    {"Apr", "04"},
    {"May", "05"},
    {"Jun", "06"},
    {"Jul", "07"},
    {"Aug", "08"},
    {"Sep", "09"},
    {"Oct", "10"},
    {"Nov", "11"},
    {"Dec", "12"},
};

string changeDateFormat(string A) {
    auto itr = find(A.begin(), A.end(), ' ');
    int pos = itr - A.begin();
    string day = A.substr(0, pos - 2);
    if(day.size() == 1) {
        day.insert(0, "0");
    }
    itr = find(itr + 1, A.end(), ' ');
    string month = A.substr(pos + 1, itr - A.begin() - pos - 1);
    pos = itr - A.begin() + 1;
    string year = A.substr(pos, A.end() - itr);
    string dash = "-";
    return year + dash + monthLookup[month] + dash + day;
}

int main() {
    string a = "6th Jun 1933";
    cout << changeDateFormat(a);
    
    return 0;
}
