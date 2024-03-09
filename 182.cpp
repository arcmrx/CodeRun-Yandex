#include <iostream>
#include <vector>
#include <sstream>

unsigned long long total_prime_factors(unsigned long long n)
{
    unsigned long long count = 0;
    unsigned long long temp = n;
    if (temp % 2 == 0)
    {
        count += 1;
        while (temp % 2 == 0)
        {
            temp /= 2;
        }
    }
    unsigned long long i = 3;
    while (i * i <= temp)
    {
        if (temp % i == 0)
        {
            count += 1;
            while (temp % i == 0)
            {
                temp /= i;
            }
        }
        i += 2;
    }
    if (temp > 2)
    {
        count += 1;
    }
    return count;
}

unsigned long long count_pairs(unsigned long long g, unsigned long long l)
{
    if (l % g != 0)
    {
        return 0;
    }
    else
    {
        return 1 << total_prime_factors(l / g);
    }
}

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<unsigned long long> numbers;
    unsigned long long num;
    while (iss >> num)
    {
        numbers.push_back(num);
    }
    unsigned long long g = numbers[0];
    unsigned long long l = numbers[1];
    unsigned long long result = count_pairs(g, l);
    std::cout << result << std::endl;
    return 0;
}