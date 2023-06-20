class Solution {
public:
    int compareVersion(string v1, string v2) {
        // support variables
        int i = 0, j = 0, v1Len = v1.size(), v2Len = v2.size(), n1, n2;
        while (i < v1Len || j < v2Len) {
            // computing the next set of version sub-values
            //121.33.4
            //121.34.5
            n1 = 0;
            n2 = 0;

            while (i < v1Len && v1[i] != '.') n1 = n1 * 10 + (v1[i++] - '0'); // 121
            while (j < v2Len && v2[j] != '.') n2 = n2 * 10 + (v2[j++] - '0'); // 121
            // handling possible results

            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
            
            // to move from . to next sub-value if both are same
            // 121.33.4
            //    i
            // 121.33.5
            //     i
            //now it will again generate 33 and 34 and compare them
            i++;
            j++;
        }
        return 0;
    }
};