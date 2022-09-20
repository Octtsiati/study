#include<iostream>
using namespace std;
template <typename T>
struct stack
{
    struct Node
    {
        T val;
        Node *next;
    };
    Node* first;
    stack();
    stack(T *a,int n);
    bool isEmpty(){
         return first==NULL;
    }
    void push(T val);
    T pop();
    void show();
};

void initial(int n,stack<int>&init);
void move(int n,stack<int>&init,stack<int>&tran,stack<int>&tar);
int main(){
    stack<int>init;//initial
    stack<int>tran;//transition
    stack<int>tar;//target
    int n;
    cin>>n;
    initial(n,init);
    init.show();
    move(n,init,tran,tar);
    tar.show();
    return 0;
}
void initial(int n,stack<int>&init){
    for(int i=n-1;i>=0;--i){
        init.push(i);
    }
}
void move(int n,stack<int>&init,stack<int>&tran,stack<int>&tar){//将n个元素从init通过tran转移到tar
    int temp;
    if(n==1){
        tar.push(init.pop());
        return; 
    }
    else
    move(n-1,init,tar,tran);
    move(1,init,tran,tar);
    move(n-1,tran,init,tar);
}
template <typename T>
stack<T>::stack(){
    first=nullptr;
}
template <typename T>
stack<T>::stack(T *a,int n){
     Node* oldfirst=first;
        first=new Node();
        first->val=a[0];
        first->next=nullptr;
    for(int i=1;i<n;++i){
        push(a[i]);
    }
}
template <typename T>
void stack<T>::push(T val){
    if(isEmpty()){
        Node* oldfirst=first;
        first=new Node();
        first->val=val;
        first->next=nullptr;
    }
    else{
    Node* oldfirst=first;
    first=new Node();
    first->val=val;
    first->next=oldfirst;
    }
}
template <typename T>
T stack<T>::pop(){
    if(isEmpty()){
       return false;
    }
   {
    T t=first->val;
    first=first->next;
    return t;
   }
}
template <typename T>
void stack<T>::show(){
    Node*prev;
    Node*pNext;
    prev=first;
    pNext=first;
    if(pNext==nullptr)
    cout<<"none"<<endl;
    else{
    while ((pNext->next)!=nullptr)
    {
        cout<<pNext->val<<endl;
        prev=pNext;
        pNext=pNext->next;
    }
    cout<<pNext->val<<endl;
    }
}