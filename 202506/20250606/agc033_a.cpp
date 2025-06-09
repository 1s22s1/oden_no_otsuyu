#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

class Point
{
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class MazeGraph
{
public:
    vector<vector<int>> visited;

    MazeGraph(vector<string> maze, vector<Point> starts, char wall = '#')
    {
        visited.assign(maze.size(), vector<int>(maze.at(0).size(), -1));

        queue<Point> queue;
        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start.x).at(start.y) = 0;
        }

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!queue.empty())
        {
            auto current = queue.front();
            queue.pop();

            for (auto move : moves)
            {
                int next_x = current.x + move.first;
                int next_y = current.y + move.second;

                if (next_x < 0 || next_x >= maze.size() || next_y < 0 || next_y >= maze.at(0).size())
                {
                    continue;
                }

                if (maze.at(next_x).at(next_y) == wall)
                {
                    continue;
                }

                if (visited.at(next_x).at(next_y) != -1)
                {
                    continue;
                }

                queue.push(Point{next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.x).at(current.y) + 1;
            }
        }
    }
};

int main()
{
    init();

    int H, W;
    cin >> H >> W;

    vector<string> maze(H);

    rep(i, H)
    {
        cin >> maze.at(i);
    }

    vector<Point> starts;
    rep(i, H)
    {
        rep(j, W)
        {
            if (maze.at(i).at(j) == '#')
            {
                starts.push_back(Point({i, j}));
            }
        }
    }

    MazeGraph graph(maze, starts);
    auto visited = graph.visited;

    auto answer = 0;
    for (auto row : visited)
    {
        answer = max(answer, *max_element(row.begin(), row.end()));
    }

    cout << answer << endl;

    return 0;
}
