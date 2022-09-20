/*
思路：
每个盘对应二进制数串上的一位，初始状态为0，结束状态为从高位到自己均为1；
方法：从0开始加1，加1后的数与上一步的数进行异或运算【^】,求得不同的位数，若
从0变为1，则对应盘右移（已经在最右的则去最左，若临近的右边有比自己小的盘则再往右）直至每一位均为1
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
            if((i&~(1<<j))&&(t&(1<<j))){//若在第j为数字由0变为1
                index=j;
                break; 
                }
            
        } 
       move(n){//将对应的盘子右移

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