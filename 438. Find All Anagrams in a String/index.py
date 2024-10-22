from collections import Counter


def findAnagrams(s: str, p: str):
    # Initialize variables
    p_len = len(p)
    s_len = len(s)

    # Edge case: if p is longer than s, return empty list
    if p_len > s_len:
        return []

    # Frequency count of p
    p_count = Counter(p)
    # Frequency count of the first window of s
    s_count = Counter(s[:p_len])

    # Result array to store starting indices of anagrams
    result = []

    # Check the first window
    if s_count == p_count:
        result.append(0)

    # Start sliding the window
    for i in range(p_len, s_len):
        # Remove the character going out of the window
        s_count[s[i - p_len]] -= 1
        if s_count[s[i - p_len]] == 0:
            del s_count[s[i - p_len]]

        # Add the new character coming into the window
        s_count[s[i]] += 1

        # Compare the new window's character count with p's character count
        if s_count == p_count:
            result.append(i - p_len + 1)

    return result


print(findAnagrams("cbaebabacd", "abc"))  # Output: [0, 6]
print(findAnagrams("abab", "ab"))         # Output: [0, 1, 2]
