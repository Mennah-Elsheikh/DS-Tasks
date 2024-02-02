#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        return sortedString(s) == sortedString(t);
    }

private:
    string sortedString(const string &str)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        return sortedStr;
    }
};
int main()
{
    Solution solution;
    string s, t;
    cin >> s >> t;
    if (solution.isAnagram(s, t))
        cout << "is valid " << endl;
    cout << "not valid" << endl;
    return 0;
}
