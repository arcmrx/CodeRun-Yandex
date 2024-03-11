#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n, m, countW, countB;
    std::string color;
    std::cin >> m >> n;
    std::vector<std::vector<char>> matrix(m, std::vector<char>(n));
    for (size_t i = 0; i != m; ++i) // строки
    {
        for (size_t j = 0; j != n; ++j) // столбцы
        {
            matrix[i][j] = '-';
        }
    }

    std::cin >> countW;
    for (int i = 0; i != countW; i++)
    {
        int x, y;
        std::cin >> x >> y;
        matrix[x - 1][y - 1] = 'W';
    }

    std::cin >> countB;
    for (int i = 0; i != countB; i++)
    {
        int x, y;
        std::cin >> x >> y;
        matrix[x - 1][y - 1] = 'B';
    }

    std::cin >> color;

    if (color == "white")
    {
        for (size_t i = 0; i != m; ++i) // строки
        {
            for (size_t j = 0; j != n; ++j) // столбцы
            {
                if (matrix[i][j] == 'W' and matrix[i + 1][j + 1] == 'B' and matrix[i + 2][j + 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'W' and matrix[i + 1][j - 1] == 'B' and matrix[i + 2][j - 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'W' and matrix[i - 1][j - 1] == 'B' and matrix[i - 2][j - 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'W' and matrix[i - 1][j + 1] == 'B' and matrix[i - 2][j + 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else
                {
                    std::cout << "No";
                    return 0;
                }
            }
        }
    }
    if (color == "black")
    {
        for (size_t i = 0; i != (m - 2); ++i) // строки
        {
            for (size_t j = 0; j != (n - 2); ++j) // столбцы
            {
                if (matrix[i][j] == 'B' and matrix[i + 1][j + 1] == 'W' and matrix[i + 2][j + 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'B' and matrix[i + 1][j - 1] == 'W' and matrix[i + 2][j - 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'B' and matrix[i - 1][j - 1] == 'W' and matrix[i - 2][j - 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else if (matrix[i][j] == 'B' and matrix[i - 1][j + 1] == 'W' and matrix[i - 2][j + 2] == '-')
                {
                    std::cout << "Yes";
                    return 0;
                }
                else
                {
                    std::cout << "No";
                    return 0;
                }
            }
        }
    }
    return 0;
}