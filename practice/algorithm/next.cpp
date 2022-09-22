#include<iostream>

using namespace std;

bool next_permutation(int n,int*a);
int main(){
    int n;
    cin>>n;
    int *a=new int[n]();
    for(int i=0;i<n;++i){
        a[i]=i+1;
    }
    while(next_permutation(n,a)){
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
bool next_permutation(int n,int*a){
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
        //反转从k+1到n的序列
        if((k+1)!=end){
            k++;
             while(k!=end){
                t=*end;
                *k=*end;
                *end=t;
                k++;
                end--;
             }
        return true;
    
    }
    return false;
}
