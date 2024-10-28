#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    // if only 1 element, just return it
    if (nums.size() < 2) {
        return nums[0];
    }

    // Create array to store the maximum loot at each index
    vector<int> dp(nums.size());

    // memorize maximum loots at first 2 indexes
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // use them to fill complete array
    for (int i = 2; i < nums.size(); i++) {
        // core logic / formula to get the maximum loot
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};  // Sample input
    int max_loot = rob(nums);
    cout << "Maximum loot possible: " << max_loot << endl;
    return 0;
}
