#include "../header.h"

bool isValid(int x, int y, const vector<int>& xCoord, const vector<int>& yCoord, const int radius) {
    int nCircles = xCoord.size();
    int xVal, yVal;
    int radiusSq = radius * radius;
    for (int i = 0; i < nCircles; i++) {
        xVal = (x - xCoord[i]);
        xVal *= xVal;
        yVal = (y - yCoord[i]);
        yVal *= yVal;
        if (xVal + yVal - radiusSq <= 0) {
            return false;
        }
    }
    return true;
}
string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    if (!isValid(0, 0, E, F, D)) {
        return "NO";
    }
    visited[0][0] = true;
    vector<vector<int>> direc = {
        {1, 0}, {1, -1}, {1, 1},
        {0, 1}, {0, -1},
        {-1, 0}, {-1, -1}, {-1, 1}
    };
    int u, v;
    while (!q.empty()) {
        auto& p = q.front();
        for (const auto& d: direc) {
            u = p.first + d[0];
            v = p.second + d[1];
            if (u < 0 || v < 0 || u > A || v > B) continue;
            if (!visited[u][v] && isValid(u, v, E, F, D)) {
            if (u == A && v == B) {
                return "YES";
            }
            visited[u][v] = true;
            q.push({u, v});
            }
        }
        q.pop();
    }
    return "NO";
}
