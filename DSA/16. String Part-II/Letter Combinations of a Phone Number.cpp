class Solution
{
public:
    void solve(string digits, string output, int index, vector<string> &ans, vector<string> &mappings)
    {
        if (index >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mappings[number];

        for (int i = 0; i < value.size(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mappings);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        // string mappings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> mappings{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mappings);
        return ans;
    }
};