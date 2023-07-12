class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                ans[i] = ans[i] * nums[j];
            }
        }
        return ans;
    }
};

//------------------------------------------------------------------------------------

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);

        // PRODUCT OF ALL ELEMENTS FROM LEFT TO RIGHT
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= nums[i];
            left[i] = product;
        }

        // PRODUCT OF ALL ELEMENTS FROM RIGHT TO LEFT
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            product *= nums[i];
            right[i] = product;
        }

        // EDGE CASES
        ans[0] = right[0];
        ans[n - 1] = left[n - 2];

        for (int i = 1; i < n - 1; i++)
        {
            ans[i] = left[i - 1] * right[i + 1];
        }

        return ans;
    }
};

//------------------------------------------------------------------------------------

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        int product = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int j = n - 1; j >= 0; j--)
        {
            ans[j] *= product;
            product *= nums[j];
        }

        return ans;
    }
};

//------------------------------------------------------------------------------------

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        int product1 = 1, product2 = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] *= product1;
            product1 *= nums[i];

            int j = n - i - 1;
            ans[j] *= product2;
            product2 *= nums[j];
        }
        return ans;
    }
};