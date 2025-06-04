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
vector<int> vec;

void f(int count)
{
    if (count == 1)
    {
        vec = {1};
        f(count + 1);
    }
    else if (count <= N)
    {
        vector<int> tmp_vec = {count};
        tmp_vec.insert(tmp_vec.begin(), vec.begin(), vec.end());
        tmp_vec.insert(tmp_vec.end(), vec.begin(), vec.end());

        vec = tmp_vec;

        f(count + 1);
    }
}

int main()
{
    init();

    cin >> N;
    f(1);

    for (const auto &v : vec)
    {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}
