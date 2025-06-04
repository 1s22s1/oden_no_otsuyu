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

    vector<int> visited(G.size(), -1);
    visited.at(0) = 0;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        for (int next : G.at(current))
        {
            if (visited.at(next) != -1)
            {
                continue;
            }

            queue.push(next);
            visited.at(next) = visited.at(current) + 1;
        }
    }

    return visited;
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

    vector<int> visited;
    visited = bfs(G);

    for (int i = 0; i <= *max_element(visited.begin(), visited.end()); i++)
    {
        for (int j = 0; j < visited.size(); j++)
        {
            if (visited.at(j) == i)
            {
                cout << j << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
