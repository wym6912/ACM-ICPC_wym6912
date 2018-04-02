#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string expr;
    cin >> expr;
    long long result = 0, cur = 0;
    expr += "+";
    int sign = +1;
    for (char c : expr) {
        if (c == '+' || c == '-') {
            result += sign * cur;
            cur = 0;
        }
        if (c == '-')
            sign = -1;
        if (c == '+')
            sign = +1;
        // bug: + and - signs are accumulated into the number
        cur = cur * 10 + (c - '0');
    }
    cout << result << endl;
    return 0;
}
