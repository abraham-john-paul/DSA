/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MedianFinder {
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxpq.empty() || num < maxpq.top()) {
            maxpq.push(num);
        } else {
            minpq.push(num);
        }

        if (maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        } else if (minpq.size() > maxpq.size() + 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if (minpq.size() == maxpq.size()) {
            return (minpq.top() + maxpq.top()) / 2.0;
        } else if (minpq.size() > maxpq.size()) {
            return minpq.top();
        } else {
            return maxpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

