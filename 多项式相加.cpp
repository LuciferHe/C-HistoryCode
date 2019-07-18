/*
Example1
输入：
3
59.50 4
-29.30 11
-66.20 17
5
-86.10 7
54.10 9
-78.40 12
70.70 17
57.60 18

输出：
y = [ 59*(x^4) ] + [ -86*(x^7) ] + [ 54*(x^9) ] + [ -29*(x^11) ] + [ -78*(x^12)] + [ 4*(x^17) ] + [ 57*(x^18) ]


Example2
输入：
2
-46.00 2
-7.70 9
3
62.70 0
-52.20 2
-23.50 11
输出：
y = [ 62*(x^0) ] + [ -98*(x^2) ] + [ -7*(x^9) ] + [ -23*(x^11) ]


Example3
输入：
3
-22.10 2
-74.30 9
-66.50 15
4
-31.60 7
-88.40 8
-33.50 15
20.70 22
输出：
y = [ -22*(x^2) ] + [ -31*(x^7) ] + [ -88*(x^8) ] + [ -74*(x^9) ] + [ -100*(x^15) ] + [ 20*(x^22) ]



Example4
输入：
3
-53.00 3
-1.50 4
-54.90 13
3
5.50 8
25.90 11
-21.50 18
输出：
y = [ -53*(x^3) ] + [ -1*(x^4) ] + [ 5*(x^8) ] + [ 25*(x^11) ] + [ -54*(x^13) ]+ [ -21*(x^18) ]*/

# include<stdio.h>
# include<stdlib.h>

struct Polynomials {
	float coef;
	int expn;
	struct Polynomials * next;
};


typedef struct Polynomials * pNode;

pNode CreatPolyn() {
	int n;
	int i, j;
	pNode head, p1, p2;
	if ((head = (pNode)malloc(sizeof(Polynomials))) == NULL){
		printf("No space!\n");
		exit(0);
	}
	head->coef = 0;
	head->expn = 0;
	head->next = NULL;
	p1 = p2 = head;
	printf("Please enter the lenth of the Polynomial.\n");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++){
		if ((p2 = (pNode)malloc(sizeof(Polynomials))) == NULL){
			printf("Can't find another space!\n");
			exit(0);
		}
		printf("Please enter the coef and expn of the %dth Polynomial.\n", i + 1);
		scanf_s("%f%d", &p2->coef, &p2->expn);
		p1->next = p2;
		p1 = p2;
	}
	p1->next = NULL;
	return head;
}

void DestroyPolyn(pNode p){
	pNode p1, p2;
	p1 = p2 = p;
	while (p2->next != NULL) {
		p2 = p1->next;
		p1->next = NULL;
		p1 = p2;
	}
}

void PrintPolyn(pNode p){
	pNode pointer;
	pointer = p;
	printf("y = ");
	if ((p->next) != NULL) pointer = p->next;
	else printf("The Polynomial is empty!\n");
	while (pointer->next != NULL) {
		printf("[ %d*(x^%d) ] + ", (int)pointer->coef, pointer->expn);
		pointer = pointer->next;
	}
	printf("[ %d*(x^%d) ]\n", (int)pointer->coef, pointer->expn);
}

int PolynLength(pNode p){
	int n = 0;
	pNode pointer;
	pointer = p;
	while ((pointer->next) != NULL)  { n++; pointer = pointer->next; }
	return n;
}

int Compare(int a, int b){
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}


void InsertNode(pNode head, pNode tail, pNode p, pNode qa){
	pNode p1, p2;
	p1 = head;
	p2 = head->next;
	while (p2 != NULL && p2 != tail->next){
		if (!Compare(p2->expn, p->expn)){
			p2->coef += p->coef;
			free(p);
			break;
		}
		if (Compare(p2->expn, p->expn) >0){
			p->next = p2;
			p1->next = p;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == tail){
		p->next = qa;
		p1->next = p;
		head = p;
	}
}


void AddPolyn(pNode Pa, pNode Pb) {  // 算法2.23
	// 多项式加法：Pa = Pa＋Pb，利用两个多项式的结点构成"和多项式"。
	pNode ha, hb, qa, qb;
	int a, b, temp;
	float sum;
	ha = Pa;      // ha和hb分别指向Pa和Pb的头结点
	hb = Pb;
	qa = Pa->next;   // qa和qb分别指向La和Lb中当前结点
	qb = Pb->next;
	while (qa && qb) {     // Pa和Pb均非空
		a = qa->expn; // a和b为两表中当前比较元素
		b = qb->expn;
		switch (Compare(a, b)) {
		case -1:  // 多项式PA中当前结点的指数值小
			ha = qa;
			qa = qa->next;
			break;
		case 0:   // 两者的指数值相等
			sum = qa->coef + qb->coef;
			if (sum != 0.0) {  // 修改多项式PA中当前结点的系数值
				qa->coef = sum;
				ha = qa;
			}
			else {  // 删除多项式PA中当前结点
				ha->next = qa->next;
				free(qa);
			}
			hb->next = qb->next;
			free(qb);
			qb = hb->next;
			qa = ha->next;
			break;
		case 1:   // 多项式PB中当前结点的指数值小
			hb->next = qb->next;
			InsertNode(Pa, ha, qb, qa);
			qb = hb->next;
			ha = ha->next;
			break;
		} // switch
	} // while
	if (qb != NULL) ha->next = qb;;   // 链接Pb中剩余结点
	free(hb);  // 释放Pb的头结点
	PrintPolyn(Pa);
} // AddPolyn




int main(){
	pNode Pa, Pb;
	while (1)
	{
		Pa = CreatPolyn();
		Pb = CreatPolyn();
		AddPolyn(Pa, Pb);
		//DestroyPolyn(p);
		//PrintPolyn( p );
		//printf("%d\n", PolynLength(p));
	}
	return 0;
}