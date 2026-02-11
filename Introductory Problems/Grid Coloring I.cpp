#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    string colors = "ABCD";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (char c : colors)
            {
                bool ok = true;

                if (i > 0 && grid[i - 1][j] == c)
                    ok = false;
                if (j > 0 && grid[i][j - 1] == c)
                    ok = false;
                if (ok && grid[i][j] != c)
                {
                    grid[i][j] = c;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << "\n";
    }

    return 0;
}
