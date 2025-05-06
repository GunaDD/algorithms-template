#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 2e5 + 5; /* change as needed */
const int mod = 1e9 + 7;

ll fact[MX], inv[MX];

ll pw(ll a, ll b) {
        ll ret = 1;
        while(b > 0) {
                if(b & 1) ret = ret * a % mod;
                a = a * a % mod;
                b /= 2;
        }
        return ret;
}

ll C(ll a, ll b) {
        return fact[a] * inv[b] % mod * inv[a - b] % mod;
}

void precompute() {
        fact[0] = 1;
        for(int i = 1; i < MX; i++) fact[i] = fact[i - 1] * i % mod;

        inv[MX - 1] = pw(fact[MX - 1], mod - 2);
        for(int i = MX - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int main() {
        
}