#include <stdio.h>
#include <stdlib.h>

typedef struct MyList *List;
struct MyList{
    int Num;
    List Next;
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n,counter=1;
        scanf("%d%d",&m,&n);
        if(m==1){
            printf("1\n");
        }
        else if(n==1){
            printf("%d\n",m);
        }
        else{

            List Last=(List)malloc(sizeof(struct MyList)),NewNode;
            Last->Num=m;Last->Next=Last;
            for(int i=m-1;i>=1;i--){
                NewNode=(List)malloc(sizeof(struct MyList));
                NewNode->Num=i;
                NewNode->Next=Last->Next;
                Last->Next=NewNode; 
            }

            List Cur=Last->Next;
            while(Cur!=Cur->Next){
                for(int i=0;i<(n-2);i++){
                    Cur=Cur->Next;
                }
      //          printf("%d out\n",Cur->Next->Num);
                Cur->Next=Cur->Next->Next;
                Cur=Cur->Next;
            }
            printf("%d\n",Cur->Num);
        }
    }
    return 0;
}
