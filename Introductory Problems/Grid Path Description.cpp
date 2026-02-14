#include <bits/stdc++.h>
using namespace std;

const int n = 7;
char s[n * n + 1];
int vis[n + 1][n + 1];
int ans = 0;

bool util(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n && !vis[x][y];
}

void dfs(int x, int y, int i)
{
    if (x == n && y == 1)
    {
        ans += (i == (n * n - 1));
        return;
    }

    if (i == n * n - 1)
        return;

    // bounding condition for the dfs call to return because these path
    // are feasible, very interesting case of hamiltonian paths as if don't
    // return from these path, the grid becomes disconnected and impossible
    // to complete the path
    if (!util(x + 1, y) && !util(x - 1, y))
        if (util(x, y - 1) && util(x, y + 1))
            return;
    if (!util(x, y + 1) && !util(x, y - 1))
        if (util(x + 1, y) && util(x - 1, y))
            return;

    vis[x][y] = 1;
    // these are the basic conditions for traversing the grid
    // if direction is down or unknown we will check for every possible
    // path through dfs while checking if the next cell is visited or not
    if ((s[i] == 'D' || s[i] == '?') && util(x + 1, y))
        dfs(x + 1, y, i + 1);
    if ((s[i] == 'U' || s[i] == '?') && util(x - 1, y))
        dfs(x - 1, y, i + 1);
    if ((s[i] == 'R' || s[i] == '?') && util(x, y + 1))
        dfs(x, y + 1, i + 1);
    if ((s[i] == 'L' || s[i] == '?') && util(x, y - 1))
        dfs(x, y - 1, i + 1);
    vis[x][y] = 0;
}
void solve()
{
    scanf("%s", s);
    dfs(1, 1, 0);
    printf("%d", ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}