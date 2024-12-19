#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;  // Counter for $5
        int ten = 0;   // Counter for $10

        for (int bill : bills)  // Iterate through each customer's bill
        {
            if (bill == 5)  /* If the customer's bill is $5 */
            {
                five++;
            }
            else if (bill == 10)    /* If the customer's bill is $10 */
            {
                if (five == 0)      
                {
                    return false;  /* If no $5 bill available, return false */
                }
                five--;
                ten++;
            }
            else
            { // bill == 20                 /* If the customer's bill is $20 */
                if (ten > 0 && five > 0)    /* If both $10 and $5 bills are available */
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)         /* If only $5 bills are available */
                {
                    five -= 3;
                }
                else
                {
                    return false;           /* If unable to give change, return false */
                }
            }
        }
        return true; //all customers get change
    }
};

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for (int bill : bills)
    {
        cout << bill << " ";
    }
    cout << endl;
    Solution solution;
    bool ans = solution.lemonadeChange(bills);
    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}