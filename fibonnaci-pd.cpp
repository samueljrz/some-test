#include <bits/stdc++.h>

using namespace std;

#define max 10000

int memo[max];

int fibo(int n) {
    if(memo[n] == 0) return memo[n] = fibo(n-1) + fibo(n-2);
    return memo[n];
}

int main()
{
    memo[0] = memo[1] = 1;
    cout<<fibo(6);

    return 0;
}

