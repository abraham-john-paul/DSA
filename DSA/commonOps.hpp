#ifndef COMMON_OPS
#define COMMON_OPS

void printMatrix(const vector<vector<int> > &A) {
    int r = A.size();
    if (r == 0) {
        return;
    }
    int c = A[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
void printArray(const vector<int>& A) {
    for (const auto e : A) {
        cout << e << " ";
    }
    cout << "\n";
}

template <class T, class U>
void printUnorderedMap(const unordered_map<T, T> um) {
    for (const auto& p : um) {
        cout << p.first << "->" << p.second << "\n";
    }
}

template<typename T>
void printValue(T v, const string& delimiter = "\n") {
    cout << v << delimiter;
}

template<typename T>
void printValues(initializer_list<T> v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << "\n";
}

#endif