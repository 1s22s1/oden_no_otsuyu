#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

using Graph = vector<vector<int>>;

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

vector<int> bfs(const vector<vector<int>> &G, int s)
{
    queue<int> que;
    vector<int> dist(G.size(), -1);

    dist.at(s) = 0;
    que.push(s);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (auto v2 : G.at(v))
        {
            if (dist.at(v2) != -1)
            {
                continue;
            }

            que.push(v2);
            dist.at(v2) = dist.at(v) + 1;
        }
    }

    return dist;
}

int main()
{
    init();

    int N, M;
    cin >> N >> M;

    Graph G(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    bfs(G, 0);

    vector<int> dist = bfs(G, 0);

    for (int i = 0; i <= *max_element(dist.begin(), dist.end()); i++)
    {
        vector<int> answers;

        for (int j = 0; j < dist.size(); j++)
        {
            if (dist.at(j) == i)
            {
                answers.push_back(j);
            }
        }

        sort(answers.begin(), answers.end());

        for (const auto &e : answers)
        {
            cout << e << ' ';
        }

        cout << endl;
    }

    return 0;
}
