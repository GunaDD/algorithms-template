#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 5;

int N;

struct fenwick {
        int t[MX];

        void upd(int pos, int val) {
                for(int i=pos;i<=N;i+=i&-i) t[i]+=val;
        }

        int que(int pos) {
                int res=0;
                for(int i=pos;i>0;i-=i&-i) res+=t[i];
                return res;
        }

        int que(int l, int r) {
                return que(r)-que(l-1);
        }
} ft;

int main() {
        N = 5;
}