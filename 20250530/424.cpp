#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

using Graph = vector<vector<int>>;

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

int main()
{
    init();

    int H, W;
    int X0, Y0, X1, Y1;

    cin >> H >> W >> X0 >> Y0 >> X1 >> Y1;

    vector<string> S(H);

    for (auto &row : S)
    {
        cin >> row;
    }

    queue<pair<int, int>> queue;
    vector<vector<int>> visited(H, vector<int>(W, -1));

    queue.push({X0, Y0});
    visited.at(X0).at(Y0) = 0;

    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!queue.empty())
    {
        pair<int, int> cur = queue.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        queue.pop();

        for (auto move : moves)
        {
            int next_x = cur_x + move.first;
            int next_y = cur_y + move.second;

            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W)
            {
                continue;
            }

            if (S.at(next_x).at(next_y) == 'B')
            {
                continue;
            }

            if (visited.at(next_x).at(next_y) != -1)
            {
                continue;
            }

            queue.push({next_x, next_y});
            visited.at(next_x).at(next_y) = visited.at(cur_x).at(cur_y) + 1;
        }
    }

    cout << visited.at(X1).at(Y1) << endl;

    return 0;
}
