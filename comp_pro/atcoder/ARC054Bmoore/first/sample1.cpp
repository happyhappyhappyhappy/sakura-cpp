#include <bits/stdc++.h>

using namespace std;

using ld = long double;

inline ld f(const ld x, const ld p) {
    return x + p * pow(0.5, x / 1.5);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ld p;
    cin >> p;

    ld lb = 0, ub = p;
    for (int i = 0; i < 148; ++i) {
        ld t1 = (2.0 * lb + ub) / 3.0;
        ld t2 = (lb + 2.0 * ub) / 3.0;

        if (f(t1, p) > f(t2, p)) lb = t1;
        else ub = t2;
        cout << "TERM : " << i << " LEFT:" << lb <<
        " RIGHT: " << ub << "\n" << flush; 
    }
    cout << "LAST : LEFT: " << lb << " RIGHT: " << ub << "\n" << flush; 

    cout << setprecision(10) << setiosflags(ios::fixed);
    cout << f(lb, p) << endl;

    return 0;
}