#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans=0;
  vector<int> inp;
  cin >> n;
  inp.resize(n);

  for(int i=n-1; i>=0; i--) {
    int aux;
    cin >> aux;
    inp[i] = aux;
  }

  sort(inp.begin(), inp.end(), greater<int>());

  for(int i=n-1; i>=1; i--) {
    inp[i-1] = inp[i] + inp[i-1];
    ans += inp[i-1];
    inp.pop_back();
    sort(inp.begin(), inp.end(), greater<int>());
  }

  cout << ans << endl;

  return 0;
}
