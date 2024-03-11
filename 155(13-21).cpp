#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0, number = 0, size1 = 0, size2 = 0;
    std::cin >> count;
    int individ1 = count;
    int individ2 = count;
    std::vector<int> numbers;
    for (size_t i = 0; i < count; ++i)
    {
        std::cin >> number;
        numbers.push_back(number);
    }
    std::sort(numbers.begin(), numbers.end());
    for (size_t i = 0; i < count - 1; ++i)
    {
        if (numbers[i] == numbers[i + 1])
        {
            individ1--;
        }
    }
    if (individ1 == individ2)
    {
        std::cout << individ1;
    }
    else
    {
        std::cout << (individ1 - 1);
    }
    return 0;
}