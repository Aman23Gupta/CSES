#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            set<int> st;
            for(int k = 0; k < i; k++) {
                st.insert(grid[k][j]); // Collect existing values in the column
            }

            for(int k = 0; k < j; k++) {
                st.insert(grid[i][k]); // Collect existing values in the row
            }
            int count = 0;
            for (int val : st) {
                if (val == count) {
                    count++;
                }
                else {
                    break; // Found a gap in the sequence
                }
            }

            grid[i][j] = count; // Assign the smallest non-negative integer not in the row or column
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}