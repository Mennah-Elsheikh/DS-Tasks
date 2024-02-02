#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramGroups;
        // the idea of using map is => we will make the key of it is the sorted string
        // and the values is the vector og all anagrams of this string

        for (const string &str : strs)
        {
            string sortedStr = str; // This sorted string will be used as the key in the unordered map.
            sort(sortedStr.begin(), sortedStr.end());

            anagramGroups[sortedStr].push_back(str);
            // add the original unsorted string to the corresponding vector in the map
            // that is the trick here
            // This way is close to the idea of Hash Collision !
        }

        vector<vector<string>> result;
        for (const auto &group : anagramGroups)
        {
            result.push_back(group.second); // as the values of the map is the vector of strings
        }
        // iterating over the map and pushing the vectors of anagrams into the result
        return result;
    }
};