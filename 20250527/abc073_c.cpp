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

    int N;
    cin >> N;

    map<int, int> m;

    for (auto _ : ranges::views::iota(0, N))
    {
        int a;
        cin >> a;

        m[a]++;
    }

    int answer = 0;

    for (const auto [key, value] : m)
    {
        if (value % 2 == 1)
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
