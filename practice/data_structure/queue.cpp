using namespace std;
template<typename T> 
struct Queue
{
    struct Node{
        T val;
        Node *next;
    };
    Node *first;
    Node *last;
    Queue();
    Queue(T*a,int n);
    bool isEmpty(){return first == nullptr;}
    void enqueue(T val);
    bool dequeue();
    void show();

};
int main(){
    double a[5]={1.1,2,3,4,5};
    Queue<double> q(a,5);
    q.enqueue(3);
    q.show();
    q.dequeue();
    q.show();
    return 0;
}
template<typename T> 
Queue<T>::Queue(){
    first=last=nullptr;
}
template<typename T>
Queue<T>::Queue(T*a,int n){
    Node* oldfirst=first;
        first=new Node();
        first->val=a[0];
        first->next=last=nullptr;
        for(int i=1;i<n;++i){
            enqueue(a[i]);
        }
}
template<typename T>
void Queue<T>::enqueue(T val){
    if(isEmpty()){
        
        first=new Node();
        first->val=val;
        first->next=last;
    }
      else if(last==nullptr){
        
        last=new Node();
        last->val=val;
        last->next=nullptr;
        first->next=last;
    }
    else{
        Node* oldlast=last;
        last=new Node();
        last->val=val;
        last->next=nullptr;
        oldlast->next=last;
    }
}
template<typename T>
bool Queue<T>::dequeue(){
    if(isEmpty()){
        return false;
    }
    {
    first=first->next;
    return true;
    }
}
template<typename T>
void Queue<T>::show(){
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
