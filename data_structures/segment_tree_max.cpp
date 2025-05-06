#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 5;

struct segtree {
      	int t[4 * MX];
 
     	void update(int v, int l, int r, int pos, int val) {
           	if(l > pos || r < pos) return;
           	if(l == r) {
                 	t[v] = val;
                 	return;
            	}
            	int mid = (l + r) >> 1;
            	update(v * 2 + 0, l, mid + 0, pos, val);
            	update(v * 2 + 1, mid + 1, r, pos, val);
            	t[v] = max(t[v * 2 + 0], t[v * 2 + 1]);
      	}
 
      	int query(int v, int l, int r, int ql, int qr) {
           	if(ql > r || qr < l) return 0;
                if(ql <= l && qr >= r) return t[v];
           	int mid = (l + r) >> 1;
           	return max(query(v * 2 + 0, l, mid + 0, ql, qr), query(v * 2 + 1, mid + 1, r, ql, qr));
      	}
} st;

int main() {
        
}