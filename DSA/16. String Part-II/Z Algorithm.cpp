vector<int> computeLPS(string p, int n)
{
    int i = 1, len = 0;
    vector<int> lps(n, 0);
    while (i < n)
    {
        if (p[i] == p[len])
        {
            lps[i] = len + 1;
			len++;
            i++;
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
int KMP(string s, string p)
{
    int n = s.size(), m = p.size(), i = 0, j = 0, count = 0;
    vector<int> lps = computeLPS(p, m);
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m)
        {
            count++;
            j = lps[j - 1];
        }
    }
    return count;
}
int zAlgorithm(string s, string p, int n, int m)
{
    return KMP(s, p);
}