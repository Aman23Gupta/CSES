#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    int t;
    cin >> t;

    vector<int> digits(18, 0);
    int d = 9;
    for(int i = 1; i <= 17; i++) {
        digits[i] = d * i;
        d *= 10;
        digits[i] += digits[i - 1];

        if(digits[i] > 1e18) {
            digits[i] = 1e18;
            break;
        }
    }

    while(t--) {
        int n;
        cin >> n;
        int num_digits = 0;
        for(int i = 1; i <= 17; i++) {
            if(n <= digits[i]) {
                n-= digits[i - 1];
                num_digits = i;
                break;
            }
        }
        //cout << "N: " << n << " Num Digits: " << num_digits << endl;
        int tens = 1;
        for(int i = 1; i < num_digits; i++) {
            tens *= 10;
        }

        int left_over = n / (tens * num_digits);
        int start = (tens * (left_over+1));
        n -= left_over * tens * num_digits;

        //cout << "Start: " << start << " Left over: " << left_over << " N: " << n << " " << num_digits << endl;

        int index = n / num_digits -(n % num_digits == 0 ? 1 : 0);

        //cout << "Index: " << index << endl;
        int final_value = start + index;
        int shifts = n % num_digits == 0 ? num_digits - 1 : n % num_digits - 1;
        string s = to_string(final_value);

        //cout << "Final Value: " << final_value << " Shifts: " << shifts << endl;

        cout << s[shifts] << endl;
    }

    return 0;
}