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

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> X(N);
    rep(i, N)
    {
        int x;
        cin >> x;

        X.at(i) = {x, i};
    }

    priority_queue<pair<int, int>> pq;

    rep(i, K)
    {
        pq.push(X.at(i));
    }

    cout << pq.top().second + 1 << endl;

    for (int i = K; i < N; i++)
    {
        if (pq.top().first > X.at(i).first)
        {
            pq.pop();
            pq.push(X.at(i));
        }

        cout << pq.top().second + 1 << endl;
    }

    return 0;
}
