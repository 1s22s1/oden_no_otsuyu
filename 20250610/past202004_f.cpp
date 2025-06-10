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

    priority_queue<int> pq;

    auto answer = 0;
    rep(i, N)
    {
        for (auto v : map[i])
        {
            pq.push(v);
        }

        answer += pq.top();
        pq.pop();

        cout << answer << endl;
    }

    return 0;
}
