#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUILDINGS_FILE_NAME "data.txt"

#define MAX_ID_LEN 100
#define MAX_NAME_LEN 100
#define MAX_INTRODUCTION_LEN 100

//构建结构体用于存储基本数据
typedef struct {
	char    buildings_id[MAX_ID_LEN];
	char    buildings_name[MAX_NAME_LEN];
} BuildingsInfo;

//构建链表
typedef struct node{
	BuildingsInfo data;
	struct node* next;
} BuildingsList;

//全局变量，存储当前建筑的数量
int CurrentCnt=0;

//读信息并返回结构体
BuildingsInfo read_buildings_info();         

//实现信息链表的初始化，从txt中读入信息保存至链表中
void init_list(BuildingsList **pL);      

//释放包括头结点在内的所有结点，完成后指向链表头结点的指针为NULL
void destory_list(BuildingsList **pL);

//调用destory_list释放包括头结点在内的所有结点，指向链表头结点的指针为NULL
//最后删除存储建筑信息的文件data.txt
void destory_list_and_file(BuildingsList **pL);

//将当前链表所有的建筑信息保存到文件 data.txt 
//其中L为指向链表头结点的指针，保存成功后，该函数返回建筑的数量。
int save_to_file(BuildingsList *L);

//显示结点为L的建筑信息
void output_one_item(BuildingsList *L);

//调用上面的函数
void output_all_items(BuildingsList *L);

//L为链表头结点的指针，函数根据choice的值，将item插入到链表的指定位置
//成功返回true，失败返回false
bool insert_item(BuildingsList *L, BuildingsInfo item, int choice);

//删除节点，L为指向链表表头结点的指针，id为要删除建筑的id
//成功返回true，失败返回false
bool delete_item(BuildingsList *L, char* buildings_id);

//查找链表，L为指向链表头结点的指针，id为要查找建筑的id
BuildingsList* search_item(BuildingsList *L, char* buildings_id);

//修改链表，L为指向链表头结点的指针，goods_id为要修改的建筑id
//new_info为该建筑的最新数据
bool change_item(BuildingsList *L, char* buildings_id, BuildingsInfo new_info);

//L为指向链表头结点的指针，该函数利用冒泡排序，按价格从低到高对建筑进行排序
void bubble_sort(BuildingsList *L);

//利用data.txt中的信息创建对应文件并进行信息输入
void open_file();

//读取函数用来取代部分场景下的scanf
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}


int main(void)
{
    BuildingsList *L;
    init_list(&L);
	BuildingsInfo new_item;
    char id[MAX_ID_LEN];
    while (1) {
	int choice;
	printf("             电子科技大学建筑信息管理系统\n");
	printf("**********************************************************\n");
	printf("                1.显示所有建筑的总览\n");//bug修订完成！
	printf("                2.修改某个建筑的信息\n");//bug修订完成！
	printf("                3.将建筑信息写入目录\n");//没问题了啊啊啊啊芜湖
	printf("                4.删除某个建筑的信息\n");//没问题
	printf("                5.查找某个建筑的信息\n");//没问题
	printf("                6.信息存盘并退出系统\n");//没问题
	printf("                7.对建筑的ID进行排序\n");//bug修好了
	printf("                8.删除所有初始化内容\n");//没问题
	printf("                9.将建筑信息写入文件\n");//没问题芜湖
	printf("警告！输入其他任意数字将清除缓存内容和建筑目录信息并退出系统！\n");//不能删除已有的信息文件
	printf("**********************************************************\n");
	printf("输入您的选择: ");

	scanf("%d", &choice);
	switch (choice) {
	  case 1:
		output_all_items(L);
        break;
	  case 2:
		new_item = read_buildings_info();//读取需要修改的信息
		printf("输入被修改的 ID:");
        read_line(id, MAX_ID_LEN);
        change_item(L, id, new_item);//替换信息
		break;
  	  case 3:
		new_item = read_buildings_info();
		int position;
		printf("输入数字表明你要将信息插入何处: 0.建筑列表尾部\n 1.建筑列表头部\n i.建筑列表中间第i号位置\n");
		scanf("%d", &position);
        insert_item(L,new_item,position);
		break;
	  case 4:
		printf("输入要删除的建筑ID: ");
		read_line(id, MAX_ID_LEN);
		delete_item(L,id);
		break;
	  case 5:
		printf("输入要查找的建筑ID: ");
		read_line(id, MAX_ID_LEN);
		BuildingsList* M=search_item(L,id);
		output_one_item(M);
		break;	
	  case 6:
		save_to_file(L);
		printf("您已经保留程序缓存并退出建筑信息管理系统!\n");
		return 0;
	  case 7:
		bubble_sort(L);
		break;
	  case 8:
		destory_list(&L);
		printf("您已经删除程序缓存!\n");
		break; 
	  case 9:
	    open_file();
	    break;
	  default:
	    destory_list_and_file(&L);
		printf("已删除程序缓存并退出建筑信息管理系统!\n");
		return 0;
	}
    }
}

