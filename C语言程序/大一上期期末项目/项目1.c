#include<stdio.h>
#include<stdbool.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
 
#define MAXSIZE 100
#define ElemType int
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
 
void lnk_merge(LinkList A, LinkList B, LinkList C) {
       LinkList m = A->next;
    LinkList n = B->next;
    C->next=m;
    LinkList P;
    while(1){
          P=n->next;
        if(m==NULL){
        m=n;
        break;
        }
      
        n->next=m->next;
        m->next=n;
       
         
         if(P==NULL){
             break;
         }
         n=P;
         m=m->next->next;
         
        
    }
   

}
 
 
 
 
 
 
//初始化链表
void init_list(LinkList *L)
{
    *L=(Node*)malloc(sizeof(Node));
    (*L)->next=NULL;
}
//打印链表
void print_list1(LinkList L)
{
    Node *p=L->next;
    int i=0;
    while(p!=NULL)
    {
        if(i==0){
            printf("head-->");
            i++;
            p=p->next;
        }else{
        printf(" %d ",p->data);
        p=p->next;
        if(p) printf("-->");
        }
    }
    printf("\n");
}
//打印链表
void print_list2(LinkList L)
{
    Node *p=L->next;
    int i=0;
    while(p!=NULL)
    {
        if(i==0){
            printf("head-->");
            i++;
            p=p->next;
        }
        else if(i==1){
            i++;
            p=p->next;
        }//防止重复输出头节点
        else{
        printf(" %d ",p->data);
        p=p->next;
        if(p) printf("-->");
        }
    }
    printf("\n");
}
//尾插法读入链表(含头节点)
void tail_insert(LinkList *L,ElemType elem[],int len)
{
 
    Node *p,*q;
    p=(Node*)malloc(sizeof(Node));
    p->data=-256;
    p->next=NULL;
    q=(*L);
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=p;
    q=q->next;
    for(int i=0;i<len;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        p->data=elem[i];
        p->next=NULL;
        q->next=p;
        q=p;
    }
    //(*L)=(*L)->next;
}
 
 
int main(){
//--------以 下 内 容 可 以 修 改----------
    ElemType elem1[]={0,1,4,5,6,7};
    ElemType elem2[]={3,4,5,6,7,7,8};
 
    //读入链表的数据，会自动转化为链表，必须为int，elem1与elem2代表链表A、B
    //数据需要大于-256，我们以-256代表头节点，否则可能造成输出错误
 
 
    //修改下方的true或false以控制程序是否运行
    bool choice=true;//true为运行，false为不运行
    
 
//--------以 上 内 容 可 以 修 改----------
    printf("--icoding--\n");
    printf("链表合并(3)\n一般认为有头节点,此处头节点值为-256\n");
    LinkList L1,L2,L3;
 
    
    
    int len1=sizeof(elem1)/sizeof(elem1[0]);
    int len2=sizeof(elem2)/sizeof(elem2[0]);
    
 
 
    init_list(&L1);
    tail_insert(&L1,elem1,len1);
    init_list(&L2);
    tail_insert(&L2,elem2,len2);
    init_list(&L3);
    printf(">>初始化链表\n");
    
    printf("链表1 | ");
    print_list1(L1);
    printf("链表2 | ");
    print_list1(L2);
 
    if(choice){
        printf(">>合并链表\n");
        lnk_merge(L1,L2,L3);
        printf("合并后| ");
        print_list2(L3);
    }
 
 
    printf("\n\n本程序仅输出结果，不判断结果正确与否\n----测试结束----\n");
    return 0;
}



