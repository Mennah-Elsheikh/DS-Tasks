#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq_map; // to count the frequency of each element
        //[1 , 1 , 1 , 2 , 2 , 3 , 3 , 4] => [ 0 , 3 , 2 , 2 , 1]
        // the map => key - value => key=> index , value=> frequency
        vector<int> result; // the result vector that i will return
        for (auto &num : nums)
        { // like foreach => to iterate
            freq_map[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1); // why vector of vector => as may be there are more than one element with the same frequency :) that is the trick !
        // the idea is we will make the vector of vector
        // the index will be the frequency and we will store the numbers with this frequency in the vector
        // and we will return the vector with k frequency or bigger
        for (auto &[key, value] : freq_map)
        {                                 // iterate over the map with the key(index) and value(frequency)
            bucket[value].push_back(key); // push the index as the values of the bucket vector
            // the index of the bucket is the frequency of the element => the value of the freq_map
        }
        // this loop to return the vector of the elements of the k frequency or bigger
        for (int i = bucket.size() - 1; i >= 0; i--)
        { // in reverse order will be more fast !
            for (auto n : bucket[i])
            {
                if (k > 0)
                {
                    result.push_back(n);
                    k--;
                }
            }
        }
        return result;
    }
};
