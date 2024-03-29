#include <iostream>
#include <vector>

int countPaths(int N, int M)
{
    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (i + 1 < N && j + 2 < M)
                dp[i + 1][j + 2] += dp[i][j];
            if (i + 2 < N && j + 1 < M)
                dp[i + 2][j + 1] += dp[i][j];
        }
    }
    return dp[N - 1][M - 1];
}
int main()
{
    int N, M;
    std::cin >> N >> M;
    std::cout << countPaths(N, M);
    return 0;
}