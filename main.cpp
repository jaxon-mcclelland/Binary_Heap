#include <iostream>
#include <algorithm>
#include "BinaryHeap.h"

int main(void) {
    BinaryHeap<int> my_heap;
    for(int i = 1; i <= 100; ++i) {
        my_heap.insert(i);
        assert(i == my_heap.getMax());
    }
    vector<int> arr(100);
    for(int i = 99; i >= 0; --i) {
        arr[i] = my_heap.getMax();
        my_heap.popMax();
    }
    vector<int> arr2 = arr;
    std::sort(arr2.begin(), arr2.end());

    for(int i = 0; i < 100; ++i) {
        assert(arr[i] == arr2[i]);
    }
    
    return 0;
}