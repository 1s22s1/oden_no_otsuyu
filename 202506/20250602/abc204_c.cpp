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

    Graph(vector<vector<int>> graph, int start = 0)
    {
        visited.assign(graph.size(), -1);

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
    }

    auto answer = 0;

    for (auto i : ranges::views::iota(0, N))
    {
        Graph graph(g, i);
        auto visited = graph.visited;

        answer += count_if(visited.begin(), visited.end(), [](int n)
                           { return n != -1; });
    }

    cout << answer << endl;

    return 0;
}
