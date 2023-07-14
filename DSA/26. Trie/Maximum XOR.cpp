struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    Node *getBit(int bit)
    {
        return links[bit];
    }

    void putBit(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // get ith bit
            if (!node->containsKey(bit))
            {
                node->putBit(bit, new Node()); // put the bit in the node and create a new node
            }
            node = node->getBit(bit); // move to the next node
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // does it contain opposite of bit coz we want to maximize the xor
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i); // make the ith bit 1
                node = node->getBit(1 - bit);
            }
            else
            {
                node = node->getBit(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (auto &it : arr1)
    {
        trie.insert(it);
    }
    int maxi = 0;
    for (auto &it : arr2)
    {
        maxi = max(maxi, trie.getMax(it));
    }

    return maxi;
}