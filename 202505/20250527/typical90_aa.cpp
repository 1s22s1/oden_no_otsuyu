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
    set<string> s;

    cin >> N;

    for (auto i : ranges::views::iota(0, N))
    {
        string name;
        cin >> name;

        if (s.contains(name))
        {
            // Do nothing
        }
        else
        {
            cout << i + 1 << endl;

            s.insert(name);
        }
    }

    return 0;
}
