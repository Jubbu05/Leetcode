class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        unordered_map<int, int> freq;
        Node *temp = head;
        freq[temp->data] = 1;
        while (temp->next != NULL)
        {
            if (freq.count(temp->next->data) != 0)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
                freq[temp->data]++;
            }
        }
        return head;
    }
};