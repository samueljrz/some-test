#include <bits/stdc++.h>

using namespace std;

int left_node[1024];
int right_node[1024];

void answap(int root, int k) {
  queue<int> q;
  q.push(root);

  int level = 0;

  while(!q.empty()) {
    level++;
    int count = q.size();
    while(count--) {
      int p = q.front();
      q.pop();
      if(level%k == 0) {
        swap(left_node[p], right_node[p]);
      }
      if(left_node[p] != -1) q.push(left_node[p]);
      if(right_node[p] != -1) q.push(right_node[p]);
    }
  }
}

void inorder(int root) {
  if(root == -1)return;
  inorder(left_node[root]);
  cout << root << " ";
  inorder(right_node[root]);
}

int main() {
  int n, a, b, t, k;
  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> a >> b;

    left_node[i] = a;
    right_node[i] = b;
  }

  cin >> t;

  while(t--) {
    cin >> k;
    answap(1, k);
    inorder(1);
    cout << endl;
  }
  return 0;
}