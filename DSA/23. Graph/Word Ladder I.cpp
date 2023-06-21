class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> us(wordList.begin(), wordList.end());

        q.push({startWord, 1});
        us.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if (word == targetWord)
                return step;

            for (int i = 0; i < word.length(); i++)
            {
                // getting every letter
                char temp = word[i];
                // changing it to every letter from a to z
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // if the word exists in the set
                    if (us.find(word) != us.end())
                    {
                        q.push({word, step + 1});
                        us.erase(word);
                    }
                }
                // restoring the word
                word[i] = temp;
            }
        }
        return 0;
    }
};