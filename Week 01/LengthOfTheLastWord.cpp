#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lengthOftheLastWord(string s)
    {

        reverse(s.begin(), s.end());

        int count = 0;

        while (s[count] == ' ')
        {
            count++;
        }

        const int firstIndex = count;

        while (s[count] != ' ' && s[count] != '\0')
        {
            count++;
        }

        return count - firstIndex;
        // the leetcode solution => as the same idea but he started from the last index
        // his code is very simple :)
        // int length = 0;
        // int i = s.length() - 1;

        // while (i >= 0 && s[i] == ' ')
        // {
        //     i--;
        // }

        // while (i >= 0 && s[i] != ' ')
        // {
        //     length++;
        //     i--;
        // }

        // return length;
    }
};

int main()
{
    Solution solution;
    // leet code examolples
    string input1 = "Hello World";
    string input2 = "   fly me   to   the moon  ";
    string input3 = "luffy is still joyboy";

    cout << "Example 1: " << solution.lengthOftheLastWord(input1) << endl; // Output: 5
    cout << "Example 2: " << solution.lengthOftheLastWord(input2) << endl; // Output: 4
    cout << "Example 3: " << solution.lengthOftheLastWord(input3) << endl; // Output: 6

    return 0;
}
