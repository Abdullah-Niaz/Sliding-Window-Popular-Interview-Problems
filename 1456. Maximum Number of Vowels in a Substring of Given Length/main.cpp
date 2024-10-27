#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int maxVowels(string s, int k)
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int max_vowel_count = 0, current_vowel_count = 0;

    // Initialize the vowel count for the first `k`-length substring
    for (int i = 0; i < k; ++i)
    {
        if (vowels.count(s[i]))
        {
            current_vowel_count++;
        }
    }

    max_vowel_count = current_vowel_count;

    // Slide the window across the string
    for (int i = k; i < s.size(); ++i)
    {
        // Add the next character in the window
        if (vowels.count(s[i]))
        {
            current_vowel_count++;
        }
        // Remove the character that is no longer in the window
        if (vowels.count(s[i - k]))
        {
            current_vowel_count--;
        }

        // Update the maximum vowel count
        max_vowel_count = max(max_vowel_count, current_vowel_count);
    }

    return max_vowel_count;
}

int main()
{
    string s = "abciiidef";
    int k = 3;
    cout << "Maximum number of vowels in any substring of length " << k << ": " << maxVowels(s, k) << endl;
    return 0;
}
