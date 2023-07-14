struct Node
{
    Node *links[26];
    bool flag = false;
    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node()); // put the character in the trie with a new node
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd(); // set the end of the word
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        // if the word is present in the trie then the flag of the last trie will be true
        if (node->isEnd() == true)
        {
            return true;
        }
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};