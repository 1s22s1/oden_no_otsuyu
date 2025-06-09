#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
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

    vector<int> P(N);
    rep(i, N)
    {
        cin >> P.at(i);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    rep(i, K)
    {
        pq.push(P.at(i));
    }

    cout << pq.top() << endl;

    for (int i = K; i < N; i++)
    {
        if (pq.top() < P.at(i))
        {
            pq.pop();
            pq.push(P.at(i));
        }

        cout << pq.top() << endl;
    }

    return 0;
}
