#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> bit;

void update(int i, int val) {
    while(i <= (int)bit.size()) {
        bit[i] += val;
        i += i&-i;
    }
}

int sum(int i) {
    int ans = 0;
    while(i > 0) {
        ans += bit[i];
        i -= i&-i;
    }

    return ans;
}

int find_pth_element(int p) {
    int h = bit.size()-1, l = 1, ans = l;
    while(l <= h) {
        int m = (l+h)/2;
        int found = sum(m);
        if(p <= found) {
            if(p==found)
                ans = m;
            h = m - 1;
        }
        else {
            l = m + 1; 
        }
    }

    return ans;
}

int32_t main() {
    int n,  k; cin >> n >> k;
    bit.resize(n + 1);

    for(int i = 0; i < n; i++) {
        //add i
        update(i + 1, 1);
    }
    int p = k % n;
    while(n > 0) {
        //find pth element 
        int x = find_pth_element(p + 1);
        cout << x << " ";

        //delete pth element
        update(x, -1);
        n--;

        if(n == 0) break;
        //move forward
        p += k;
        p = p % n;
    }

    cout << endl;

    return 0;
}