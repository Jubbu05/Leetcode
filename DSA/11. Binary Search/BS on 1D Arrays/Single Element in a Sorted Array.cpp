//PAIR CHECK
//(EVEN, ODD) -> LEFT HALF (ELEMENT IS ON RIGHT HALF)
//(ODD, EVEN) -> RIGHT HALF (ELEMENT IS ON LEFT HALF)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        int low = 0; 
        int high = n - 1; 

        // Boundary checks
        if (n == 1) 
            return nums[0]; // Return the only element if there's only one element in the vector
        else if (nums[0] != nums[1])
            return nums[0]; // Return the first element if it's not equal to the second element
        else if (nums[n - 1] != nums[n - 2])
            return nums[n - 1]; // Return the last element if it's not equal to the second last element

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            // Unique element check
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid]; // Return the unique element

            // Adjust the search range based on whether the element appears in even or odd index positions
            //(evem,odd) pair check -> left half SO ELEMENT IS ON RIGHT HALF
            //      (even index and next element is same)            (odd index and previous element is same) 
            else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                low = mid + 1; 
            else
                high = mid - 1; 
        }
        return -1; 
    }
};
