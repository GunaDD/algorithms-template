#include <bits/stdc++.h>
using namespace std;


// 600 ms performance increase from unordered map : https://codeforces.com/contest/585/submission/158393139
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct hsh {
    size_t operator()(const pair<int,int> &p) const {
        return p.first * 383 + p.second;
    }
};

gp_hash_table<pair<int,int>, int, hsh> mp;

int main() {
    
}