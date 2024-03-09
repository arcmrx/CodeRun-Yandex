#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string input1, input2, result;
    int count = 0;
    getline(std::cin, input1);
    getline(std::cin, input2);
    std::sort(begin(input1), end(input1));
    input1.erase(std::unique(begin(input1), end(input1)), end(input1));
    for (int i = 0; i != input1.size(); i++)
    {
        for (int j = 0; j != input2.size(); j++)
        {
            if (input1[i] == input2[j])
            {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}