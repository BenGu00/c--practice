#include<stdio.h>
void f(int* p) {
	scanf_s("%d", p);        // p是代表一个地址，而*p则是一个值。
	printf(" p=%p \n", p);    //而scanf这个函数需要的是一个地址，&这个运算符是运算的是那个值的地址。
	printf("*p=%d \n", *p);
	*p = 99;
}
void g(int j) {
	printf("j=%d \n", j);
}
/*
  在主函数main里，虽然先定义了一个变量i，并且将6这个值赋值给了i
  并且将i的地址也就是做&运算，传给了f函数i的地址
  后又在f函数中进行scanf函数调用i的地址并且进行输入
  所以在f函数中*p!=6  在main函数中输出的i!=6,  又因为在f函数中将99赋值给了*p
  所以 在f函数中输出的*p=scanf函数输入的值     而在main函数中输出的 i！=scanf函数输入的值  而是i=99
*/
int main() {
	int i;
	i = 6;
	f(&i);
	g(i);
	printf("&i=%p \n", &i);
	printf(" i=%d \n", i);
	return 0;
}