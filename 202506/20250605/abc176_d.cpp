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

        deque<pair<int, int>> deque;
        for (auto start : starts)
        {
            deque.push(start);
            visited.at(start.first).at(start.second) = 0;
        }

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!deque.empty())
        {
            auto current = deque.front();
            deque.pop();

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

                deque.push({next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.first).at(current.second) + 1;
            }
        }
    }
};

int main()
{
    init();

    int H, W, Ch, Cw, Dh, Dw;
    cin >> H >> W >> Ch >> Cw >> Dh >> Dw;

    vector<string> maze(H);
    for (auto i : ranges::views::iota(0, H))
    {
        cin >> maze.at(i);
    }

    return 0;
}
