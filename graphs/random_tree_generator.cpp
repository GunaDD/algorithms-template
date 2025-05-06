#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int,int>> prueferDecode(vector<int> code) {
        // number of times something appears here equals to number of degree minus one
        int N=code.size()+2;
        vector<int> deg(N);
        for(int i=0;i<N;i++) deg[i]++;
        for(int i=0;i<N-2;i++) deg[code[i]]++;

        set<int> leafs;
        for(int i=0;i<N;i++) {
                if(deg[i]==1) {
                        leafs.insert(i);
                }
        }

        vector<pair<int,int>> edge;

        for(int i=0;i<N-2;i++) {
                int v=*leafs.begin();
                edge.push_back({v,code[i]});
                deg[code[i]]--;
                if(deg[code[i]]==1) leafs.insert(code[i]);
                leafs.erase(v);
        }
        edge.push_back({*leafs.begin(),N-1});

        return edge;
}

int N;

vector<int> curCode;

void genAll() { // N^(N-2) possilbe trees
        if(curCode.size()==N-2) {
                vector<pair<int,int>> tree=prueferDecode(curCode);
                for(auto [x,y]:tree) {
                        cout<<x<<" "<<y<<'\n'; // add 1 for 1 based
                }
                cout<<'\n';

                return;
        }
        for(int j=0;j<N;j++) {
                curCode.push_back(j);
                genAll();
                curCode.pop_back();
        }
}

void genRand() {
        vector<int> randCode;
        for(int i=0;i<N-2;i++) randCode.push_back(rng()%N);
        vector<pair<int,int>> tree=prueferDecode(randCode);
        for(auto [x,y]:tree) {
                cout<<x<<" "<<y<<'\n'; // add 1 for 1 based
        }
        cout<<'\n';
}

int main() {
        cin.tie(0); ios_base::sync_with_stdio(0);

        cin>>N;
        // ENSURE N > 1

        genRand();
}
