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

    map<int, vector<int>> map;

    rep(i, N)
    {
        int a, b;
        cin >> a >> b;

        map[a - 1].push_back(b);
    }

    ll answer = 0;
    priority_queue<int> pq;

    rep(i, N)
    {
        for (auto e : map[i])
        {
            pq.push(e);
        }

        answer += pq.top();
        pq.pop();

        cout << answer << endl;
    }

    return 0;
}
