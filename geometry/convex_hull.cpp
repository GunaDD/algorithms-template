#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define P pair<ll,ll>
#define X first
#define Y second

int cross(P x, P y) {
      return x.X * y.Y - x.Y * y.X;
}

vector<P> ch(vector<P> pt) {
      int N = pt.size();
      sort(pt.begin(), pt.end());

      vector<P> v, vv;

      v.push_back(pt[0]);
      v.push_back(pt[1]);

      for(int i = 2; i < N; i++) {
            while(v.size() > 1 && cross(
                  make_pair(v[v.size() - 1].X - v[v.size() - 2].X, v[v.size() - 1].Y - v[v.size() - 2].Y), 
                  make_pair(pt[i].X - v[v.size() - 1].X, pt[i].Y - v[v.size() - 1].Y)) >= 0) {
                        
                  v.pop_back();
            }
            v.push_back(pt[i]);
      }

      vv.push_back(pt[N - 1]);
      vv.push_back(pt[N - 2]);

      for(int i = N - 3; i >= 0; i--) {
            while(vv.size() > 1 && cross(
                  make_pair(vv[vv.size() - 1].X - vv[vv.size() - 2].X, vv[vv.size() - 1].Y - vv[vv.size() - 2].Y), 
                  make_pair(pt[i].X - vv[vv.size() - 1].X, pt[i].Y - vv[vv.size() - 1].Y)
                  ) >= 0) {

                  vv.pop_back();
            }
            vv.push_back(pt[i]);
      }

      v.pop_back();
      vv.pop_back();
      
      for(auto x : vv) v.push_back(x);

      return v;
}

int main() {
      
}