#include <iostream>
#include <vector>
using namespace std;

const int PRIME = 101; // A prime number for hashing

vector<int> rabinKarp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> result;

    if (m > n)
    return result;

    long long patternHash = 0, textHash = 0, h = 1;

    // The value of h would be "pow(d, m-1)%q"
    for (int i = 0; i < m - 1; i++)
        h = (h * 256) % PRIME;

    // Calculate hash value for pattern and first window of text
    for (int i = 0; i < m; i++)
    {
        patternHash = (256 * patternHash + pattern[i]) % PRIME;
        textHash = (256 * textHash + text[i]) % PRIME;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // Check the hash values of current window of text and pattern
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                result.push_back(i);
        }

        // Calculate hash value for next window of text:
        if (i < n - m)
        {
            textHash = (256 * (textHash - text[i] * h) + text[i + m]) % PRIME;

            // Make sure hash is positive
            if (textHash < 0)
                textHash += PRIME;
        }
    }

    return result;
}

int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> positions = rabinKarp(text, pattern);

    if (positions.empty())
        cout << "Pattern not found" << endl;
    else
    {
        cout << "Pattern found at indices: ";
        for (int pos : positions)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