void open_file(){
    FILE *fp;
	char name[100],intro[100];
	printf("请输入想打开的文件：");
	scanf("%s",name);
	fp=fopen(name,"w");
	printf("请输入建筑信息：");
	scanf("%s",intro);
	fprintf(fp,"%s",intro);
	fclose(fp);
	printf("信息录入成功！\n");
	return;

}

void init_list(BuildingsList **L) {
    FILE *fp;
    BuildingsInfo buildingsInfo;
    BuildingsList *p, *r,*temp;//p为临时链表

    (*L) = (BuildingsList *)malloc(sizeof(BuildingsList));
	//后面并没有进行销毁
	
    r = (*L);

	if(r==NULL)
	return;//内存分配失败的情况（一般不会）

    if ((fp = fopen(BUILDINGS_FILE_NAME, "r")) == NULL)//如果打开文件失败（文件不存在）
    {
        if ((fp = fopen(BUILDINGS_FILE_NAME, "w")) == NULL)//如果创建同样失败
	        printf("提示:不能创建建筑信息文件\n");
    }

    else
	{
        while (!feof(fp))//判断文件是否结束，未结束函数会返回0，反之为1
        {
            fscanf(fp, "%s", buildingsInfo.buildings_id);
            fscanf(fp, "%s", buildingsInfo.buildings_name);
			
            if(strcmp(temp->data.buildings_id,buildingsInfo.buildings_id)==0){
				fclose(fp);
                r->next = NULL;
				printf("建筑的链表文件已建立，有%d个建筑记录\n", CurrentCnt);
				return;
			}

			char name[100];
			sprintf(name,"%s.txt",buildingsInfo.buildings_name);
			if ((fopen(name, "r")) == NULL)//如果打开文件失败（文件不存在）
            {
               if ((fopen(name, "w")) == NULL)//如果创建同样失败
	            printf("提示:不能创建建筑文件\n");
            }

            p = (BuildingsList*)malloc(sizeof(BuildingsList));   //每次读取到一个结构体，就会进行相应的动态内存分配

            if (p == NULL) {
                return;
            }//内存分配失败的情况（一般不会）
           if(p){
            p->data = buildingsInfo;
            p->next = NULL;

            temp=p;

            r->next = p;
            r = p; 
			CurrentCnt++;  //r链表通过p链表不断递增
		   }
        }
    }
    fclose(fp);
    r->next = NULL;
	
    printf("建筑的链表文件已建立，有%d个建筑记录\n", CurrentCnt);
	
}



bool insert_item(BuildingsList *L, BuildingsInfo buildingsInfo, int choice) {
    BuildingsList *tempNode=L;
    BuildingsList *newNode=malloc(sizeof(BuildingsList));//记得malloc哦，不然debug会让你de到怀疑人生
	
	if(newNode==NULL){
		printf("false");
		return false;
	}                                //保险(免得debug)

	newNode->data=buildingsInfo;
	newNode->next=NULL;              //初始化该新建结点
    
	if (CurrentCnt >= 100) {
        printf("信息库已满(100),要插入请先删除一定量的建筑数据!\n");
        return false;
    }                                //保险（免得debug)  

    switch (choice) {
        case 0:
            if(L->next==NULL){
				L->data=buildingsInfo;
				CurrentCnt++;
				return true;
			}
			if(L->next!=NULL){
                tempNode=tempNode->next;
			}
			tempNode->next=newNode;
			CurrentCnt++;
			return true;
        //尾插法

        case 1:
            newNode->next = L->next;
            L->next = newNode;
            CurrentCnt++;
            return true;
        //头插法
		
		default:
	    if (choice <= CurrentCnt+1 && choice > 0) {
	        for (int i = 0; i < choice; i++){ 
				if(tempNode==NULL)
				return false;
				tempNode=tempNode->next;
 			} 
			if(tempNode==NULL)
				return false;
			newNode->next=tempNode->next;
			tempNode->next=newNode;
			CurrentCnt++;
			return true;
        //任意位置的插入
	    }
	else {
   	        printf("输入的位置超出当前建筑列表范围！\n");
            return false;
	    }
    }
}


