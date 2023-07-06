class Solution
{
public:
    float getDist(vector<int> &x, vector<int> &y)
    {
        float ans = sqrt(pow(x[1] - y[1], 2) + pow(x[0] - y[0], 2) * 1.0);
        ;
        return ans;
    }
    //  Distance between all the sides points - TOTAL 4 will be equal value
    // Distance between diagonal points - TOTAL 2 will be equal value
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<double> dist;
        dist.push_back(getDist(p1, p2));
        dist.push_back(getDist(p1, p3));
        dist.push_back(getDist(p1, p4));
        dist.push_back(getDist(p2, p3));
        dist.push_back(getDist(p2, p4));
        dist.push_back(getDist(p3, p4));

        sort(dist.begin(), dist.end());

        int s = 0, d = 0; // s - count for side  , d- count for diagonal

        float ss = dist[0], dd = dist[5]; // initial value of side and diagonal
        for (int i = 0; i < 6; i++)
        {
            if (dist[i] == ss)
                s++;
            if (dist[i] == dd)
                d++;
        }
        if (s == 4 && d == 2)
            return true;
        return false;
    }
};