#include <bits/stdc++.h>
using namespace std;


// fast set from https://codeforces.com/blog/entry/118391
// basically just 2 priority queues = 1 set

template<typename T>
struct FastSet {
    priority_queue<T> pq, pending;

    void add(T x) {
        pq.push(x);
    }

    void rem(T x) {
        pending.push(x);
        while (!pq.empty() && !pending.empty() && pq.top() == pending.top()) {
            pq.pop();
            pending.pop();
        }
    }

    T max() {
        assert(!pq.empty());
        return pq.top();
    }
};


int main() {
    FastSet<pair<int,int>> pqA, pqB;
    
}