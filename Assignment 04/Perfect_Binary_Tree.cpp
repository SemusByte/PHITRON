#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int x;

    while (cin >> x) {
        a.push_back(x);
    }

    int n = 0;
    for (int v : a) {
        if (v != -1) n++;
    }

    if (n == 0) {
        cout << "NO";
        return 0;
    }

    int h = log2(n + 1);

    if ((1 << h) - 1 != n) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && (a[l] == -1 || a[r] == -1)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}