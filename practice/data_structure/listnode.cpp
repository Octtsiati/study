#include<iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
};
ListNode* create(int *a,int n);
void output(ListNode* head);
ListNode* insert(ListNode* head,int n);
ListNode* remove(ListNode* head,int n);
int main(){
    int a[10];
    int n,rm;
    cin>>n>>rm;
    for(int i = 0;i<n;i++){
        cin>>a[i]; 
    }
    ListNode* list = create(a,n);
    output(list);
    list = remove(list,rm);
    output(list);
    return 0;
}
ListNode* create(int *a,int n){//创建链表
    ListNode* head=NULL;//建立头节点
    ListNode* PreNode=NULL;
    PreNode=new ListNode;
    PreNode->val=a[0];
    PreNode->next=NULL;
    head=PreNode;  
    for(int i=1;i<n;++i){
        ListNode* NewNode=new ListNode;
        NewNode->val=a[i];
        NewNode->next=NULL;
        PreNode->next=NewNode;
        PreNode=NewNode;
    }
    return head;//返回第一个节点（头节点）
}
void output(ListNode* head){
    ListNode *prev;
    ListNode*pNext;
    prev=head;
    pNext=head;
    while ((pNext->next)!=nullptr)
    {
        cout<<pNext->val<<endl;
        prev=pNext;
        pNext=pNext->next;
    }
    if(pNext!=head)
    cout<<pNext->val<<endl;
    
}
ListNode* insert(ListNode* head,int n){//按需修改
    ListNode *NewNode=new ListNode;
    NewNode->val=n,NewNode->next=NULL;
    if(head==NULL){
        head=NewNode;
    }
    ListNode*p=head;
    ListNode*pNext=head;
    return head;
}
ListNode* remove(ListNode* head,int n){
    ListNode*p=head;
    ListNode*pNext=head;
    while(((pNext->next)!=NULL)&&((pNext->val)!=n))
        {
	        p=pNext;
	        pNext=pNext->next;
        }
    if(pNext==head)
        {
	head=p->next;
	delete pNext;
        }
    else if(pNext->val==n)
        {
	        p->next=pNext->next;
	        delete pNext;
        }   
return head;
}