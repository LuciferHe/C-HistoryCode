/*
姓名：王冰
学号：13101020125
班级：计13-1
*/

# include <stdio.h> 
int main ()
{
	int a[4] = {3,5,8,9};
	int b[4];
	int i, j;
	int count;
	int level = 0;
	printf ( "游戏规则：猜个4不同的正整数，如果该位置和数字都正确则为Y，\
如果该位置和数字都错误则为N,数字正确但位置不对则为T\n");
	while (1)
	{
		count = 0;
		printf ( "请分别输入4个不同的正整数，数字之间以空格分开:" );
		scanf ( "%d%d%d%d", &b[0],&b[1],&b[2],&b[3] );
		for ( i=0; i<4; i++ )
		{
			if ( b[i]==a[i] )
				{
					count++;
					printf ( "Y " );
				}
			else
				{
					for ( j=0; j<4; j++ )
					{
						if( b[i] == a[j] )
						{
							printf ( "T " );
							break;
						}
					}
					if ( j==4 )
					{
						printf ( "N " );
					}
				}
		}
		if ( i==4 )
			printf ( "\n" );
		level++;
		if ( count==4 )
		{
			printf ( "恭喜你答对了。\n" );
			if( level<4 ) 
			printf ( "你很聪明，你已经成功击败全国98%%的选手。\n" );
			else if ( level>3 && level <10 )
				printf ( "不错，你已经成功击败全国80%%的选手。\n" );
			else if ( level>9 && level <20 )
				printf ( "不错，你已经成功击败全国70%%的选手。\n" );
			else if ( level>19 && level <70 )
				printf ( "不错，你已经成功击败全国30%%的选手。\n" );
			break;
		}
		else 
		{
			printf ( "\n再试一次吧。\n" );
		}
	}
	return 0;
}