bool delete_item(BuildingsList *L, char* buildings_id) {
     BuildingsList *p = L, *tempNode = p->next;
    while(tempNode!=NULL){
        if(strcmp(buildings_id,tempNode->data.buildings_id)==0){
			p->next=tempNode->next;
			free(tempNode);//销毁！！
			CurrentCnt--;
			return true;
		}
		tempNode=tempNode->next;
		p=p->next;
	}
	return false;
}


BuildingsList* search_item(BuildingsList *L, char* id) {
    BuildingsList *tempNode = L;
    while(tempNode!=NULL){
		if(strcmp(id,tempNode->data.buildings_id)==0){
			return tempNode;
		}
		tempNode=tempNode->next;
	}
	return NULL;
}

bool change_item(BuildingsList *L, char* id, BuildingsInfo new_info) {
   BuildingsList* tempnode = search_item(L,id);
    if(tempnode != NULL) {
       printf("成功进入循环！\n");
       tempnode->data = new_info;   
	   return true; 
    }
    return false;
	
}


void output_one_item(BuildingsList *p){
	if (p == NULL) {
        printf("error\n");
        return;
    }
    printf("id:%s\t\n", p->data.buildings_id);
    printf("name:%s\t\n", p->data.buildings_name);

}


void output_all_items(BuildingsList *L)
{
    if (L == NULL) {
        printf("程序内未找到任何建筑信息！\n");
        return;
    }

	BuildingsList* tempnode = L->next;
    while (tempnode != NULL) {
        output_one_item(tempnode);
        tempnode = tempnode->next;
    }
    return;
}


void destory_list(BuildingsList **L) {
	if (L == NULL || *L == NULL)
		return;
	BuildingsList *pre = *L, *p = (*L)->next;
	BuildingsList* ptemp = NULL;
    while (p != NULL) {
        ptemp = p->next;
        free(p);
        p = ptemp;
    }
    free(*L);
    *L = NULL;
    L = NULL;
    CurrentCnt = 0;
}


void destory_list_and_file(BuildingsList **L) {
    destory_list(L);
	remove(BUILDINGS_FILE_NAME);
}


int save_to_file(BuildingsList *L) {
    if(L == NULL)
        return 0;
    BuildingsList *p = L->next;
    FILE *fp;
    if ((fp = fopen("data.txt", "w")) == NULL)
    {
        printf("提示:不能打开建筑文件\n");
        return 0;
    }
    int save_count = 0;
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->data.buildings_id);
        fprintf(fp, "%s\t\n", p->data.buildings_name);
        p = p->next;
        save_count++;
    }
    fclose(fp);
    return save_count;
}


void bubble_sort(BuildingsList *L) {
   if(CurrentCnt==1||!CurrentCnt)return;
	
	for(int j=1;j<CurrentCnt;j++)
	for(BuildingsList* i=L;i->next->next!=NULL;i=i->next)
	{
		BuildingsList* a=i->next,*b=i->next->next;
		if(strcmp(a->data.buildings_id,b->data.buildings_id)>0)
		{
			BuildingsList* tem=b->next;
			i->next=b;
			b->next=a;
			a->next=tem;

        }
    }
	
}


BuildingsInfo read_buildings_info(){
	BuildingsInfo buildings;
	printf("输入建筑信息:\n");
	printf("建筑ID:");
	read_line(buildings.buildings_id, MAX_ID_LEN);
	printf("建筑名称:");
	read_line(buildings.buildings_name, MAX_NAME_LEN);
	return buildings;
}




