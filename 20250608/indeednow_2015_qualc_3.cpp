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

    int N;
    cin >> N;

    vector<vector<int>> g(N);

    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;

        g.at(a - 1).push_back(b - 1);
        g.at(b - 1).push_back(a - 1);
    }

    vector<bool> visited(N, false);
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(0);

    vector<int> answer;

    while (!pq.empty())
    {
        int target;
        target = pq.top();
        pq.pop();
        answer.push_back(target);
        visited.at(target) = true;

        for (auto e : g.at(target))
        {
            if (!visited.at(e))
            {
                pq.push(e);
            }
        }
    }

    rep(i, N)
    {
        if (i == N - 1)
        {
            cout << answer.at(i) + 1 << endl;
        }
        else
        {
            cout << answer.at(i) + 1 << ' ';
        }
    }

    return 0;
}
