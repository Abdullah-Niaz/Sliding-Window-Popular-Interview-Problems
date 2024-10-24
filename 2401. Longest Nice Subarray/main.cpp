#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int currMask = 0; // Tracks the OR of elements in the window
        int i = 0;        // Left pointer for the sliding window
        int max_len = 0;  // Maximum length of the nice subarray

        for (int j = 0; j < nums.size(); ++j)
        {
            // While the AND of nums[j] with the current mask is not zero
            while ((currMask & nums[j]) != 0)
            {
                currMask ^= nums[i]; // Remove the element at i from the current mask
                ++i;                 // Shrink the window from the left
            }

            currMask |= nums[j];               // Add the new element to the current mask
            max_len = max(max_len, j - i + 1); // Update the maximum length
        }

        return max_len;
    }
};

int main()
{
    vector<int> nums = {1, 3, 8, 48, 10};
    Solution sol;
    cout << "Longest nice subarray length: " << sol.longestNiceSubarray(nums) << endl;
    return 0;
}
