#include <bits/stdc++.h>

using namespace std;

stack<char> inp;

bool brackets(string s) {
  for(int i=0; i<s.size(); i++) {
    if(s[i] == '{' || s[i] == '[' || s[i] == '(') inp.push(s[i]);
    else if(s[i] == '}') {
      if(inp.empty()) return false;
      if(inp.top() == '{') inp.pop();
      else return false;
    }else if(s[i] == ']') {
      if(inp.empty()) return false;
      if(inp.top() == '[') inp.pop();
      else return false;
    }else if(s[i] == ')') {
      if(inp.empty()) return false;
      if(inp.top() == '(') inp.pop();
      else return false;
    }
  }
  return inp.empty();
}

int main() {
  int n;
  string s;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> s;
    if(brackets(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    while(!inp.empty()) inp.pop();
  }
  return 0;
}