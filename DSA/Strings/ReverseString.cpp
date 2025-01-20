#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to reverse a string
    void reverseString(vector<char> &s)
    {
        stack<char> stack;

        // Push characters onto the stack
        for (char c : s)
        {
            stack.push(c);
        }

        // Pop characters from the stack to reverse the string
        for (int i = 0; i < s.size(); ++i)
        {
            s[i] = stack.top();
            stack.pop();
        }

        return;
    }

    void reverseStringOptimal(vector<char> &s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return;
    }
};

int main()
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};

    // Creating an instance of Solution class
    Solution sol;

    // Function call to reverse the string
    sol.reverseString(str);

    for (char c : str)
    {
        cout << c;
    }

    return 0;
}