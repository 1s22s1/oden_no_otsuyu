#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

ll f(ll H)
{
    if (H == 1)
    {
        return 1;
    }

    return 2 * f(H / 2) + 1;
}

int main()
{
    init();

    ll H;
    cin >> H;

    cout << f(H) << endl;

    return 0;
}
