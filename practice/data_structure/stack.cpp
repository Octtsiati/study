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
    bool pop();
    void show();
};
int main(){
    int a[5]={1,2,3,4,5};
    stack<int> b(a,5);
    b.push(2);
    b.show();
    //b.show();
    //cout<<b.isEmpty()<<endl;
    return 0;
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
    
    Node* oldfirst=first;
    first=new Node();
    first->val=val;
    first->next=oldfirst;
    
}
template <typename T>
bool stack<T>::pop(){
    if(isEmpty()){
       return false;
    }
   {
    first=first->next;
    return true;
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