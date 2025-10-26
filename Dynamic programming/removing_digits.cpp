#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool has_digit(int n, int d) {
    int tens = 1;
    //cout<<n<<":"<<"your digits"<<"\n";
    while(tens <= n) {
        //cout<<(n/tens)%10<<"\n";
        if((n/tens)%10 == d) return true;
        tens *= 10;
    }

    return false;
}

int32_t main() {
    int n; cin >> n;
    vector<int> dp(n+1, LONG_MAX);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=1;j<10;j++) {
            if(i+j > n) continue;
            if(has_digit(i+j, j))
                dp[i+j] = min(dp[i] + 1, dp[i+j]);
        }

        //cout<<dp[i] << " " << "your min\n";
    }

    cout<<dp[n]<<endl;

    return 0;
}

/*
f(n) -> min[f(n-d1) ... f(n-dm)]
*/