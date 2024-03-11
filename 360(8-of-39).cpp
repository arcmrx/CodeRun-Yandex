#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int find_largest_repeating_number(int n, vector<int> &a)
{
    unordered_map<int, int> count_map;
    int max_count = 0;
    int max_number = 0;

    for (int i = 0; i < n; i++)
    {
        count_map[a[i]]++;
        if (count_map[a[i]] > max_count)
        {
            max_count = count_map[a[i]];
            max_number = a[i];
        }
    }

    return max_number;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = find_largest_repeating_number(n, a);
    cout << result << endl;

    return 0;
}