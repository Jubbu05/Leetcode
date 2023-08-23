class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> maxheap;

        for (auto it : s)
        {
            freq[it]++;
        }
        for (auto it : freq)
        {
            maxheap.push({it.second, it.first});
        }
        s = "";
        while (!maxheap.empty())
        {
            auto it = maxheap.top();
            maxheap.pop();
            char c = it.second;
            int x = it.first;
            while (x)
            {
                s += c;
                x--;
            }
        }
        return s;
    }
};