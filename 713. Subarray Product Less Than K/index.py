from typing import List

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k <= 1:
            return 0

        i = 0          # Left pointer
        count = 0      # To count the number of valid subarrays
        prod = 1       # To keep track of the product of the current window

        for j in range(n):
            prod *= nums[j]  # Include nums[j] in the product

            # Shrink the window from the left until the product is less than k
            while prod >= k and i <= j:
                prod //= nums[i]
                i += 1

            # Count all subarrays ending at index j with start points from i to j
            count += (j - i + 1)
        
        return count

sol = Solution()
nums = [10, 5, 2, 6]
k = 100
result = sol.numSubarrayProductLessThanK(nums, k)
print("Number of subarrays with product less than", k, ":", result)
