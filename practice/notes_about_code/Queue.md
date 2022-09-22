# Queue

### 声明

同stack，包含链表设置结点，然后使用first和last指针分别指向队列的首尾，然后包括入队出队、判断是否队列为空，展示的操作

```c++
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
```

### 构造

同stack，默认构造则令first和last均为空指针，构造则以数组和数组长度为函参，分别将队列中的元素排进去

## enque()

首先判断队列是否为空（**空指针无法直接赋值**），故若为空，则先给first开辟内存后再存储，并让first->next指向last；若不为空，则再看last是否为空，为空则开辟内存后为其赋值，若不为空则让newlast等于last，刷新last的值，再使newlast->next指向last

```c++
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
```

### deque()

若为空则错误，不为空则first指向下一个

```c++
if(isEmpty()){
        return false;
    }
    {
    first=first->next;
    return true;
    }
```

### show()

同stack

```c++
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
```

## 改进

- [ ] 把deque的时候返回元素的值，show的时候就可以输出deque的值后再把它enque进去，这样一个轮回队列不变