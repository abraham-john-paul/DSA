#include "../header.h"

int solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> inDeg(A + 1);
    vector<vector<int>> adjList(A + 1, vector<int>());
    int nEdges = B.size();
    for (int i = 0; i < nEdges; i++) {
        adjList[B[i]].push_back(C[i]);
        inDeg[C[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= A; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
    int node;
    int nCourses = 0;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        nCourses++;
        for (int v : adjList[node]) {
            inDeg[v]--;
            if (inDeg[v] == 0) {
                q.push(v);
            }
        }
    }
    return nCourses == A;
}