#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

using Graph = vector<vector<int>>;

vector<int> bfs(Graph G)
{
    queue<int> queue;
    queue.push(0);

    vector<int> visited(G.size(), -1);
    vector<int> previous(G.size(), -1);
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
            previous.at(next) = current;
        }
    }

    return previous;
}

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
    cin >> N >> M;

    Graph G(N);

    for (auto _ : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;

        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    vector<int> previous;
    previous = bfs(G);

    if (!all_of(previous.begin(), previous.end(), [](int n)
                { return n != -1; }))
    {
        cout << "Yes" << endl;

        for (auto i : ranges::views::iota(1, N))
        {
            cout << previous.at(i) + 1 << endl;
        }
    }
    else
    {
    }

    return 0;
}
