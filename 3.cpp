#include <iostream>
#include <vector>
#include <algorithm>

void max_food_weight(int N, int M, std::vector<std::vector<int>> &matrix)
{
    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
    std::vector<std::vector<char>> steps(N, std::vector<char>(M, ' '));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
        steps[i][0] = 'D';
    }
    for (int j = 1; j < M; ++j)
    {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
        steps[0][j] = 'R';
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < M; ++j)
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                steps[i][j] = 'D';
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
                steps[i][j] = 'R';
            }
        }
    }
    std::cout << dp[N - 1][M - 1] << "\n";

    int i = N - 1, j = M - 1;
    std::vector<char> path;
    while (i > 0 || j > 0)
    {
        path.push_back(steps[i][j]);
        if (steps[i][j] == 'D')
            --i;
        else
            --j;
    }
    for (int k = path.size() - 1; k >= 0; --k)
    {
        std::cout << path[k] << " ";
    }
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
    max_food_weight(N, M, matrix);
    return 0;
}
