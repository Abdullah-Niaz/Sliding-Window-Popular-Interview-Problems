#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int s_len = s.length(), p_len = p.length();
    if (p_len > s_len) return {};  // Edge case: if p is longer than s

    vector<int> p_count(26, 0), s_count(26, 0), result;

    // Initialize the frequency count for the first window and p
    for (int i = 0; i < p_len; i++) {
        p_count[p[i] - 'a']++;
        s_count[s[i] - 'a']++;
    }

    // Compare the first window
    if (p_count == s_count) result.push_back(0);

    // Start sliding the window
    for (int i = p_len; i < s_len; i++) {
        // Remove the character that is no longer in the window
        s_count[s[i - p_len] - 'a']--;
        // Add the new character that enters the window
        s_count[s[i] - 'a']++;

        // Compare the current window's character frequency with p's frequency
        if (p_count == s_count) {
            result.push_back(i - p_len + 1);
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> anagramIndices = findAnagrams(s, p);

    // Output the result
    for (int index : anagramIndices) {
        cout << index << " ";
    }
    return 0;
}
