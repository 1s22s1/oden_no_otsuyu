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

    set<string> s;

    for (auto i : ranges::views::iota(0, N))
    {
        string t;
        cin >> t;

        s.insert(t);
    }

    cout << s.size() << endl;

    return 0;
}
