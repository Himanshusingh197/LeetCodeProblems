#include <bits/stdc++.h>
using namespace std;

int getValue(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(string s)
{
    int total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int current = getValue(s[i]);
        if (i + 1 < s.length())
        {
            int next = getValue(s[i + 1]);
            if (current < next)
            {
                total -= current;
            }
            else
            {
                total += current;
            }
        }
        else
        {
            total += current;
        }
    }
    return total;
}

int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;

    return 0;
}