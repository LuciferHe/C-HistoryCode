# include<stdio.h>
# include<stdlib.h>
const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

struct StackLink{
	int * base;
	int * top;
	int stacksize;
};

typedef struct StackLink SqStack;

int InitStack(SqStack * S){
	S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S->base) exit(0);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return 1;
}//¹¹ÔìÒ»¸ö¿ÕÕ»S

int Push(SqStack * S, int e){
	if (S->top - S->base >= S->stacksize){
		//Õ»Âú£¬×·¼Ó´æ´¢¿Õ¼ä
	}
	*S->top = e;
	S->top++;
	return 1;
}//²åÈëÕ»¶¥ÔªËØ

int Pop(SqStack * S, int *e){
	if (S->top == S->base) return 0;
	*e = *(S->top-1);
	S->top = S->top - 1;
	return 1;
}//ÈôÕ»²»¿Õ£¬ÔòÉ¾³ýSµÄÕ»¶¥ÔªËØ


int StackEmpty(SqStack *S){
	if (S->base == S->top) return 1;
	return 0;
}


void conversion( int Num,int radix ) {
	int e;
	int *E = &e;
	SqStack ExampleStack;
	SqStack * S = &ExampleStack;
	InitStack(S);
	while (Num) {
		Push(S,Num%radix);
		Num /= radix;
	}
	while (!StackEmpty(S)){
		Pop(S,E);
		printf("%d",e);
	}
	printf("\n");
}

int main()
{
	int n, radix;
	while (scanf_s("%d%d", &n, &radix) == 2)
		conversion(n,radix);
	return 0;
}