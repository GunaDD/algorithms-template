#include <bits/stdc++.h>
using namespace std;

const int MX=2e5+5,K=18;

int up[MX][K], tin[MX], tout[MX], timer = 1, sz[MX];

int dep[MX];
vector<int> adj[MX];

int N,M;
 
void dfs(int v, int p) {
        tin[v] = timer++;
        up[v][0] = p;
        for(int k = 1; k < K; k++) {
                up[v][k] = up[up[v][k - 1]][k - 1];
        }
        for(auto u : adj[v]) {
                if(u == p) continue;
                dep[u] = dep[v] + 1;
                dfs(u, v);
                sz[v] += sz[u];
        }
        sz[v]++;
        tout[v] = timer++;
}
 
bool isAnc(int v, int anc) { 
        if(tin[anc] <= tin[v] && tout[v] <= tout[anc]) return 1;
        return 0;
}

int LCA(int u, int v) {
        if(isAnc(u, v)) return v;
        if(isAnc(v, u)) return u;
        for(int k = K-1; k >= 0; k--) {
                if(!isAnc(u, up[v][k]) && up[v][k] != 0) v = up[v][k];
        }
        return up[v][0];
}

int main() {
        
}