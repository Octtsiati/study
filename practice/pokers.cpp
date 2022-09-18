#include<iostream>
using namespace std;
struct queue{
    int p[100];
    int head=0;
    int tail=0;
};
struct stack{
    int stack[100];
    int top;
};
int book[10]={0};

int main(){
    queue q1;
    queue q2;
    for(int i=0;i<6;i++){
        cin>>q1.p[q1.tail];
        q1.tail++;
    }
    for(int i=0;i<6;i++){
        cin>>q2.p[q2.tail];
        q2.tail++;
    }
    stack s;
    s.top=0;
    int t=0;
    while(q1.head<q1.tail && q2.head<q2.tail){
         t=q1.p[q1.head];//��ʱ������q1�ĵ�һ����
        if(book[t]==0){//������û�к�q1������һ����
            q1.head++;//q1��һ����ɾ��
             s.top++;//�����ϼ�һ����
            s.stack[s.top]=t;
           
            book[t]=1;//��Ǹ����������ϴ���
        }
        else//�������к�q1������һ����
        {
            q1.head++;//�Ȱ����е��Ƴ���ȥ
            q1.p[q1.tail]=t;
            q1.tail++;//���û���
            while(s.stack[s.top]!=t){
                book[s.stack[s.top]]=0;//���Ʊ��Ϊ��
                q1.p[q1.tail]=s.stack[s.top];//�������ϵ����û���
                q1.tail++;
                s.top--;
            }
            
        }
 t=q2.p[q2.head];
        if(book[t]==0){//������û�к�q1������һ����
            q2.head++;
             s.top++;
            s.stack[s.top]=t;
           
            book[t]=1;
        }
        else//�������к�q1������һ����
        {
            q2.head++;
            q2.p[q2.tail]=t;
            q2.tail++;
            while(s.stack[s.top]!=t){
                book[s.stack[s.top]]=0;//���Ʊ��Ϊ��
                q2.p[q2.tail]=s.stack[s.top];
                q2.tail++;
                s.top--;
            }
            
        }
        if(q1.head==q1.tail){
            cout<<"player1 wins"<<endl;
            cout<<"what player2 have are ";
            for(int i=q2.head;i<=q2.tail;++i){
                cout<<q2.p[q2.head]<<' ';
            }
            cout<<endl;
        }
        else if(q2.head==q2.tail){
            cout<<"player2 wins"<<endl;
            cout<<"what player1 have are ";
            for(int i=q1.head;i<=q1.tail;++i){
                cout<<q1.p[q1.head]<<' ';
            }
            cout<<endl;
        }
       
    }
     if(s.top>0){
            cout<<"pokers on the desk are ";
            for(int i=s.top;i>=0;--i){
                cout<<s.stack[s.top]<<' ';
            }
            cout<<endl;
        }
        else
        cout<<"There are no pokers existing."<<endl;
    return 0;
}
/*
#if false
#include<iostream>
#include<vector>
using namespace std;
struct queue{
    int *p;
    int head=0;
    int tail=0;
    queue(int n,int *a);
};
struct stack{
    vector<int> sta;
    int top;
};
void game();
int main(){
    int n1,n2;
    cin>>n1>>n2;
    int *p1=new int(n1);
    int *p2=new int(n2);
    for(int i=0;i<n1;++i){
        cin>>p1[i];
    }
    for(int i=0;i<n2;++i){
        cin>>p2[i];
    }
    queue q1(n1,p1);
    queue q2(n2,p2);

}
queue::queue(int n,int *a){//nΪ���鳤�ȣ�Ϊ����
    int *p=new int(n);
    for(int i=0;i<n;++i){
        p[i]=a[i];
        tail++;
    }
}
void game(queue &q1,queue &q2){
    int book[9]={0};
    int t=0;
    stack s;
    s.top=0;
    while(q1.head<q1.tail && q2.head<q2.tail){
        t=q1.p[q1.head];
        if(book[t]==0){//������û�к�q1������һ����
            q1.head++;
            s.top++;
            s.sta.push_back(t);
            book[t]=1;
        }
        else//�������к�q1������һ����
        {
            q1.head++;

        }
    }
}
#endif*/
/*
2 4 1 2 5 6
3 1 3 5 6 4
С��win
С����ǰ���е����ǣ�
1 6 5 2 3 4 1 �����ϵ����������Ϊ��
3 4 5 6 2 �밴���������. . .
image.png
*/