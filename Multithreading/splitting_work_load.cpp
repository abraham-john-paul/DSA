#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void storeData(vector<string>& dataStore, vector<string>& newData, int start, int size);
void readData(int *fobj, int start, int end);

int main() {
    auto a = new int[5000];

    for(int i = 0; i < 5000; i++) {
        a[i] = i + 1;
    }

    for(int i = 0; i < 5000; i++) {
        cout << a[i] << " ";
    }
    
    vector<string> dataStore;
    dataStore.reserve(5000);

    thread t1 = thread([&dataStore](int* a, int start, int end){
        vector<int> v(a + start, a + (end - start + 1));
        // return 
    });

    return 0;
}