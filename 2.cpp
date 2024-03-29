#include <iostream>
#include <vector>
#include <algorithm>

int min_food_weight(int N, int M, std::vector<std::vector<int>> &matrix)
{
    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }
    for (int j = 1; j < M; ++j)
    {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < M; ++j)
        {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }
    std::cout << "\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    return dp[N - 1][M - 1];
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << min_food_weight(N, M, matrix);
    return 0;
}
