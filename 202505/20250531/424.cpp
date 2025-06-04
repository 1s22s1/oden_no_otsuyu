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

int main()
{
    init();

    int H, W, X0, Y0, X1, Y1;
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

    while (!queue.empty())
    {
        pair<int, int> t = queue.front();
        int current_x = t.first;
        int current_y = t.second;
        queue.pop();

        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto move : moves)
        {
            int next_x = current_x + move.first;
            int next_y = current_y + move.second;

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
            visited.at(next_x).at(next_y) = visited.at(current_x).at(current_y) + 1;
        }
    }

    cout << visited.at(X1).at(Y1) << endl;

    return 0;
}
