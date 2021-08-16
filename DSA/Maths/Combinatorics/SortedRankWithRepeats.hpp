vector<long long> factorial(int A, int m) {
    vector<long long> ans;
    ans.reserve(A + 1);
    ans.push_back(1);
    long long fac = 1;
    for (int i = 1; i <= A; i++) {
        fac = (fac * i) % m;
        ans.push_back(fac);
    }
    return ans;
}

int findCharLessThan(const string& A, int i) {
    const int nA = A.size();
    int cnt = 0;
    for (int j = i; j < nA; j++) {
        if (A[i] > A[j]) {
            cnt++;
        }
    }

    return cnt;
}

int fastPower(long long a, int p, int m) {
    long long ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        p >>= 1;
    }

    return ans;
}

int findRank(string A) {
    unordered_map<char, int> freqMap;
    for (const char c : A) {
        freqMap[c]++;
    }
    const int nA = A.size();
    const int m = 1000003;
    auto fact = factorial(nA, m);
    long long nLesser;

    long long ans = 1;
    long long reps = 1;
    long long Nr;

    for (int i = 0; i < nA; i++) {
        nLesser = findCharLessThan(A, i);
        reps = 1;
        for (auto p : freqMap) {
            if (p.second > 1) {
                reps = (reps * fact[p.second]) % m;
            }
        }
        freqMap[A[i]]--;
        Nr = (nLesser * fact[nA - i - 1]) % m;
        // cout << reps << "reps\n";
        reps = fastPower(reps, m - 2, m) % m;
        ans = (ans + (Nr * reps) % m) % m;
    }

    return ans;
}
