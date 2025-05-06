#include <bits/stdc++.h>
using namespace std;

struct Trie {
      struct Vertex {
            int next[2];
            Vertex() {
                  fill(begin(next), end(next), -1);
            }
      };

      vector<Vertex> trie;

      Trie() {
            trie.resize(1);
      }

      void insert(int x) {
            int v = 0;
            for(int i = 21; i >= 0; i--) {
                  int c = x >> i & 1;
                  if(trie[v].next[c] == -1) {
                        trie[v].next[c] = trie.size();
                        trie.emplace_back();
                  }
                  v = trie[v].next[c];    
            }
      }

      int get(int v, int x, int bit) {
            if(bit < 0) return 0;
            int nxt = (x >> bit & 1) ^ 1;

            if(trie[v].next[nxt] != -1) {
                  return get(trie[v].next[nxt], x, bit - 1) | (1 << bit);
            } else {
                  return get(trie[v].next[nxt ^ 1], x, bit - 1);
            }
      }

} trie;

int main() {
      
}