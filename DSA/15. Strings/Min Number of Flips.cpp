// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

// string = 0 0 0 1 0 1 0 1 1 1
// case1  = 0 1 0 1 0 1 0 1 0 1 
// case2  = 1 0 1 0 1 0 1 0 1 0

int minFlips(string S)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (i % 2 == 0 && S[i] == '1')
            cnt1++;
        else if (i % 2 == 1 && S[i] == '0') // odd index 
            cnt1++;

        if (i % 2 == 0 && S[i] == '0')
            cnt2++;
        else if (i % 2 == 1 && S[i] == '1')
            cnt2++;
    }
    return min(cnt1, cnt2);
}