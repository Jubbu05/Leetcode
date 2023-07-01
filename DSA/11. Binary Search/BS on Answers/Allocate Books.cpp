int isPossible(vector<int> &A, int pages, int students)
{
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (sumAllocated + A[i] > pages)
    {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages)
        return false;
    }
    else
    {
      sumAllocated += A[i];
    }
  }
  if (cnt < students)
    return true;
  return false;
}
int findPages(vector<int> A, int n, int m)
{
  // search space maxElement to sumOfAllElements
  if (m > n)
    return -1;
  int low = *(max_element(A.begin(), A.end()));
  int high = accumulate(A.begin(), A.end(), 0);

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, m))
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}