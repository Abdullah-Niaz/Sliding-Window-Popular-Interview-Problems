def maxVowels(s: str, k: int) -> int:
    vowels = {'a', 'e', 'i', 'o', 'u'}
    max_vowel_count = 0
    current_vowel_count = 0

    # Initialize the count of vowels in the first k-length substring
    for i in range(k):
        if s[i] in vowels:
            current_vowel_count += 1

    max_vowel_count = current_vowel_count

    # Slide the window across the string
    for i in range(k, len(s)):
        # Add the next character in the window
        if s[i] in vowels:
            current_vowel_count += 1
        # Remove the character that is no longer in the window
        if s[i - k] in vowels:
            current_vowel_count -= 1

        # Update the maximum vowel count
        max_vowel_count = max(max_vowel_count, current_vowel_count)

    return max_vowel_count


# Example usage:
s = "abciiidef"
k = 3
print("Maximum number of vowels in any substring of length", k, ":", maxVowels(s, k))
