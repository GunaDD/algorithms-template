#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> line;

double isec(int x, int y)  {
        return (double)(line[x].second-line[y].second)/(line[y].first-line[x].first);
}

bool comp(int x, int y, int z) { // return true if should pop
        // compare line x and y

        if(line[y].first==line[z].first) {
                return line[y].second<=line[z].second;
        }
        return isec(y,z)<=isec(x,y);
}

vector<pair<double,int>> ch;
vector<int> pos;

ll qry(ll x) {
        int l=0,r=ch.size()-1,res=-1;
        while(l<=r) {
                int mid=(l+r)>>1;
                if(ch[mid].first>=x) {
                        res=mid;
                        r=mid-1;
                } else {
                        l=mid+1;
                }
        }
        if(res==-1) {
                res=pos.back();
        } else {
                res=pos[ch[res].second];
        }

        return res;
}

int main() {
        
}