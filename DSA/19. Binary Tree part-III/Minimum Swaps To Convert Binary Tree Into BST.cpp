#include <bits/stdc++.h>
void inorder(vector<int> &arr, vector<int> &in, int i)
{
    if (i >= arr.size())
        return;
    inorder(arr, in, 2 * i + 1);
    in.push_back(arr[i]);
    inorder(arr, in, 2 * i + 2);
}
// minimum swaps to sort an array
int minimumSwaps(vector<int> &arr, int n)
{
    vector<int> nums;
    inorder(arr, nums, 0);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end()); // sort according to value
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = v[i];
        int value = p.first;
        int index = p.second;

        // 2,0  8,1  5,2  4,3

        // 2,0  4,3  5,2  8,1
        // i=0    1    2    3

        // if  i == index then index is at correct position no need to swap

        if (i != index)
        {
            swap(v[i], v[index]);
            swaps++;
            i--; // we need to check i again if the swapped element is at correct position or not
        }
    }
    return swaps;
}
