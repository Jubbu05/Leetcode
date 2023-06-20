class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // If n is greater than m, swap the arrays and their lengths
        // to ensure that n is always smaller than or equal to m.
        if (n > m)
            return kthElement(arr2, arr1, m, n, k);

        // Calculate the range for the binary search
        int low = max(0, k - m);
        int high = min(k, n);

        // Perform binary search
        while (low <= high)
        {
            // Calculate the partition cuts for both arrays
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            // Determine the elements at the partition cuts
            // and their neighboring elements
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            // Check if the current partition is valid
            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2); // Found the kth element

            // Adjust the search range based on the comparison results
            else if (l1 > r2)
                high = cut1 - 1; // Move the high boundary to the left
            else
                low = cut1 + 1; // Move the low boundary to the right
        }

        // Return a default value (1 in this case) if k is invalid or out of range
        return 1;
    }
};
