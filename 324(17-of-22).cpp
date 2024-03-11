#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int countb, counts, buy = 0, sell = 0, sum = 0;
    std::cin >> countb >> counts;
    std::vector<int> buys;
    std::vector<int> sells;

    for (int i = 0; i != countb; i++)
    {
        std::cin >> buy;
        buys.push_back(buy);
    }

    for (int j = 0; j != counts; j++)
    {
        std::cin >> sell;
        sells.push_back(sell);
    }

    sort(buys.begin(), buys.end());
    sort(sells.rbegin(), sells.rend());

    for (int k = 0; k != std::min(countb, counts); k++)
    {
        if (sells[k] - buys[k] >= 0)
        {
            sum += sells[k] - buys[k];
        }
    }
    std::cout << sum;

    return 0;
}