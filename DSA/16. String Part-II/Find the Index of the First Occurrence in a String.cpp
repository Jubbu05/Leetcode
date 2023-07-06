// Using Brute Force naive Approach
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i <= m - n; i++)
        { // haystack

            for (int j = 0; j < n; j++)
            { // needle

                if (haystack[i + j] != needle[j])
                    break;

                //we have reached the end of needle
                if (j == n - 1)
                    return i;
            }
        }

        return -1;
    }
};

// KMP
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        if (n == 0)
            return 0;
            
        vector<int> lps(n, 0);
        int prev = 0;
        int i = 1;
        // LPS Array
        // first value of lps is always 0
        while (i < n)
        {
            if (needle[prev] == needle[i])
            {
                lps[i] = prev + 1;
                prev++;
                i++;
            }
            else
            {
                if (prev == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    prev = lps[prev - 1];
                }
            }
        }

        int y = 0; // pointer for haystack
        int z = 0; // pointer for needle

        while (y < m)
        {
            if (haystack[y] == needle[z])
            {
                y++;
                z++;
            }
            else
            {
                if (z == 0)
                {
                    y++;
                }
                else
                {
                    z = lps[z - 1];
                }
            }

            if (z == n)
            {
                return y - n;
            }
        }

        return -1;
    }
};