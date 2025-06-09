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

    vector<pair<int, int>> ab;
    for (auto i : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;
        ab.push_back({a, b});
    }

    int answer = 0;

    for (auto i : ranges::views::iota(0, M))
    {
        vector<vector<int>> g(N);
        for (auto j : ranges::views::iota(0, M))
        {
            if (i != j)
            {
                g.at(ab.at(j).first - 1).push_back(ab.at(j).second - 1);
                g.at(ab.at(j).second - 1).push_back(ab.at(j).first - 1);
            }
        }

        Graph graph(g);
        auto visited = graph.visited;

        if (any_of(visited.begin(), visited.end(), [](int n)
                   { return n == -1; }))
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
