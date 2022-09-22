#include<iostream>

using namespace std;

bool next_permutation(int n,int*a,int *&index);//index为上一次修改的后一个元素的位置
bool reverse(int *index,int *end);
int main(){
    int n;
    cin>>n;
    int *a=new int[n]();
    for(int i=0;i<n;++i){
        a[i]=i+1;
    }
    int* index=nullptr;
    for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    while(next_permutation(n,a,index)){
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        if(reverse(index,&a[n-1])){
            for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        }
        
    }
    return 0;
}
bool next_permutation(int n,int*a,int *&index){
    int*p1,*p2;
    p1=p2=a;
    int *end=&a[n-1];
    int*k,*b;
    k=p1;
    while( *p1!=*(end-1) ){//找到最大的k使得a[k]<a[k+1]
        if( (*p1<*(p1+1)) && (*k<*p1) ){
            k=p1;
        }
        p1++;
    }
    if((*p1<*(p1+1)) && (*k<*p1)){//p1+1为end时
        k=p1;
    }
    p2=b=k+1;
    while(*p2!=*end){//找大于k的最大索引b，使得a[k]<a[b]
        if((*p2>*k)&&(*p2>*k)){
            b=p2;
        }
        p2++;
    }
    if((*p2>*k)&&(*p2>*k)){//p2为end时
            b=p2;
        }
    int t;
    if(*k<*b){
        t=*k;
        *k=*b;
        *b=t;
        index=k+1;
    return true;
    }
    return false;
}
bool reverse(int *index,int *end){
   //反转从k+1到n的序列
   int t;
    while((index!=end)&&(index<end)){
    t=*index;
    *index=*end;
    *end=t;
    index++;
    end--;
        return true;
    } 


return false;
}
