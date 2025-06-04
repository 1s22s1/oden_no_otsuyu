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

    Graph(vector<vector<int>> g)
    {
        visited.assign(g.size(), -1);

        queue<int> queue;
        queue.push(0);

        visited.at(0) = 0;

        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();

            for (int next : g.at(current))
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

    return 0;
}
