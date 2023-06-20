// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int cnt0=0;
//         int cnt1=0;
//         int cnt2=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 cnt0++;
//             }else if(nums[i]==1){
//                 cnt1++;
//             }else{
//                 cnt2++;
//             }
//         }
//         int i=0;
//         while(cnt0!=0){
//             nums[i++]=0;
//             cnt0--;
//         }
//         while(cnt1!=0){
//             nums[i++]=1;
//             cnt1--;
//         }
//         while(cnt2!=0){
//             nums[i++]=2;
//             cnt2--;
//            }
//     }
// };
//Dutch national flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};