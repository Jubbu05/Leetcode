class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int start;
        int end;
        int posi;
    };
    bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.posi < m2.posi) return true;
         return false;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].posi = i;
        }

        sort(meet, meet + n, comparator);

        int limit = meet[0].end;
        int cnt=1;
        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                cnt++;
            }
        }
      return cnt;
    }
};