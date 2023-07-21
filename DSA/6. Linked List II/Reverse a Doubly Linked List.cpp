Node* reverseDLL(Node * head)
{
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        curr->prev = nxt;
        prev = curr;
        curr = nxt;
    }
    return prev;
}