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

ll f(ll N)
{
    if (N == 0)
    {
        return 1;
    }

    return N * f(N - 1);
}

int main()
{
    init();

    ll N;
    cin >> N;

    cout << f(N) << endl;

    return 0;
}
