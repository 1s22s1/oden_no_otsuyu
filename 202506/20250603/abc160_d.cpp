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

    int N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<int>> g(N);

    for (auto i : ranges::views::iota(0, N - 1))
    {
        g.at(i).push_back(i + 1);
        g.at(i + 1).push_back(i);
    }

    g.at(X - 1).push_back(Y - 1);
    g.at(Y - 1).push_back(X - 1);

    map<int, int> answer;

    for (auto i : ranges::views::iota(0, N))
    {
        Graph graph(g, i);
        auto visited = graph.visited;

        for (auto j : ranges::views::iota(0, N))
        {
            answer[abs(visited.at(i) - visited.at(j))]++;
        }
    }

    for (auto i : ranges::views::iota(1, N))
    {
        cout << answer[i] / 2 << endl;
    }

    return 0;
}
