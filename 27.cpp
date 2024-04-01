#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main() 
{
    int n;
    std:: cin >> n;
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                {
                    if(j * j * j <= i)
                    {
                        dp[i] = std::min(dp[i], dp[i - j * j * j] + 1);
                    }
                    else
                    {
                        break;
                    }
                }
        }
    std::cout << dp[n];
	return 0;
}