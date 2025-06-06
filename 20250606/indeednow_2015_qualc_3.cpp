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

    vector<vector<int>> graph(N);
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;

        graph.at(a - 1).push_back(b - 1);
        graph.at(b - 1).push_back(a - 1);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> visited(N, false);

    pq.push(0);
    visited.at(true);
    vector<int> answer;

    while (!pq.empty())
    {
        int current = pq.top();
        pq.pop();
        answer.push_back(current + 1);

        for (auto e : graph.at(current))
        {
            if (!visited.at(e))
            {
                pq.push(e);
            }
        }

        visited.at(current) = true;
    }

    rep(i, N)
    {
        if (i == N - 1)
        {
            cout << answer.at(i);
        }
        else
        {
            cout << answer.at(i) << ' ';
        }
    }

    cout << endl;

    return 0;
}
