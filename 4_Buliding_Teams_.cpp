#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5 + 1;

int N, M;
bool possible = true;
vector<int> G[maxN];
int team[maxN];

void dfs(int u, int t)
{
    team[u] = t;
    for (int v : G[u])
    {
        if (team[v] == 0)
        {
            dfs(v, 3 - t);
        }
        else if (team[v] == t)
        {
            possible = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (team[i] == 0)
        {
            dfs(i, 1);
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            cout << team[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
