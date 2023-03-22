#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include <ctype.h>


#define MAX 100

#define GOODS_FILE_NAME "goodsinfo.txt"


#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30


typedef struct {
	char    goods_id[MAX_ID_LEN];
	char    goods_name[MAX_NAME_LEN];
	int     goods_price;
	char    goods_discount[MAX_DISCOUNT_LEN];
	int     goods_amount;
	int     goods_remain;
} GoodsInfo;//构建结构体用于存储基本数据

typedef struct node
{
	GoodsInfo data;
	struct node* next;
} GoodsList;//构建链表


int CurrentCnt;
//全局变量，存储当前商品的数量


GoodsInfo read_goods_info();         
//读信息并返回结构体

void init_list(GoodsList **pL);      
//实现信息链表的初始化，从txt中读入信息保存至链表中

void destory_list(GoodsList **pL);
//释放包括头结点在内的所有结点，完成后指向链表头结点的指针为NULL

void destory_list_and_file(GoodsList **pL);
//调用destory_list释放包括头结点在内的所有结点，指向链表头结点的指针为NULL
//最后删除存储商品信息的文件goodinfo.txt

int save_to_file(GoodsList *L);
//将当前链表所有的商品信息保存到文件 goodsinfo.txt 
//其中L为指向链表头结点的指针，保存成功后，该函数返回商品的数量。

void output_one_item(GoodsList *L);
//显示结点为L的商品信息

void output_all_items(GoodsList *L);
//调用上面的函数

bool insert_item(GoodsList *L, GoodsInfo item, int choice);
//L为链表头结点的指针，函数根据choice的值，将item插入到链表的指定位置
//成功返回true，失败返回false

bool delete_item(GoodsList *L, char* goods_id);
//删除节点，L为指向链表表头结点的指针，id为要删除商品的id
//成功返回true，失败返回false

GoodsList* search_item(GoodsList *L, char* goods_id);
//查找链表，L为指向链表头结点的指针，id为要查找商品的id

bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
//修改链表，L为指向链表头结点的指针，goods_id为要修改的商品id
//new_info为该商品的最新数据

void bubble_sort(GoodsList *L);
//L为指向链表头结点的指针，该函数利用冒泡排序，按价格从低到高对商品进行排序



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
    GoodsList *L;
    init_list(&L);
	GoodsInfo new_item;
    char id[MAX_ID_LEN];
    while (1) {
	int choice;
	printf("              超市商品管理系统\n");
	printf("********************************************\n");
	printf("            1.显示所有商品的信息\n");
	printf("            2.修改某个商品的信息\n");
	printf("            3.插入某个商品的信息\n");
	printf("            4.删除某个商品的信息\n");
	printf("            5.查找某个商品的信息\n");
	printf("            6.商品存盘并退出系统\n");
	printf("            7.对商品价格进行排序\n");
	printf("            8.(慎用)删除所有内容\n");
	printf("警告！输入其他任意数字将清除所有内容并退出系统！\n");
	printf("********************************************\n");
	printf("输入您的选择: ");

	scanf("%d", &choice);
	switch (choice) {
	  case 1:
		output_all_items(L);
        break;
	  case 2:
		new_item = read_goods_info();//读取需要修改的信息
		printf("输入被修改的 ID:");
        read_line(id, MAX_ID_LEN);
        change_item(&L, id, new_item);//替换信息
		break;
  	  case 3:
		new_item = read_goods_info();
		int position;
		printf("输入数字表明你要插入的商品位置: 0.商品列表尾部\n 1.商品列表头部\n i.商品列表中间第i号位置\n");
		scanf("%d", &position);
        insert_item(L,new_item,position);
		break;
	  case 4:
		printf("输入要删除记录的 ID:");
		read_line(id, MAX_ID_LEN);
		delete_item(L,id);
		break;
	  case 5:
		printf("输入要删除记录的 ID:");
		read_line(id, MAX_ID_LEN);
		search_item(L,id);
		break;	
	  case 6:
		save_to_file(L);
		printf("您已经存盘并退出超市商品管理系统!\n");
		return 0;
	  case 7:
		bubble_sort(L);
		break;
	  case 8:
		destory_list(&L);
		printf("您已经删除商品文件内容以及链表内容!\n");
		break;
	  default:
	    destory_list_and_file(&L);
		//printf("已删除所有信息并退出超市商品管理系统!\n");
		return 0;
	}
    }
}


void init_list(GoodsList **L) {
    FILE *fp;
    GoodsInfo goodsInfo;
    GoodsList *p, *r;//p为临时链表

    (*L) = (GoodsList *)malloc(sizeof(GoodsList));
	//这里进行动态内存分配，但是不对它进行销毁，以便于后面的函数继续使用
	//反正一直会用
	//反正程序结束内存都会被回收

    r = (*L);

	if(r==NULL)
	return;//内存分配失败的情况（一般不会）

    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL)//如果打开文件失败（文件不存在）
    {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)//如果创建同样失败
	        printf("提示:不能创建商品文件\n");//寄！！！（一般不会）
    }
    else {
        while (!feof(fp))//判断文件是否结束，未结束函数会返回0，反之为1
        {
            fscanf(fp, "%s", goodsInfo.goods_id);
            fscanf(fp, "%s", goodsInfo.goods_name);
            fscanf(fp, "%d", &goodsInfo.goods_price);
            fscanf(fp, "%s", goodsInfo.goods_discount);
            fscanf(fp, "%d", &goodsInfo.goods_amount);
            fscanf(fp, "%d\t", &goodsInfo.goods_remain);
            p = (GoodsList*)malloc(sizeof(GoodsList));

            if (p == NULL) {
                return;
            }//内存分配失败的情况（一般不会）

            p->data = goodsInfo;
            p->next = NULL;
            r->next = p;
            r = p;     //r链表通过p链表不断递增
            CurrentCnt++;
        }
    }
    fclose(fp);
    r->next = NULL;
    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}



bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice) {
    GoodsList *tempNode=L;
    GoodsList *newNode=malloc(sizeof(GoodsList));
	//这里也不进行销毁
    int i;

	if(newNode==NULL){
		return false;
	}

	newNode->data=goodsInfo;
	newNode->next=NULL;
    
	if (CurrentCnt >= 100) {
        printf("信息库已满(100),要插入请先删除一定量的商品数据!\n");
        return false;
    }//保险措施

    switch (choice) {
        case 0:
            if(tempNode==NULL){
				L->data=goodsInfo;
				CurrentCnt++;
				return true;
			}
			while(L->next!=NULL){
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
            return true;//头插法
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
	    }//任意位置的插入
	else {
   	        printf("输入的位置超出当前商品列表范围\n");
            return false;
	    }
    }
}




bool delete_item(GoodsList *L, char* goods_id) {
     GoodsList *p = L, *tempNode = p->next;
    while(tempNode!=NULL){
        if(strcmp(goods_id,tempNode->data.goods_id)==0){
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



GoodsList* search_item(GoodsList *L, char* goods_id) {
    GoodsList *tempNode = L;
    while(tempNode!=NULL){
		if(strcmp(goods_id,tempNode->data.goods_id)==0){
			return tempNode;
		}
		tempNode=tempNode->next;
	}
	return NULL;
}

bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info) {
    GoodsList* tempnode = L;
    while (tempnode != NULL) {
        if (strcmp(goods_id, tempnode->data.goods_id) == 0) {
            tempnode->data = new_info;
            return true;
        }
        tempnode = tempnode->next;
	 }
	return false;
}



void output_one_item(GoodsList *p){
	if (p == NULL) {
        printf("error");
        return;
    }
    printf("id:%s                  ", p->data.goods_id);
    printf("name:%s                ", p->data.goods_name);
    printf("price:%d               ", p->data.goods_price);
    printf("discount%s             ", p->data.goods_discount);
    printf("amount:%d              ", p->data.goods_amount);
    printf("remain:%d            \n", p->data.goods_remain);
    return;
}






void output_all_items(GoodsList *L)
{
	 GoodsList* tempnode = L->next;
    if (L == NULL) {
        printf("error");
        return;
    }
    while (tempnode != NULL) {
        output_one_item(tempnode);
        tempnode = tempnode->next;
    }
    return;
}



void destory_list(GoodsList **L) {
	if (L == NULL || *L == NULL)
		return;
	GoodsList *pre = *L, *p = (*L)->next;
	GoodsList* ptemp = NULL;
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


void destory_list_and_file(GoodsList **L) {
    destory_list(L);
	remove(GOODS_FILE_NAME);
}

int save_to_file(GoodsList *L) {
    if(L == NULL)
        return 0;
    GoodsList *p = L->next;
    FILE *fp;
    if ((fp = fopen("goodsinfo.txt", "w")) == NULL)
    {
        printf("提示:不能打开商品文件\n");
        return 0;
    }
    int save_count = 0;
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->data.goods_id);
        fprintf(fp, "%s\t", p->data.goods_name);
        fprintf(fp, "%d\t", p->data.goods_price);
        fprintf(fp, "%s\t", p->data.goods_discount);
        fprintf(fp, "%d\t", p->data.goods_amount);
        fprintf(fp, "%d\t", p->data.goods_remain);
        p = p->next;
        save_count++;
    }
    fclose(fp);
    return save_count;
}



void bubble_sort(GoodsList *L) {
    GoodsList *p;
    GoodsInfo temp;
    int n = CurrentCnt;
    int i, j;
    
    if (L == NULL || L->next == NULL)
        printf("当前链表中没有商品\n");
    for (j = 1; j < n; ++j) {
        p = L->next;
        for (i = 0; i < n - j; ++i) {
            if (p->data.goods_price > p->next->data.goods_price) {
	/* 补充代码*/
            }
            p = p->next;
        }
    }
}



GoodsInfo read_goods_info(){
	GoodsInfo goods;
	printf("输入你要插入的商品信息:\n");
	printf("商品ID:");
	read_line(goods.goods_id, MAX_ID_LEN);
	printf("商品名称:");
	read_line(goods.goods_name, MAX_NAME_LEN);
	printf("商品价格:");
	scanf("%d",&goods.goods_price);
	printf("商品折扣:");
	read_line(goods.goods_discount, MAX_DISCOUNT_LEN);
	printf("商品数量:");
	scanf("%d", &goods.goods_amount);
	printf("商品剩余:");
	scanf("%d", &goods.goods_remain);
	return goods;
}




