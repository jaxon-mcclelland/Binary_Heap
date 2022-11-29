#pragma once
#include <bits/stdc++.h>
#include <vector>



using std::vector;

template <class T>
class BinaryHeap {
    public:
        BinaryHeap(int size = 15);
        ~BinaryHeap();
        void insert(T item);
        T getMax() const;
        void popMax();
    private:
        void _rebalanceHeap();
        vector<T> baseArr;
        int num_items;
};



template <class T>
BinaryHeap<T>::BinaryHeap(int size) {
    baseArr = vector<T>(size + 1);
    this->num_items = 0;
    // baseArr[0] = -INF
    baseArr[0] = INT_MIN;
}

template <class T>
BinaryHeap<T>::~BinaryHeap() {
    baseArr.clear();
}

template <class T>
void BinaryHeap<T>::insert(T item) {
    baseArr[++num_items] = item;
    
    int pos = num_items;
    int parent = pos >> 1;
    while(parent != 0 && baseArr[pos] > baseArr[parent]) {
        T temp = baseArr[parent];
        baseArr[parent] = baseArr[pos];
        baseArr[pos] = temp;

        pos = parent;
        parent = pos >> 1;
    }

    if(baseArr.size() - 1 == num_items) {
        baseArr.resize(baseArr.size() * 2);
    }
}

template <class T>
T BinaryHeap<T>::getMax() const {
    return this->num_items != 0 ? baseArr[1] : NULL;
}

template <class T>
void BinaryHeap<T>::popMax() {
    if(this->num_items < 1) {
        return;
    }
    baseArr[1] = baseArr[--num_items];
    _rebalanceHeap();
}

template <class T>
void BinaryHeap<T>::_rebalanceHeap() {
    int idx = 1;
    int child = 2;
    while(child < num_items) {
        if(baseArr[child + 1] > baseArr[child]) {
            ++child;
        }
        if(baseArr[idx] >= baseArr[child]) {
            break;
        }
        T temp = baseArr[idx];
        baseArr[idx] = baseArr[child];
        baseArr[child] = temp;
        idx = child;
        child = child << 1;   
    }
}