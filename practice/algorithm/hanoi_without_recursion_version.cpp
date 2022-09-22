/*
思路：
每个盘对应二进制数串上的一位，初始状态为0，结束状态为从高位到自己均为1；
方法：从0开始加1，加1后的数与上一步的数进行异或运算【^】,求得不同的位数，若
从0变为1，则对应盘右移（已经在最右的则去最左，若临近的右边有比自己小的盘则再往右）直至每一位均为1
*/
#include<iostream>
#include<cmath>
using namespace std;
int** search(int n,int**top);//查找对应的盘在哪根柱子上,返回对应的栈顶指针
void move(int **top,int *f);

int main(){

    int n;
    cin>>n;
    int *init=new int[n]();//建立三个数组，分别为起始、过渡、目标柱
    int *tran=new int[n]();
    int *tar=new int[n]();
    for(int i=0;i<n;++i){
        init[i]=i+1;
    }

    int* top[4]={nullptr};
    top[0]=&init[0];
    top[1]=&tran[n-1];//栈顶
    top[2]=&tar[n-1];

    int t=0;
    int index=0;
    for(int num=1;num<pow(2,n);++num){
        for(int j=0;j<n;++j){//1.获取盘子数
            if((num&(1<<j))&&( !(t&(1<<j)) )){//若在第j为数字由0变为1
                index=j;//需要移动的是第j个盘子(0,1,2...)
                t=num;
                break; 
                }

        }
        move(search(index,top),top[2]);//将对应的盘子右移
             
       }    
        for(int i=0;i<n;++i){
            cout<<tar[i]<<endl;
        }
    
    return 0;
}
int** search(int n,int**top){
    for(int i=0;i<3;++i){
        if(*(top[i])-1==n)
        return &(top[i]);
    }
}
void move(int **p,int *f){// p为&top[2] *p为top[2] **p为tran[n-1] f为top[2]
    int t=**p;
    while( 1 ){//下一个柱顶元素大于本身
    if(*p!=f && ( (**(p+1)) >**p)){//p不为p[2]且下一个栈顶比自己大
        if(*(*p+1)>0)
        (*p)++;//栈顶弹出一个
        p++;//指针指向下一个
        (*p)--;//下一个的栈顶压下去
        **p=t;
        break;
    }
    else if( *p!=f && (**(p+1))==0){//p不为p[2]且下一个栈顶为空
        if(*(*p+1)>0)
        (*p)++;//栈顶弹出一个
        p++;//指针指向下一个
        **p=t;
        break;
    }
    else if((*p)==f && (*((&f)-2) >*p)  ){//p为top[2],且top[0]大于top[2]
        (*p)--;
        p=(&f)-2;//p直接为top[0]
        **p=t;
        break;
    }
    else if((*p)==f && *((&f)-2)==0 ) {//p为top[2],且top[0]大于top[2]
        if(*(*p+1)>0)
        (*p)++;//栈顶弹出一个
        p=(&f)-2;//p直接为top[0]
        **p=t;
        break;
    }
    else {//剩下的情况，直接跳下一个
        (*p)++;//栈顶弹出一个
        p++;//指针指向下一个
    }
        
    }

}