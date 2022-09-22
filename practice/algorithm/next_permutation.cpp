#include<iostream>

using namespace std;

bool next_permutation(int n,int*a,int *&index);//indexΪ��һ���޸ĵĺ�һ��Ԫ�ص�λ��
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
        index=k+1;
    return true;
    }
    return false;
}
bool reverse(int *index,int *end){
   //��ת��k+1��n������
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
