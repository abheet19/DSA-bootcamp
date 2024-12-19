#include <bits/stdc++.h>
using namespace std;

/*Example

Input : Student = [1, 2, 3] , Cookie = [1, 1]

Output :1

explanation : You have 3 students and 2 cookies.

he minimum size of cookies required for students are 1 , 2 ,3.

You have 2 cookies both of size 1, So you can assign the cookie only to student having minimum cookie size 1.

So your answer is 1.
*/

// Time Complexity = O(NlogN + MlogM + M)
// Space Complexity = O(1)

class Solution
{
public:
    int findMaximumCookieStudents(vector<int> &Student, vector<int> &Cookie)
    {
        sort(Student.begin(), Student.end()); // greed of each student
        sort(Cookie.begin(), Cookie.end());   // no. of cookies

        int cookieIdx = 0, studentIdx = 0;
        int contentChildren = 0; //    Result

        while (studentIdx < Student.size() and cookieIdx < Cookie.size())
        {
            if (Student[studentIdx] <= Cookie[cookieIdx])
            {
                contentChildren++;
                studentIdx++;
            }
            cookieIdx++;
        }
        return contentChildren;
    }
};

int main()
{
    // Example input
    vector<int> Student = {1, 2};
    vector<int> Cookie = {1, 1, 1};

    Solution solution;

    int result = solution.findMaximumCookieStudents(Student, Cookie);

    cout << "Number of students satisfied: " << result << endl;

    return 0;
}