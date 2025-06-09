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

    MazeGraph(vector<string> maze, pair<int, int> start)
    {
        visited.assign(maze.size(), vector<int>(maze.at(0).size(), -1));

        queue<pair<int, int>> queue;
        queue.push(start);

        visited.at(start.first).at(start.second) = 0;

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
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

    int H, W;
    cin >> H >> W;

    vector<string> maze;
    for (auto _ : ranges::views::iota(0, H))
    {
        string row;
        cin >> row;

        maze.push_back(row);
    }

    auto answer = 0;

    for (auto i : ranges::views::iota(0, H))
    {
        for (auto j : ranges::views::iota(0, W))
        {
            if (maze.at(i).at(j) == '.')
            {
                MazeGraph graph(maze, {i, j});
                auto visited = graph.visited;

                for (auto row : visited)
                {
                    auto max_it = *max_element(row.begin(), row.end());
                    answer = max(max_it, answer);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
