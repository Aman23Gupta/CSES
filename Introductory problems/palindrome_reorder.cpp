#include <bits/stdc++.h>
using namespace std; 

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int odd_count = 0;
    for (const auto& pair : freq) {
        if (pair.second % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        string half = "";
        for (const auto& pair : freq) {
            half += string(pair.second / 2, pair.first);
        }
        string palindrome = half;
        if (odd_count == 1) {
            for (const auto& pair : freq) {
                if (pair.second % 2 != 0) {
                    palindrome += pair.first;
                    break;
                }
            }
        }
        reverse(half.begin(), half.end());
        palindrome += half;
        cout << palindrome << endl;
    }

    return 0;
}