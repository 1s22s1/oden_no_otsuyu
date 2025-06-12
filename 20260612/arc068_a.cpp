#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

int main()
{
    init();

    ll x;
    cin >> x;

    auto answer = x / 11 * 2;

    if (6 < x % 11 && x % 11 < 11)
    {
        answer += 2;
    }
    else if (x % 11 != 0)
    {
        answer += 1;
    }

    cout << answer << endl;

    return 0;
}
