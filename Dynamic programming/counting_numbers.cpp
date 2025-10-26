#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"


void getDigits(int x, vector <int> &digit)
{
    while (x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
}

vector<vector<vector<vector<int>>>> dp(20, vector<vector<vector<int>>>(11, vector<vector<int>>(2, vector<int>(2,-1))));

int go(int i, int last_digit, int tight, int pre, vector<int>& digits) {
    if(i<0) return 1;
    if(dp[i][last_digit][tight][pre] != -1) return dp[i][last_digit][tight][pre];

    int a = 0;
    int k = (tight)? digits[i] : 9;

    for(int j=0; j<=k; j++) {
        if(last_digit == j && pre == 0) {
            continue;
        }

        int new_tight = tight & (digits[i] == j);
        int new_pre = pre & (j == 0);
        a += go(i-1, j, new_tight, new_pre, digits);
    }
    
    dp[i][last_digit][tight][pre] = a; 

    return a;
}



int32_t main() {
    int a,b; cin >> a >> b;
    vector<int> d1,d2;
    if(a>0)
        getDigits(a-1, d1);

    getDigits(b, d2);
    dp.assign(20, vector<vector<vector<int>>>(11, vector<vector<int>>(2, vector<int>(2,-1))));

    int res1 = a>0?go(d1.size()-1, 10, 1, 1, d1):0;
    dp.assign(20, vector<vector<vector<int>>>(11, vector<vector<int>>(2, vector<int>(2,-1))));

    int res2 = go(d2.size()-1, 10, 1, 1, d2);
    cout<<(res2-res1)<<endl;

    return 0;
}