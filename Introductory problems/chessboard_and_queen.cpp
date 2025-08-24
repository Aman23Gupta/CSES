#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool possible(int i, int j, vector<string> & board) {
    for(int k = 0; k < i; k++) {
        if(board[k][j] == 'Q') return false;
        // check diagonals
        if(j - (i - k) >= 0 && board[k][j - (i - k)] == 'Q') return false; // left diagonal
        if(j + (i - k) < 8 && board[k][j + (i - k)] == 'Q') return false; // right diagonal
    }

    return true; // No conflicts found
}

int go(int i, vector<string> &board) {
    if(i == 8) return 1;
    int next = 0;
    for(int k = 0; k < 8; k++) {
        if(possible(i, k, board) && board[i][k] == '.') {
            board[i][k] = 'Q'; // Place queen
            next += go(i + 1, board); // Move to next row
            board[i][k] = '.'; // Backtrack
        }
    }

    return next; // No solution found in this configuration
}

int32_t main() {
    vector<string> board(8);
    for(int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    int ans = go(0, board);
    cout << ans << endl;
    return 0;
}