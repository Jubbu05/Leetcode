class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";
    if (n == 2)
      return "11";

    string str = "11";

    for (int i = 3; i <= n; i++)
    {
      str += '$'; // delimiter
      int len = str.length();

      int cnt = 1;
      string tmp = "";

      for (int j = 1; j < len; j++)
      {
        if (str[j] != str[j - 1])
        {
          tmp += to_string(cnt); // count
          tmp += str[j - 1]; // value
          cnt = 1;
        }
        else
          cnt++;
      }`
      str = tmp;
    }

    return str;
  }
};