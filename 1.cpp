#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers{};
    int number;
    for(size_t i = 0; i != 3; ++i)
    {
        std::cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    std::cout << numbers[1];
}