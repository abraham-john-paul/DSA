class Solution
{
    public:
    int doMatching(vector<int>& Z, const string& s, int start, int end) {
        const int nS = s.size();
        while (end < nS && s[end - start] == s[end]) {
            end++;
        }
        Z[start] = end - start;
        return end - 1;
    }
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if (s1.size() != s2.size()) return false;
        string T = s2 + "#" + s1 + s1;
        const int nS2 = s2.size();
        int nT = T.size();
        vector<int> Z(nT);
        int start = 0;
        int end = 0;
        for (int i = 1; i < nT; i++) {
            if (end < i) {
                start = i;
                end = doMatching(Z, T, start, i);
            } else {
                if (Z[i - start] < end - i + 1) {
                    Z[i] = Z[i - start];
                } else {
                    start = i;
                    end = doMatching(Z, T, start, end + 1);
                }
            }
            // cout << Z[i] << endl;
            if (Z[i] == nS2) return true;
        }
        
        return false;
    }
};
