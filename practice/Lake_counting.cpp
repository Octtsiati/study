#include<iostream>
using namespace std;
int DFS(char**p,int n,int m,int i,int j);
int main(){
    int n,m;
    cin>>n>>m;
    char **p=new char *[n];
    for(int i=0;i<n;++i){
        p[i]=new char[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[n][m];
        }
    }

}
int DFS(char**p,int n,int m,int i,int j){//pΪ���飬n��mΪ���鳤��,ijȷ�����鵱ǰλ��
    if(**p=='.'){
        if((++i)!=n&&*((*p)+1)!='W'){

        }
    }
}