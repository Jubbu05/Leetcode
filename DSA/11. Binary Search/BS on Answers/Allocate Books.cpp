// MAXIMUM NUMBER OF PAGES ALLOCATED TO A STUDENT SHOULD BE MINIMUM
int cntStudent(vector<int> &A, int pages)
{
  int students = 0;
  int sumAllocated = 0; // sumAllocated denotes pages the student currently holding
  for (int i = 0; i < A.size(); i++)
  {
    // can we allocate A[i] pages to current
    if (sumAllocated + A[i] > pages) // if sumAllocated + A[i] > pages then we need to allocate a new book to student
    {
      students++;          // increment student count
      sumAllocated = A[i]; // allocate A[i] pages to new student
    }
    // we can allocate A[i] pages to current student
    else
    {
      sumAllocated += A[i];
    }
  }
  return students;
}
int findPages(vector<int> A, int n, int m)
{
  // n - no of books
  // m - no of students
  // search space maxElement to sumOfAllElements
  if (m > n)
    return -1;
  int low = *(max_element(A.begin(), A.end())); // maxElement
  int high = accumulate(A.begin(), A.end(), 0); // sumOfAllElements

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int students = cntStudent(A, mid);
    if (students < m) // we can allocate pages to more students
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