# stack

### 声明

首先根据《算法》内容设置一个结构体 stack ，并将Node包含进去，stack包含的成员有头指针first（要实现FIFO），操作有判断**是否为空栈**、**push（将元素压入栈）**、**pop（将元素弹出栈）**、**show（从栈顶开始依次展出栈中元素）**

```c++
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
```

### 构造函数

1. 默认构造函数：将第一个节点设置为空（方便后面判断栈是否为空）
2. 函数参数有，指针a，整型变量 n，构造方式：将数组a内元素一个个压入栈中，此时需要使用到push()

### isEmpty()

通过判断头指针是否为空决定

### push()

思路：新建一个新指针oldfirst指向first，first.val改变为push的元素，first.next指向first

```c++
if(isEmpty()){
        Node* oldfirst=first;
        first=new Node();
        first->val=val;
        first->next=nullptr;
    }
```

### pop()

若为空，则返回错误

若不为空，则将头指针指向下一个

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

两个指针prev、pnext，初始指向头指针，若为空则声明none结束，若不为空，则当pnext的下一个不为空时（即到倒数第二个元素），输出pnext的元素，然后pnext指向它的下一个

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

**改进**

利用pop()直接输出【缺点：只能show一次，因为全都pop出去了】

```c++
while(!this->isEmpty()){
    cout<<this->first->val<<endl;
    this->pop();
} 
```

改成模板类型

```c++
template <typename T>
stack<int> b(a,5);
```



## 待改进之处

- [ ] 
- [ ] 直接利用已经写好的链表使用栈