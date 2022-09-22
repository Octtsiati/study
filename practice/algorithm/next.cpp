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
    while( *p1!=*(end-1) ){//�ҵ�����kʹ��a[k]<a[k+1]
        if( (*p1<*(p1+1)) && (*k<*p1) ){
            k=p1;
        }
        p1++;
    }
    if((*p1<*(p1+1)) && (*k<*p1)){//p1+1Ϊendʱ
        k=p1;
    }
    p2=b=k+1;
    while(*p2!=*end){//�Ҵ���k���������b��ʹ��a[k]<a[b]
        if((*p2>*k)&&(*p2>*k)){
            b=p2;
        }
        p2++;
    }
    if((*p2>*k)&&(*p2>*k)){//p2Ϊendʱ
            b=p2;
        }
    int t;
    if(*k<*b){
        t=*k;
        *k=*b;
        *b=t;
        //��ת��k+1��n������
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
