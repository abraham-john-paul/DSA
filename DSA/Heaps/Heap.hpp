#include "../header.h"

class minHeap
{
    vector<int> heap;

public:
    void minHeapifyUp(int idx)
    {
        if (idx == 0)
        {
            return;
        }
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx])
        {
            swap(heap[parent], heap[idx]);
            minHeapify(heap, parent);
        }
    }

    void minHeapifyDown(int idx)
    {
        int smallest = idx;
        int left = (idx << 1) + 1;
        int right = left + 1;
        const int n = heap.size();
        if (left < n && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < n && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != idx)
        {
            swap(heap[smallest], heap[idx]);
            minHeapifyDown(smallest);
        }
    }

    void insertItem(int val)
    {
        int n = A.size();
        heap.push_back(val);
        minHeapifyUp(n);
    }

    bool deleteItem (int idx)
    {
        if (idx < heap.size())
        {
            swap(heap[idx], heap.back());
            heap.pop_back();
            minHeapifyDown(idx);
            return true;
        }
        else
        {
            return false;
        }
    }

    void top()
    {
        if (empty())
        {
            throw runtime_error;
        }
        return heap[0];
    }

    bool empty()
    {
        return heap.size() == 0;
    }
};
