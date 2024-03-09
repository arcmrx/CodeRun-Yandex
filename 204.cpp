#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main()
{
    int count, number1, number2, str, sum = 0;
    std::cin >> count;
    std::vector<int> sumstrs;
    std::vector<std::vector<int>> matrix(count, std::vector<int>(2));
    str = count;
    while (str != 0)
    {
        std::cin >> number1 >> number2;
        matrix[str - 1][0] = number1;
        matrix[str - 1][1] = number2;
        --str;
    }
    for (size_t i = 0; i != count; ++i)
    {
        sumstrs.push_back(matrix[i][0] * matrix[i][1]);
        sum += sumstrs[i];
    }
    for (size_t i = count - 1; i != -1; --i)
    {
        std::cout << std::setprecision(12) << (sumstrs[i] * 1.0) / sum << "\n";
    }
    return 0;
}