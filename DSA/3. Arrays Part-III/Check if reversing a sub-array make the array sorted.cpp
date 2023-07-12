// https://www.codingninjas.com/studio/library/check-if-reversing-a-sub-array-make-the-array-sorted

// We begin by creating a copy of the original array and then sort it.
// Now, compare the original array with the sorted array. Mark the first and the last index that does not match the two arrays.
// If no such indices exist, then return true.
// Else, the elements between the two indices found shall be in decreasing order in the original array. 
// If the condition is not fulfilled, then we return false. Else we return true.

#include "bits/stdc++.h"
using namespace std;
void solve()
{  
    int arr[] = [1, 2, 3, 5, 4];
    int n = sizeof(arr)/sizeof(int);
   
    // Creating a temporary array
    int temp[n];
    for(int i = 0;i<n;i+=1){
        temp[i]=arr[i];
    }

    //Sorting the array.
    sort(temp, temp+n);
    int fr,bk;

    //Defining the front and back variables.
    fr = -1;bk = -1;
    for(int i = 0;i<n;i+=1){

        //Getting the front variable value.
        if(arr[i]!=temp[i]){
            fr = i;
            break;
        }
    }
   
    //If front doesn't exist, then the array is already sorted.
    if(fr == -1){
        cout<<"YES\n";
        return;
    }

    //Getting the value of back variable.
    for(int i = n-1;i>=0;i--){
        if(temp[i]!=arr[i]){
            bk = i;
            break;
        }
    }

    //Now, we check if the array between front and back variable
    //is sorted in descending order.
    for(int i = fr;i<bk;i++){
        //If not, therefore No single subarray exist.
        if(arr[i]<arr[i+1]){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
}  
int main()
{
    solve();
    return 0;
}