/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;  // To store the element and its index
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // If the complement exists in the map, return the result
        if (num_map.find(complement) != num_map.end()) {
            result.push_back(num_map[complement]);
            result.push_back(i);
            return result;
        }

        // If the complement doesn't exist, store the current element with its index
        num_map[nums[i]] = i;
    }

    return result;  // Although we assume there is always one solution, this is a fallback
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    // Output the result
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
