#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0;
    int current_sum = 0;
    int min_length = INT_MAX;

    for (int right = 0; right < nums.size(); ++right)
    {
        current_sum += nums[right];

        while (current_sum >= target)
        {
            min_length = min(min_length, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    return (min_length == INT_MAX) ? 0 : min_length;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayLen(target, nums);
    cout << "The minimal length of the subarray: " << result << endl;

    return 0;
}
