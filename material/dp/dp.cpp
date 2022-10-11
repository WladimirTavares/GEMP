#include "bits/stdc++.h"

using namespace std;

int num_palavra(int n){
    long long dp[n+1];

    dp[1] = 3;
    dp[2] = 8;
    for(int i = 3; i <= n; i++){
        dp[i] = 2*dp[i-1] + 2*dp[i-2];
    }

    return dp[n];
}

int main()
{
	int n;
    cin >> n;
    cout << num_palavra(n) << endl;
    return 0;
}
