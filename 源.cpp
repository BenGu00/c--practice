#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct linknode {
    DataType data;
    struct linknode* next;
} LinkList;

// 初始化链表
LinkList* InitList() {
    LinkList* head;
    head = (LinkList*)malloc(sizeof(LinkList));
    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}

// 头插法建立单链表
void CreateListH(LinkList* head, int n) {
    LinkList* s;
    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }
    int i;
    printf("请输入%d个整数： \n", n);
    for (i = 0; i < n; i++) {
        s = (LinkList*)malloc(sizeof(LinkList));
        if (s == NULL) {
            printf("错误：单链表内存分配错误！\n");
            return;
        }
        scanf_s("%d", &s->data);
        s->next = head->next;
        head->next = s;
    }
    printf("头插法建立单链表成功！ \n");
}

// 尾插法建立单链表
void CreateListL(LinkList* head, int n) {
    LinkList* s, * last;
    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }
    last = head;
    int i;
    printf("请输入%d个元素： \n", n);
    for (i = 0; i < n; i++) {
        s = (LinkList*)malloc(sizeof(LinkList));
        if (s == NULL) {
            printf("错误：单链表内存分配错误！\n");
            return;
        }
        scanf_s("%d", &s->data);
        s->next = NULL;
        last->next = s;
        last = s;
    }
    printf("尾插法建立单链表成功 \n");
}

// 求链表长度
int LengthList(LinkList* head) {
    LinkList* p;
    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return 0;
    }
    p = head->next;
    int j = 0;
    while (p != NULL) {
        p = p->next;
        j++;
    }
    return j;
}

// 按值查找结点位置
void Locate(LinkList* head, DataType x) {
    LinkList* p;
    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }
    int j = 1;
    p = head->next;
    while (p != NULL && p->data != x) {
        p = p->next;
        j++;
    }
    if (p != NULL) {
        printf("在第%d位上找到元素值为%d的结点 ! \n", j, x);
    }
    else {
        printf("未找到值为%d的结点！\n", x);
    }
}

// 按序号查找结点
void SearchList(LinkList* head, int i) {
    LinkList* p;
    int j = 1;

    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }

    if (i < 1 || i > LengthList(head)) {
        printf("错误：位置输入不合法！\n");
        return;
    }

    p = head->next;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }

    if (j == i && p != NULL) {
        printf("第%d个位置的元素值为%d !\n", i, p->data);
    }
}

// 按序号插入元素结点
void InsList(LinkList* head, int i, DataType x) {
    LinkList* p, * s;
    p = head;
    int j = 0;

    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }

    if (i < 1) {
        printf("插入失败！位置必须大于等于1！\n");
        return;
    }

    // 找到第i-1个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p != NULL) {
        s = (LinkList*)malloc(sizeof(LinkList));
        if (s == NULL) {
            printf("错误：单链表内存分配错误！\n");
            return;
        }
        s->data = x;
        s->next = p->next;  // 新结点指向原第i个结点
        p->next = s;        // 第i-1个结点指向新结点
        printf("值为%d的元素插入成功！\n", x);
    }
    else {
        printf("插入失败！位置不存在！\n");
    }
}

// 按序号删除元素结点
void DelList(LinkList* head, int i) {
    int j = 0;
    DataType x;
    LinkList* p, * s;
    p = head;

    if (head == NULL || head->next == NULL) {
        printf("链表为空，删除失败！\n");
        return;
    }

    if (i < 1) {
        printf("删除失败！位置必须大于等于1！\n");
        return;
    }

    // 找到第i-1个结点
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next != NULL && j == i - 1) {
        s = p->next;
        x = s->data;
        p->next = s->next;
        free(s);
        printf("删除第%d上的元素值为%d成功\n", i, x);
    }
    else {
        printf("删除失败！位置不存在！\n");
    }
}

// 输出单链表
void DisList(LinkList* head) {
    LinkList* p;

    if (head == NULL) {
        printf("错误：链表初始化错误！\n");
        return;
    }

    p = head->next;
    if (p == NULL) {
        printf("链表为空！\n");
        return;
    }

    printf("当前链表元素：");
    while (p != NULL) {
        printf("%5d", p->data);
        p = p->next;
    }
    printf("\n");
}

// 显示菜单
void Menu() {
    printf("\n======单链表操作=========\n");
    printf("|1.头插法建立单链表     |\n");
    printf("|2.输出单链表           |\n");
    printf("|3.尾插法建立单链表     |\n");
    printf("|4.输出单链表长度       |\n");
    printf("|5.按值查找结点位置     |\n");
    printf("|6.按序号查找结点       |\n");
    printf("|7.按序号插入元素结点   |\n");
    printf("|8.按序号删除元素结点   |\n");
    printf("|0.退出程序             |\n");
    printf("=========================\n");
    printf("   请选择菜单编号: ");
}

// 释放链表内存
void FreeList(LinkList* head) {
    LinkList* p, * q;
    if (head == NULL) {
        return;
    }
    p = head->next;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    free(head);
}

// 主函数
int main() {
    LinkList* head;
    int choice;
    int n, i;
    DataType x;

    // 初始化链表
    head = InitList();
    if (head == NULL) {
        printf("链表初始化失败，程序退出！\n");
        return -1;
    }

    do {
        Menu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入元素个数：\n");
            scanf_s("%d", &n);
            CreateListH(head, n);
            break;

        case 2:
            DisList(head);
            break;

        case 3:
            printf("请输入元素个数：\n");
            scanf_s("%d", &n);
            CreateListL(head, n);
            break;

        case 4:
            printf("链表长度为：%d\n", LengthList(head));
            break;

        case 5:
            printf("请输入要查找的元素值：\n");
            scanf_s("%d", &x);
            Locate(head, x);
            break;

        case 6:
            printf("请输入要查找的元素位置：\n");
            scanf_s("%d", &i);
            SearchList(head, i);
            break;

        case 7:
            printf("请输入插入元素的位置和元素值（位置 值）：\n");
            scanf_s("%d %d", &i, &x);
            InsList(head, i, x);
            DisList(head);
            break;

        case 8:
            printf("请输入删除元素的位置：\n");
            scanf_s("%d", &i);
            DelList(head, i);
            DisList(head);
            break;

        case 0:
            printf("程序退出，感谢使用！\n");
            break;

        default:
            printf("输入错误，请重新选择（0-8）！\n");
        }
    } while (choice != 0);

    // 释放链表内存
    FreeList(head);

    return 0;
}