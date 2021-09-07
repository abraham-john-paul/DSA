#include "../header.h"

class MinStack {
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

vector<int> st;
vector<int> minStack;
int endItr;
int capacity;

MinStack::MinStack() {
    endItr = -1;
    capacity = -1;
    st.clear();
    minStack.clear();
}

void MinStack::push(int x) {
    if (endItr < capacity) {
        st[endItr + 1] = x;
    } else {
        st.push_back(x);
        capacity++;
    }
    if (minStack.empty() || x <= minStack.back()) {
        minStack.push_back(x);
    }
    endItr++;
}

void MinStack::pop() {
    if (endItr != -1) {
        if (st[endItr] == minStack.back()) {
            minStack.pop_back();
        }
        endItr--;
    }
}

int MinStack::top() {
    if (endItr != -1) {
        return st[endItr];
    }
    return -1;
}

int MinStack::getMin() {
    if (endItr != -1) {
        return minStack.back();
    }
    return -1;
}