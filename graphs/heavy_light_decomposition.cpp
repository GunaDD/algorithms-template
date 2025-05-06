#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 5;

int sz[MX], nxt[MX], in[MX], out[MX];
vector<int> g[MX];

int t = 0;

void dfs_sz(int v = 0) {
        sz[v] = 1;
        for(auto &u: g[v]) {
                dfs_sz(u);
                sz[v] += sz[u];
                if(sz[u] > sz[g[v][0]]) {
                        swap(u, g[v][0]);
                }
        }
}

// nxt[u] adalah ancestor terjauh yang bisa di capai hanya menggunakan heavy edge
// light edge bagi subtree size dengan 2

void dfs_hld(int v = 0) {
        in[v] = t++;
        for(auto u: g[v]) {
                nxt[u] = (u == g[v][0] ? nxt[v] : u);
                dfs_hld(u);
        }
        out[v] = t;
}

// https://codeforces.com/blog/entry/53170

/* 
up -> up -> ... -> up ( log n kali )
[in(v),out(v)) subtree si v
[in(nxt(v)),in(v)] path si v ke atas
dia query membentuk kea contigous subsegment di segment tree
hemat memori
*/

int main() {

}