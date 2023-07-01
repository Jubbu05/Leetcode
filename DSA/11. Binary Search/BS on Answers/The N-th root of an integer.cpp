int NthRoot(int n, int m)
{
    int low = 1, high = m; // Initialize the lower and upper bounds of the search range

    while (low <= high)
    {
        int mid = (low + high) / 2; // Calculate the middle value

        if (pow(mid, n) == m) // If mid raised to the power of n is equal to m, we found the root
            return mid;
        else if (pow(mid, n) > m) // If mid raised to the power of n is greater than m, search in the lower half
            high = mid - 1;
        else // If mid raised to the power of n is less than m, search in the upper half
            low = mid + 1;
    }

    return -1; // Return -1 if the nth root of m is not found in the range
}
