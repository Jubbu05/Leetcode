class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1); // Swap arrays to ensure binary search happens on the minimum size array

        int low = 0, high = n1; //we can choose mininum 0 elements and maximum n1 elements from nums1

        while (low <= high) {
            int cut1 = (low + high) / 2; // Calculate the cut position for the first array
            int cut2 = ((n1 + n2 + 1) /2) - cut1; // Calculate the corresponding cut position for the second array

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]; //         Get the left element of the first array segment
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1]; // Get the left element of the second array segment
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1]; // Get the right element of the first array segment
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2]; // Get the right element of the second array segment

            //checking for valid cut
            if (l1 <= r2 && l2 <= r1) {
                //length is even
                if ((n1 + n2) % 2 != 0)
                    return max(l1, l2); //median will be the maximum of left elements if the total number of elements is odd 
                else
                    //for even length
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            else if (l1 > r2){
                 high = cut1 - 1; // Adjust the search range to the left of cut1
            }
            else{
                low = cut1 + 1; // Adjust the search range to the right of cut1
            }
        }
        return 0.0; // Return 0.0 if the median is not found
    }
};
