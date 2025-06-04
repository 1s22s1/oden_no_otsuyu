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

    map<string, int> m;

    for (auto _ : ranges::views::iota(0, N))
    {
        string s;
        cin >> s;

        m[s]++;
    }

    auto max_it = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
                              { return a.second < b.second; });

    vector<string> names;

    for (const auto &e : m)
    {
        if (e.second == max_it->second)
        {
            names.push_back(e.first);
        }
    }

    sort(names.begin(), names.end());

    for (const auto &name : names)
    {
        cout << name << endl;
    }

    return 0;
}
