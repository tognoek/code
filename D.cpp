#include <bits/stdc++.h>

using namespace std;

string c[] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};

int int_to_string(string a) {
    int res = 0;
    for (int i = 0; i < a.length(); i++) {
        if (int(a[i]) > 57 || int(a[i]) < 48) {
            return -1;
        }
        res = res * 10 + (int(a[i] - 48));
    }
    return res;
}

int string_to_int(string a) {
    for (int i = 0; i < 20; i++) {
        string test = c[i];
        if (test.length() == a.length()) {
            int check = 0;
            for (int t = 0; t < a.length(); t++) {
                if (test[t] != a[t]) {
                    check++;
                    if (check > 1) {
                        break;
                    }
                }
            }
            if (check < 2) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    cin >> n;
    int a = int_to_string(n);
    if (a > 0) {
        cout << c[a];
    } else {
        cout << string_to_int(n);
    }
}