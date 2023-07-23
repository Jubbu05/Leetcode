//OPTIMAL APPROACH 1
// GAP Algo
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int k = 0;
    for (int i = m; i < m + n; i++)
    {
      nums1[i] = nums2[k++];
    }
    int gap = ceil((m + n) / 2);
    while (gap > 0)
    {
      int i = 0, j = gap;
      while (j < m + n && i < m + n)
      {
        if (nums1[i] > nums1[j])
        {
          swap(nums1[i], nums1[j]);
        }
        i++;
        j++;
      }
      if (gap <= 1)
        gap = 0;
      else
        gap = ceil((gap / 2));
    }
  }
};

//OPTIMAL APPROACH 2
//TC - O(min(n,m)) + O(nlogn) + O(mlogm)
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int left = m - 1;
    int right = 0;

    while (left >= 0 && right < n) //O(min(n,m))
    {
      if (nums1[left] > nums2[right])
      {
        swap(nums1[left], nums2[right]);
        left--;
        right++;
      }
      else
      {
        break;
      }
    }
    sort(nums1.begin(), nums1.end()); //O(nlogn)
    sort(nums2.begin(), nums2.end()); //O(mlogm)
  }
};