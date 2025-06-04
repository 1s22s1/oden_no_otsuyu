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

vector<int> bfs(Graph G)
{
    queue<int> queue;
    queue.push(0);

    vector<int> visit(G.size(), -1);
    visit.at(0) = 0;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        for (int next : G.at(current))
        {
            if (visit.at(next) != -1)
            {
                continue;
            }

            queue.push(next);
            visit.at(next) = visit.at(current) + 1;
        }
    }

    return visit;
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

    vector<int> visit;
    visit = bfs(G);

    auto max_it = *max_element(visit.begin(), visit.end());

    cout << max_it << endl;

    return 0;
}
