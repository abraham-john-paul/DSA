#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    using pii = pair<int, int>;
    const int n = arrive.size();
    vector<pii> schedule;
    schedule.reserve(2 * n);
    for (int i = 0 ; i < n; i++) {
        schedule.emplace_back(arrive[i], 0);
        schedule.emplace_back(depart[i], 1);
    }

    sort(schedule.begin(), schedule.end());
    int rooms = 0;
    int maxRooms = 0;

    for (const pii p : schedule) {
        if (p.second == 0) {
            rooms++;
            maxRooms = max(rooms, maxRooms);
        } else {
            rooms--;
        }
    }
    return maxRooms <= K ? true : false;
}
