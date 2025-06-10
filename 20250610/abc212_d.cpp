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

    int Q;
    cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll d = 0;

    rep(i, Q)
    {
        int query;
        cin >> query;

        switch (query)
        {
        case 1:
            ll a;
            cin >> a;
            pq.push(a - d);

            break;
        case 2:
            ll b;
            cin >> b;
            d += b;

            break;
        case 3:
            cout << pq.top() + d << endl;
            pq.pop();

            break;
        }
    }

    return 0;
}
