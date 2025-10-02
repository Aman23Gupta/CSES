#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            cout<<0<<" ";
        }
        else {
            cout<< st.top() + 1 << " ";
        }
        st.push(i);
    }

    cout<<endl;

    return 0;
}