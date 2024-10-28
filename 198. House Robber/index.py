def rob(nums):
    # if only 1 element, just return it
    if len(nums) < 2:
        return nums[0]

    # Create array to store the maximum loot at each index
    dp = [0] * len(nums)

    # memorize maximum loots at first 2 indexes
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    # use them to fill complete array
    for i in range(2, len(nums)):
        # core logic / formula to get the maximum loot
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    return dp[len(nums) - 1]


# Main function to test the code
if __name__ == "__main__":
    nums = [2, 7, 9, 3, 1]  # Sample input
    max_loot = rob(nums)
    print("Maximum loot possible:", max_loot)
