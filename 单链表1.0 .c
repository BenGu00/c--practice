#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct linknode
{
	DataType data;
	struct linknode *next;
}LinkList;

LinkList *InitList(){
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head; 
}

void CreateListH(LinkList*head,int n){
	LinkList*s;
	int i;
	if(head==NULL){
		printf("错误：链表未初始化！\n");
		return ;
	}
	printf("请输入%d个整数： \n",n);
	for(i=0;i<n;i++){
		s=(LinkList*)malloc(sizeof(LinkList));
		if(s==NULL){
			printf("错误：内存分配错误！ \n");
			return ;
		}
		else{
			scanf("%d",&s->data);
			s->next=head->next;
			head->next=s;
		}
	}
	printf("建立单链表操作成功！\n");
}

void DisplayList(LinkList*head){
	LinkList*p=head->next;
	if(p==NULL){
		printf("链表为空！不能显示数据！\n");
		return ;
	}
	printf("当前链表内容(均从头节点进行输出)： \n");
	while (p!=NULL){
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
}

void Mune(){
	printf("========单链表操作菜单======== \n");
	printf("|      1. 头插法建立单链表    |\n");
    printf("|      2. 显示链表内容        |\n");
    printf("|      0. 退出                |\n");
    printf("===============================\n");
    printf("请输入编号：");
}

 int main(){
 	int n;
 	int chioce;
 	LinkList *head;
 	head=InitList();
 	if(head==NULL){
 		return -1;
	 }
	 do{
	 	Mune();
		 scanf("%d",&chioce);
		 switch(chioce){
		 	case 1:
		 		printf("请输入需要存储的数据个数： \n");
		 		scanf("%d",&n);
		 		CreateListH(head,n);
		 		break;
		 	case 2:
			    DisplayList	(head);
			    break;
			default:
			   printf("无效选项！ \n");    
		 } 
	 }while(chioce!=0);
 	return 0;
 }
