/*
˼·��
ÿ���̶�Ӧ�����������ϵ�һλ����ʼ״̬Ϊ0������״̬Ϊ�Ӹ�λ���Լ���Ϊ1��
��������0��ʼ��1����1���������һ����������������㡾^��,��ò�ͬ��λ������
��0��Ϊ1�����Ӧ�����ƣ��Ѿ������ҵ���ȥ�������ٽ����ұ��б��Լ�С�����������ң�ֱ��ÿһλ��Ϊ1
*/
#include<iostream>
#include<cmath>
using namespace std;
int** search(int n,int**top);//���Ҷ�Ӧ�������ĸ�������,���ض�Ӧ��ջ��ָ��
void move(int **top,int *f);

int main(){

    int n;
    cin>>n;
    int *init=new int[n]();//�����������飬�ֱ�Ϊ��ʼ�����ɡ�Ŀ����
    int *tran=new int[n]();
    int *tar=new int[n]();
    for(int i=0;i<n;++i){
        init[i]=i+1;
    }

    int* top[4]={nullptr};
    top[0]=&init[0];
    top[1]=&tran[n-1];//ջ��
    top[2]=&tar[n-1];

    int t=0;
    int index=0;
    for(int num=1;num<pow(2,n);++num){
        for(int j=0;j<n;++j){//1.��ȡ������
            if((num&(1<<j))&&( !(t&(1<<j)) )){//���ڵ�jΪ������0��Ϊ1
                index=j;//��Ҫ�ƶ����ǵ�j������(0,1,2...)
                t=num;
                break; 
                }

        }
        move(search(index,top),top[2]);//����Ӧ����������
             
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
void move(int **p,int *f){// pΪ&top[2] *pΪtop[2] **pΪtran[n-1] fΪtop[2]
    int t=**p;
    while( 1 ){//��һ������Ԫ�ش��ڱ���
    if(*p!=f && ( (**(p+1)) >**p)){//p��Ϊp[2]����һ��ջ�����Լ���
        if(*(*p+1)>0)
        (*p)++;//ջ������һ��
        p++;//ָ��ָ����һ��
        (*p)--;//��һ����ջ��ѹ��ȥ
        **p=t;
        break;
    }
    else if( *p!=f && (**(p+1))==0){//p��Ϊp[2]����һ��ջ��Ϊ��
        if(*(*p+1)>0)
        (*p)++;//ջ������һ��
        p++;//ָ��ָ����һ��
        **p=t;
        break;
    }
    else if((*p)==f && (*((&f)-2) >*p)  ){//pΪtop[2],��top[0]����top[2]
        (*p)--;
        p=(&f)-2;//pֱ��Ϊtop[0]
        **p=t;
        break;
    }
    else if((*p)==f && *((&f)-2)==0 ) {//pΪtop[2],��top[0]����top[2]
        if(*(*p+1)>0)
        (*p)++;//ջ������һ��
        p=(&f)-2;//pֱ��Ϊtop[0]
        **p=t;
        break;
    }
    else {//ʣ�µ������ֱ������һ��
        (*p)++;//ջ������һ��
        p++;//ָ��ָ����һ��
    }
        
    }

}