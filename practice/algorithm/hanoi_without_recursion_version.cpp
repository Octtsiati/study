/*
˼·��
ÿ���̶�Ӧ�����������ϵ�һλ����ʼ״̬Ϊ0������״̬Ϊ�Ӹ�λ���Լ���Ϊ1��
��������0��ʼ��1����1���������һ����������������㡾^��,��ò�ͬ��λ������
��0��Ϊ1�����Ӧ�����ƣ��Ѿ������ҵ���ȥ�������ٽ����ұ��б��Լ�С�����������ң�ֱ��ÿһλ��Ϊ1
*/
#include<iostream>
#include<cmath>
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

int main(){
    stack<int>init;//initial
    stack<int>tran;//transition
    stack<int>tar;//target
    int n;
    cin>>n;
    initial(n,init);
    init.show();
    int t=0;
    int index;
    for(int i=1;i<pow(2,n);++i){
        int s=t^i;
        for(int j=0;j<n;++j){
            if((i&~(1<<j))&&(t&(1<<j))){//���ڵ�jΪ������0��Ϊ1
                index=j;
                break; 
                }
            
        } 
       move(n){//����Ӧ����������

       }    


    }
    return 0;
}
void initial(int n,stack<int>&init){
    for(int i=n-1;i>=0;--i){
        init.push(i);
    }
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