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

int N;
vector<int> vec = {};

void f(int cnt)
{
    if (cnt == 1)
    {
        vec = {1};
        f(cnt + 1);
    }
    else if (cnt <= N)
    {
        vector<int> new_vec = {cnt};
        new_vec.insert(new_vec.begin(), vec.begin(), vec.end());
        new_vec.insert(new_vec.end(), vec.begin(), vec.end());

        vec = new_vec;

        f(cnt + 1);
    }
}

int main()
{
    init();

    cin >> N;

    f(1);

    for (auto const &v : vec)
    {
        cout << v << ' ';
    }

    cout << endl;

    return 0;
}
