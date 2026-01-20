#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int val) {
        heap.push_back(val);             // Add to the end
        heapifyUp(heap.size() - 1);      // Bubble up to maintain order
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();           // Move last element to root
        heap.pop_back();                 // Remove last element
        heapifyDown(0);                  // Bubble down to maintain order
    }

    int top() {
        return heap.front();
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap pq;
    pq.push(15);
    pq.push(30);
    pq.push(20);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}