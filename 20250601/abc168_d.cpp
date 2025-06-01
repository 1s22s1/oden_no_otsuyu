#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

class Graph
{

public:
    vector<int> visited;
    vector<int> previous;

    Graph(vector<vector<int>> graph, int start = 0)
    {
        visited.assign(graph.size(), -1);
        previous.assign(graph.size(), -1);

        queue<int> queue;
        queue.push(start);

        visited.at(start) = 0;

        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();

            for (int next : graph.at(current))
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
    }
};

int main()
{
    init();

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);

    for (auto _ : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;

        g.at(a - 1).push_back(b - 1);
        g.at(b - 1).push_back(a - 1);
    }

    Graph graph(g);

    auto previous = graph.previous;

    cout << "Yes" << endl;
    for (auto i : ranges::views::iota(1, N))
    {
        cout << previous.at(i) + 1 << endl;
    }

    return 0;
}
