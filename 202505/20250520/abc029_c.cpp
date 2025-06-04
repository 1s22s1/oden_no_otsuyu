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

void f(int rest, string s)
{
    if (rest == 0)
    {
        cout << s << endl;
    }
    else
    {
        for (char c = 'a'; c <= 'c'; c++)
        {
            f(rest - 1, s + c);
        }
    }
}

int main()
{
    init();

    int N;
    cin >> N;

    f(N, "");

    return 0;
}
