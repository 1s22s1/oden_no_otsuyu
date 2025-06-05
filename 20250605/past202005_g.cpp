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

class MazeGraph
{
public:
    vector<vector<int>> visited;

    MazeGraph(vector<string> maze, vector<pair<int, int>> starts)
    {
        visited.assign(maze.size(), vector<int>(maze.at(0).size(), -1));

        queue<pair<int, int>> queue;
        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start.first).at(start.second) = 0;
        }

        vector<pair<int, int>> moves = {{1, 1}, {0, 1}, {-1, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!queue.empty())
        {
            auto current = queue.front();
            queue.pop();

            for (auto move : moves)
            {
                int next_x = current.first + move.first;
                int next_y = current.second + move.second;

                if (next_x < 0 || next_x >= maze.size() || next_y < 0 || next_y >= maze.at(0).size())
                {
                    continue;
                }

                if (maze.at(next_x).at(next_y) == '#')
                {
                    continue;
                }

                if (visited.at(next_x).at(next_y) != -1)
                {
                    continue;
                }

                queue.push({next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.first).at(current.second) + 1;
            }
        }
    }
};

int main()
{
    init();

    int N, X, Y;
    cin >> N >> X >> Y;

    auto max_range = 501;
    auto d = 250;

    vector<string> maze(max_range, string(max_range, '.'));
    for (auto _ : ranges::views::iota(0, N))
    {
        int x, y;
        cin >> x >> y;

        maze.at(x + d).at(y + d) = '#';
    }

    MazeGraph graph(maze, {{d, d}});

    cout << graph.visited.at(X + d).at(Y + d) << endl;

    return 0;
}
