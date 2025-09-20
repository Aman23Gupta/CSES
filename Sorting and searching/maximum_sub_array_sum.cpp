#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    int all_max = INT_MIN, curr_max = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i]; 
        curr_max = max(a[i], sum);
        sum = curr_max;
        all_max = max(curr_max, all_max);
    }

    cout<<all_max<<endl;
    return 0;
}