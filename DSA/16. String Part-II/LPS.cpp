vector<int> computeLPS(string p, int n)
{
    int i = 1;
    int len = 0;
    vector<int> lps(n, 0);

    // Dry run for  pattern = "abcabcd", then you will understand clearly how we will create "LPS" array
    // pattern   ----------> a b c a b c d
    // "lps" array comes --> 0 0 0 1 2 3 0
    while (i < n)
    {
        if (p[i] == p[len])
        {
            lps[i] = len + 1;
            len++;
            i++
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
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