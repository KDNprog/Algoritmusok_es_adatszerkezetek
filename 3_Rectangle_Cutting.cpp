#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int A, B;
    cin >> A >> B;

    vector<vector<int>> dp(A + 1, vector<int>(B + 1, INF));

    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            if (i == j)
                dp[i][j] = 0;
        }
    }

    for (int a = 1; a <= A; a++)
    {
        for (int b = 1; b <= B; b++)
        {
            if (a == b)
                continue;

            for (int i = 1; i < a; i++)
            {
                dp[a][b] = min(dp[a][b], dp[i][b] + dp[a - i][b] + 1);
            }

            for (int i = 1; i < b; i++)
            {
                dp[a][b] = min(dp[a][b], dp[a][i] + dp[a][b - i] + 1);
            }
        }
    }

    cout << dp[A][B] << endl;

    return 0;
}