struct ListNode {
    int val;
    struct ListNode *next;
};
ListNode* create(int a[],int n);
ListNode* sort(struct ListNode* head);
void output(ListNode* head);
ListNode* insert(ListNode* head,int n);
ListNode* remove(ListNode* head,int n);
