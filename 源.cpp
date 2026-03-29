#include <stdio.h >
int main() {
	int type = 0;
	printf("请输入数值:");
	scanf_s("%d", &type);
	switch (type) {
	case 1:printf("早上好！\n");
		break;
	case 2:printf("你好！\n");
		break;
	case 3:printf("中午好！\n");
		break;
	case 4:printf("再见！\n");
		break;
	default: printf("结束程序！\n");
		return  0;

	}
 }