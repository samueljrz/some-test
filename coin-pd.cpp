#include <bits/stdc++.h>

using namespace std;

#define maxn 10000
#define maxv 10000
#define inf 214748364

int memo[maxn][maxv];
vector<int> inp;

int ans(int ix, int val) {
  if(val < 0) return inf;
  if(memo[ix][val] == -1) {
    memo[ix][val] = min(1 + ans(ix, val-inp[ix]), ans(ix+1, val));
  }
  return memo[ix][val];
}

int main() {
  int n = 5;
  int val = 175;
  for(int i=0; i<maxn; i++) {
    for(int j=0; i<maxv; j++) {
      memo[i][j] = -1;
    }
  }
  for(int i=val; i<maxv; i++) {
    memo[n][i] = inf;
  }
  memo[n][0] = 0;
  inp.resize(n);
  inp[0] = 2;
  inp[1] = 5;
  inp[2] = 10;
  inp[3] = 20;
  inp[4] = 50;
  cout << ans(0, val);
  return 0;
}