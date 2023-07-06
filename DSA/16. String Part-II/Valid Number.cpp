// RULES:
// DIGITS: 0-9 ATLEAST ONE
// SIGN: + OR - AT FIRST INDEX(0) OR JUST AFTER E OR e
// EXPONENT: e OR E ATMOST ONE AFTER DIGITS
// DECIMAL: . ATMOST ONE BEFORE EXPONENT
class Solution
{
public:
    bool isNumber(string s)
    {
        bool num = false;
        bool exp = false;
        bool dot = false;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                num = true;
            }
            else if (c == 'e' || c == 'E')
            {
                // already seen an e or no number before e
                if (exp == true || num == false)
                    return false;

                exp = true;
                num = false;
            }
            else if (c == '.')
            {
                //already have a dot or seen an e
                if (dot == true || exp == true)
                    return false;
                dot = true;
            }
            else if (c == '-' || c == '+')
            {
                // + and - can only be at the beginning or after e
                // -1 , -1.2 , 1e+2
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else
            {
                // any other character
                return false;
            }
        }

        return num;
    }
};