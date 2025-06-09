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

    int N, M;
    priority_queue<ll> pq;

    cin >> N >> M;

    rep(i, N)
    {
        ll A;
        cin >> A;

        pq.push(A);
    }

    rep(i, M)
    {
        ll tmp = pq.top();
        pq.pop();
        pq.push(tmp / 2);
    }

    ll answer = 0;

    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << endl;

    return 0;
}
