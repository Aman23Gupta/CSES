#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());
    int c = 1;
    for(int i=1;i<n;i++) {
        if(nums[i] != nums[i-1]) c++;
    }

    cout<<c<<"\n";
    return 0;
}