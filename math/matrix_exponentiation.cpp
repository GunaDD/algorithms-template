#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using matrix = array<array<ll, 5>, 5>;

const int mod = 1e9 + 7;

matrix mult(matrix a, matrix b) {
      matrix c = {{ 
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 0}
      }};

      for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                  for(int k = 0; k < 5; k++) {
                        c[i][j] += a[i][k] * b[k][j] % (mod - 1);
                        c[i][j] %= mod - 1;
                  }
            }
      }

      return c;
}

matrix matPow(matrix a, ll k) {
      matrix res = {{ 
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0}, 
            {0, 0, 1, 0, 0}, 
            {0, 0, 0, 1, 0}, 
            {0, 0, 0, 0, 1}
      }};

      while(k > 0) {
            if(k & 1) res = mult(res, a);
            a = mult(a, a);
            k /= 2;
      }

      return res;
}

int main() {

}