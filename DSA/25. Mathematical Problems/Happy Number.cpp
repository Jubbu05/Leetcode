class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> s;
        int val;
        int index;

        while (1)
        {
            val = 0;

            while (n)
            {
                index = n % 10;
                val += index * index;
                n /= 10;
            }
            if (val == 1)
            {
                return true;
            }

            // stuck in a loop
            else if (s.find(val) != s.end())
            {
                return false;
            }

            s.insert(val);
            n = val;
        }
        return false;
    }
};

class Solution
{
public:
    int getSquareDigit(int num)
    {
        int sum = 0;
        while (num)
        {
            int r = num % 10;
            sum += r * r;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        do
        {
            slow = getSquareDigit(slow);
            fast = getSquareDigit(getSquareDigit(fast));
        } while (slow != fast);
        if (slow == 1)
        {
            return true;
        }
        return false;
    }
};