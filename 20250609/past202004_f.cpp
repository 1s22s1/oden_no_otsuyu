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

    int N;
    cin >> N;

    map<ll, vector<ll>> map;

    rep(i, N)
    {
        ll x, y;
        cin >> x >> y;

        map[x - 1].push_back(y);
    }

    ll answer = 0;
    priority_queue<ll> pq;

    rep(i, N)
    {
        for (auto x : map[i])
        {
            pq.push(x);
        }

        answer += pq.top();
        pq.pop();

        cout << answer << endl;
    }

    return 0;
}
