/*Sky从小喜欢奇特的东西，而且天生对数字特别敏感，一次偶然的机会，他发现了一个有趣的四位数2992，这个数，它的十进制数表示，其四位数字之和为2+9+9+2=22，它的十六进制数BB0，其四位数字之和也为22，同时它的十二进制数表示1894，其四位数字之和也为22，啊哈，真是巧啊。Sky非常喜欢这种四位数，由于他的发现，所以这里我们命名其为Sky数。但是要判断这样的数还是有点麻烦啊，那么现在请你帮忙来判断任何一个十进制的四位数，是不是Sky数吧。
现在我们输入一个四位数，它到底是不是Sky数呢？*/
# include<stdio.h>
# include<string.h>

int sumary( int num, int x )
{
	int sum = 0;
	while ( num!=0 )
	{
		sum += num%x;
		num /= x;
	}
	return sum;
}


int main ()
{
	int num;
	while (scanf("%d", &num) == 1 && num){
	int a = sumary(num, 16);
	int b = sumary(num, 10);
	int c = sumary(num, 12);
	if (a == b && b == c){
		printf("%d is a Sky Number.\n", num);
	}//if
	else
		printf("%d isn't a Sky Number.\n", num);
	}//while
	return 0;
}







