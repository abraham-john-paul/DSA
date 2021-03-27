#include <fstream>
#include <string>

using namespace std;

int main() {
    const string filePath = "/home/abraham_paul/Learning/C++/Multithreading/testData.txt";
    ofstream fobj;
    fobj.open(filePath, ios::trunc);
    const int start = 1;
    const int end = 100;
    int i = start;
    int j = start;
    
    for (; i <= end; i++) {
        for (j = 1; j <= 10; j++)
            fobj << i;
        fobj << "\n";
    }

    if (fobj.is_open()) {
        fobj.close();
    }

    return 0;
}