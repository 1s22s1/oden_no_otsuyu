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

                if (maze.at(next_x).at(next_y) == 'X')
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

pair<int, int> find_position(vector<string> maze, char c)
{
    rep(i, maze.size())
    {
        rep(j, maze.at(0).size())
        {
            if (maze.at(i).at(j) == c)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    init();

    int H, W, N;
    cin >> H >> W >> N;

    vector<string> maze(H);
    rep(i, H)
    {
        cin >> maze.at(i);
    }

    auto from = find_position(maze, 'S');
    auto answer = 0;
    rep(i, N)
    {
        MazeGraph graph(maze, {from});
        auto to = find_position(maze, i + 1 + '0');

        answer += graph.visited.at(to.first).at(to.second);
        from = to;
    }

    cout << answer << endl;

    return 0;
}
