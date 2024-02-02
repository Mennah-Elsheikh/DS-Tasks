#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        // this way is big O(n^2)
        for (int i = 0; i < n; ++i)
        {
            int complement = target - nums[i];

            for (int j = i + 1; j < n; ++j)
            {
                if (nums[j] == complement)
                {

                    return {i, j};
                }
            }
        }
        return {};
    }
    // another way using unordered_map => O(n) it is amazing *_*
    //  int n = nums.size();
    //      unordered_map<int, int> mp; // val -> index

    //     for (int i = 0; i < n; i++) {
    //         int complement = target - nums[i];
    //         if (mp.find(complement) != mp.end()) {
    //             return {mp[complement], i};
    //         }
    //         mp.insert({nums[i], i});
    //     }
    //     return {};
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target;
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
