#include<iostream>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t1=0;
        int t2=0;//��λ��Ӵ浽�������н�λ��ŵ���һ����
        ListNode *p=nullptr;
        int v1,v2;
        if(l1==nullptr)
            v1=0;
        else
            v1=l1->val;
        if(l2==nullptr)
            v2=0;
            else
                v2=l2->val;
        t1=v1+v2; 
            t1=t2+t1%10;//��λ��
            t2=t1/10;//ʮλ��
        p=new ListNode(t1);
        while(l1->next!=nullptr && l2->next!=nullptr){
            t1=l1->val+l2->val; 
            t1=t2+t1%10;//��λ��
            t2=t1/10;//ʮλ��
            p->next=new ListNode(t1);
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l2->next==nullptr){
            while(l1->next!=nullptr){
                t1=l1->val+t2;
                t1=t2+t1%10;//��λ��
                t2=t1/10;//ʮλ��
                p->next=new ListNode(t1);
                p=p->next;
                l1=l1->next;
            }
        }
        if(l1->next==nullptr){
            while(l2->next!=nullptr){
                t1=l2->val+t2;
                t1=t2+t1%10;//��λ��
                t2=t1/10;//ʮλ��
                //np=new ListNode(t1,p);//��t1��������
                //p=new ListNode;
                //p=np;
                p->next=new ListNode(t1);
            p=p->next;
                l2=l2->next;
            }
        }
        if(l1==nullptr)
            v1=0;
        else
            v1=l1->val;
        if(l2==nullptr)
            v2=0;
            else
                v2=l2->val;
        t1=v1+v2; 
        t1=t2+t1%10;//��λ��
        t2=t1/10;//ʮλ��
        if(t2!=0){
            p->next=new ListNode(t1);
            p=p->next;
            p->next=new ListNode(t2);
        }
        else{
        p->next=new ListNode(t1);
        }
        return p;
    }
};
int main(){
    
}