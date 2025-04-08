#include <bits/stdc++.h>
using namespace std;

// Preprocess the pattern to build the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(const string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m);
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0  
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // Try to shorten the current prefix
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP search function to find all occurrences of pattern in text
vector<int> KMP(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern);
    vector<int> matches;

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            matches.push_back(i - j); // Match found at index (i - j)
            j = lps[j - 1];           // Continue searching for next match
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // Use the LPS array to avoid unnecessary comparisons
            }
            else
            {
                i++;
            }
        }
    }

    return matches;
}

// Example usage
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> matchPositions = KMP(text, pattern);

    for (int pos : matchPositions)
    {
        cout << "Pattern found at index " << pos << endl;
    }

    return 0;
}
