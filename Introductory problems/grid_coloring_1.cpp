#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i+j)%2 == 0)
                grid[i][j] = (grid[i][j] == 'A' ? 'C' : 'A');
            else
                grid[i][j] = (grid[i][j] == 'B' ? 'D' : 'B');
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}