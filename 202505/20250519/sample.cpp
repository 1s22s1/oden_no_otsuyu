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

    vector<int> vec = {1, 2, 3, 4, 5};

    do
    {
        for (const auto &e : vec)
        {
            cout << e << ' ';
        }

        cout << endl;

    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}
