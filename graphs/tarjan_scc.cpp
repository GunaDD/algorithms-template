#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 5;

bool used[MX];
vector<int> adj[MX], adj_rev[MX];

vector<int> order, component;

void dfs1(int v) {
	used[v] = true;

	for (auto u : adj[v])
		if (!used[u])
            		dfs1(u);

	order.push_back(v);
}

// rerun the "order" in reverse and get the component of the current vertex
void dfs2(int v) {
	used[v] = true;
	component.push_back(v);

	for (auto u : adj_rev[v])
		if (!used[u])
        		dfs2(u);
}

int main() {

}
