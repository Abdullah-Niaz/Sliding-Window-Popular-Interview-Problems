#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k <= 1)
        {
            return 0;
        }

        int i = 0;     // Left pointer
        int count = 0; // To count the number of valid subarrays
        int prod = 1;  // To keep track of the product of the current window

        for (int j = 0; j < n; j++)
        {
            prod *= nums[j]; // Include nums[j] in the product

            // Shrink the window from the left until the product is less than k
            while (prod >= k && i <= j)
            {
                prod /= nums[i];
                i++;
            }

            // Count all subarrays ending at index j with start points from i to j
            count += (j - i + 1);
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int result = sol.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;
    return 0;
}
