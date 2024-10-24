def longestNiceSubarray(nums):
    currMask = 0  # Tracks the OR of elements in the window
    i = 0  # Left pointer for the sliding window
    max_len = 0  # Maximum length of nice subarray

    for j in range(len(nums)):
        # While the AND of nums[j] with the current mask is not zero
        while (currMask & nums[j]) != 0:
            currMask ^= nums[i]  # Remove the element at i from the current mask
            i += 1  # Shrink the window from the left
        
        currMask |= nums[j]  # Add the new element to the current mask
        max_len = max(max_len, j - i + 1)  # Update the maximum length
    
    return max_len

# Example usage:
nums = [1, 3, 8, 48, 10]
print("Longest nice subarray length:", longestNiceSubarray(nums))
