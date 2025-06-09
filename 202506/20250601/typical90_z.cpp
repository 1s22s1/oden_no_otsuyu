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

    int N;
    cin >> N;

    vector<vector<int>> g(N);

    for (auto i : ranges::views::iota(0, N - 1))
    {
        int a, b;
        cin >> a >> b;

        g.at(a - 1).push_back(b - 1);
        g.at(b - 1).push_back(a - 1);
    }

    Graph graph(g);

    auto visited = graph.visited;

    vector<int> even, odd;

    for (auto i : ranges::views::iota(0, N - 1))
    {
        if (visited.at(i) % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }

    if (even.size() > odd.size())
    {
        for (auto e : even)
        {
            cout << e + 1 << ' ';
        }
    }
    else
    {
        for (auto e : odd)
        {
            cout << e + 1 << ' ';
        }
    }

    cout << endl;

    return 0;
}
