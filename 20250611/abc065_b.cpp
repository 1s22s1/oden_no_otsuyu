#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

class LinearGraph
{

public:
    vector<int> visited;
    vector<int> previous;

    LinearGraph(vector<vector<int>> graph, int start = 0)
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

    int N;
    cin >> N;

    vector<vector<int>> g(N);

    rep(i, N)
    {
        int a;
        cin >> a;

        g.at(i).push_back(a - 1);
    }

    LinearGraph graph(g);
    auto visited = graph.visited;

    cout << visited.at(1) << endl;

    return 0;
}
