#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int check(vector<int>& a, int mid) {
    int count = 1;
    int sum = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] > mid) return a.size()+1;
        sum += a[i];
        while(sum > mid) {
            sum = a[i];
            count++;
        }
    }

    return count;
}

int32_t main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int l=0, h = 1e18;
    int ans = 0;
    while(l <= h) {
        int mid = l+(h-l)/2;
        int t = check(a,mid);
        //cout<<t<<"\n";
        if(t <= k) {
            //cout<<"mid:"<< mid<<" t:"<<t<<endl;
            ans = mid;
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}