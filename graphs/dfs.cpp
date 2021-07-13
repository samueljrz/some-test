#include <bits/stdc++.h>

using namespace std;

#define N 8

vector<int> adj[N];
vector<bool> visited;

void dfs(int v) {
  visited[v] = true;
  cout << v << ' ';
  for(auto u : adj[v]) {
    if(!visited[u]) {
      dfs(u);
    }
  }
}

void dfsStack(int v) {
  stack<int> aux;
  aux.push(v);
  while(!aux.empty()) {
    int u = aux.top();
    aux.pop();
    cout << u << ' ';
    visited[u] = true;
    for(auto e : adj[u]) {
      if(!visited[e]) {
        aux.push(e);
      }
    }
  }
}

int main() {
  visited.assign(N, false);
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[3].push_back(4);
  adj[4].push_back(6);
  adj[2].push_back(5);
  adj[5].push_back(7);
  dfsStack(0);
  cout << endl;
  return 0;
}