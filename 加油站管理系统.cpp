//#include "stdafx.h"
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>

const int MAXN = 20;

struct deal
{
	int card_number;
	double transactionMoney;
	char transactionTime[MAXN + 1];
	char transactionType[MAXN];
	char oilStation[MAXN];
	char workername[MAXN];
	double balance;
};

struct oil
{
	char oilName[MAXN];
	char oilType[MAXN];
	double oilPrice;
};

struct card
{
	int  cardNumber;
	char clientName[MAXN];
	char clientAdress[MAXN];
	char clientID[MAXN];
	char clientMobile[MAXN];
	double balance;
};

/* 函数原型 */
int  enterChoice();
void newOilRecord();
void changeOilRecord();
void deleteOilRecord();
void displayOilRecord();
double  oilSearch(char a[], char b[]);//辅助函数，验证油品是否存在, 若存在就返回油品价格

void newCardRecord();
void changeCardRecord();
void charge();
int judge(int, double);//辅助函数，验证卡号是否存在和余额是否充足
void consume();
void displayCardRecord();
void deleteCardRecord();
void searchCardRecord();

void systemTime(char * a);//辅助函数，获取系统时间，自动保存为交易时间
void newCardDealRecord(struct deal);//辅助函数，自动新建交易记录
void displayCardDealRecord();
void searchCardDealRecord();


int main()
{
	int choice;  /* 用于设置用户进行选择不同功能 */

	while ( (choice = enterChoice()) && choice < 14 )
	{

		switch (choice)
		{
		case 1: newOilRecord(); break;
		case 2: changeOilRecord(); break;
		case 3: deleteOilRecord(); break;
		case 4: displayOilRecord(); break;
		case 5: newCardRecord(); break;
		case 6: changeCardRecord(); break;
		case 7: charge(); break;
		case 8: consume(); break;
		case 9: displayCardRecord(); break;
		case 10: deleteCardRecord(); break;
		case 11: searchCardRecord(); break;
		case 12: displayCardDealRecord(); break;
		case 13: searchCardDealRecord(); break;
			/* display message if user does not select valid choice */
		default: printf("Incorrect choice\n"); break;
		} /* end switch */
	} /* end while */
	return 0;	/* indicates successful termination */
} /* end main */


/* 用户菜单选择 */
int enterChoice()
{
	int menuChoice; /* 存储用户菜单的选择 */

	/* 显示可选的菜单 */
	printf("\n油品记录:\n");
	printf("\t1——添加\n");
	printf("\t2——修改\n");
	printf("\t3——删除\n");
	printf("\t4——全部显示\n");
	printf("\n加油卡记录:\n");
	printf("\t5——添加\n");
	printf("\t6——修改\n");
	printf("\t7——充值\n");
	printf("\t8——汽车加油\n");
	printf("\t9——全部显示\n");
	printf("\t10——删除\n");
	printf("\t11——查找\n");
	printf("\n交易记录:\n");
	printf("\t12——显示全部\n");
	printf("\t13——条件查找\n");
	printf("\n0 ——— 退出程序\n");
	printf("\n您的选择:");

	scanf("%d", &menuChoice); /* 接受用户的选择 */
	return menuChoice;
}

/* 创建新油品纪录 */
void newOilRecord()
{
	FILE *fPtr;
	int panduan, xuanze;
	struct oil temp = { "", "", 0.0 };
	char oilNameTemp[MAXN] = { '\0' };
	char oilTypeTemp[MAXN] = { '\0' };

	if ((fPtr = fopen("oil_base.dat", "ab+")) == NULL)
	{
		printf("写入油品信息文件有误\n");
		exit(0);
	}
	while (1)
	{
		printf("请您输入新的油品名称:");
		scanf("%s", oilNameTemp);
		printf("\n请您输入新的油品型号:");
		scanf("%s", oilTypeTemp);

		rewind(fPtr);
		panduan = 0;							 /* 判断账号是否存在 */
		while ((fread(&temp, sizeof(struct oil), 1, fPtr)) != (int)NULL)
		{
			if (!strcmp(temp.oilName, oilNameTemp) && !strcmp(temp.oilType, oilTypeTemp))
			{
				printf("\n\n对不起,该种类油品已存在!");
				panduan = 1;				 /* 说明该账号不能保存  */
				break;
			}
		}
		if (panduan == 0)                   /* 说明该账号可以保存新增纪录  */
		{
			printf("\n请您输入新的油品价格: ");
			scanf("%lf", &temp.oilPrice);
			strcpy(temp.oilName, oilNameTemp);
			strcpy(temp.oilType, oilTypeTemp);
			fseek(fPtr, 0, SEEK_END);
			fwrite(&temp, sizeof(struct oil), 1, fPtr);
			printf("\n 保存油品信息成功 ");
		}
		printf("\n\n是否继续录入信息:是:1;否:0;请选择:");
		scanf("%d", &xuanze); printf("\n");
		if (xuanze != 1) break;
	}
	fclose(fPtr);
}//newOilRecord

/* 修改油品价格 */
void changeOilRecord()
{
	FILE *fPtr;
	int i, panduan;         /* 保存账号的有关信息 */
	struct oil temp = { "", "", 0.0 };
	char oilNameTemp[MAXN] = { '\0' };
	char oilTypeTemp[MAXN] = { '\0' };			 /*  用于保存交易的金额 */

	printf("请您输入油品名称:");
	scanf("%s", oilNameTemp);
	printf("\n请您输入油品型号:");
	scanf("%s", oilTypeTemp);

	if ((fPtr = fopen("oil_base.dat", "rb+")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	i = 0;
	panduan = 0;
	while ((fread(&temp, sizeof(struct oil), 1, fPtr)) != (int)NULL)
	{
		if (!strcmp(temp.oilName, oilNameTemp) && !strcmp(temp.oilType, oilTypeTemp))
		{
			panduan = 1;
			printf("\n请您输入更新的油品价格: ");
			scanf("%lf", &temp.oilPrice);
			fseek(fPtr, i * sizeof(struct oil), SEEK_SET);
			fwrite(&temp, sizeof(struct oil), 1, fPtr);
			break;
		}// end if
		i++;
	}
	if (panduan == 0) printf("\n\n error:对不起,您输入的油品种类错误\n");
	else           printf("\n\n 修改成功\n");
	fclose(fPtr);
} //changeOilRecord

/* 删除油品记录 */
void deleteOilRecord()
{
	FILE *fPtr, *fPtr1;
	int panduan;       
	struct oil temp = { "", "", 0.0 };
	char oilNameTemp[MAXN] = { '\0' };
	char oilTypeTemp[MAXN] = { '\0' };

	printf("请您输入油品名称:");
	scanf("%s", oilNameTemp);
	printf("\n请您输入油品型号:");
	scanf("%s", oilTypeTemp);

	rename("oil_base.dat", "temp.dat");

	if ((fPtr = fopen("temp.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	if ((fPtr1 = fopen("oil_base.dat", "wb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}

	panduan = 0;
	while ((fread(&temp, sizeof(struct oil), 1, fPtr)) != (int)NULL)
	{
		if (!strcmp(temp.oilName, oilNameTemp) && !strcmp(temp.oilType, oilTypeTemp))    /* 是要删除的信息  */
		{
			panduan = 1;
		}
		else
		{
			fwrite(&temp, sizeof(struct oil), 1, fPtr1);
		}
	}
	if (panduan == 0)
		printf("\n\n 对不起,您输入的油品种类错误\n");
	else
		printf("\n\n 删除信息成功!\n");
	fclose(fPtr);
	fclose(fPtr1);
	remove("temp.dat");
}//deleteOilRecord

/* 显示全部油品种类信息 */
void displayOilRecord()
{
	FILE *cfPtr;
	int flag;          /* 用于设置是否输出标题 */

	struct oil temp = { "", "", 0.0 };

	flag = 0;
	if ((cfPtr = fopen("oil_base.dat", "rb")) == NULL)
	{
		printf("无账号信息文件.\n");

	}
	else
	{
		while (fread(&temp, sizeof(struct oil), 1, cfPtr) != (int)NULL)
		{

			if (flag == 0)                                //第一次需要输出标题
			{
				printf("\n%-10s%-10s%-0s\n", "名称", "型号", "价格");
			}
			printf("%-10s%-10s%.2f\n", temp.oilName, temp.oilType, temp.oilPrice);
			flag = 1;
		}
		fclose(cfPtr); /* fclose函数用于关闭文件 */
	} /* end else */
}//displayOilRecord

/*验证油品是否存在，存在即返回油品价格*/
double oilSearch(char a[], char b[])
{
	FILE *fPtr;
	int panduan;
	struct oil temp = { "", "", 0.0 };

	if ((fPtr = fopen("oil_base.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	panduan = 0;
	while ((fread(&temp, sizeof(struct oil), 1, fPtr)) != (int)NULL)
	{
		if (!strcmp(a, temp.oilName) && !strcmp(b, temp.oilType))
		{
			panduan = 1;
			fclose(fPtr);
			return temp.oilPrice;
		}// end if
	}
	if (!panduan)  return 0.00;
	fclose(fPtr);
} //oilSearch


/* 创建新加油卡纪录 */
void newCardRecord()
{
	FILE *fPtr;
	int panduan, xuanze;
	struct card temp = { 0, "", "", "", "", 0.0 };
	int    cardNumberTemp;

	if ((fPtr = fopen("oilcard_base.dat", "ab+")) == NULL)
	{
		printf("写入加油卡信息文件有误\n");
		exit(0);
	}
	while (1)
	{
		printf("请您输入新的卡号:");
		scanf("%d", &cardNumberTemp);
		while (!cardNumberTemp)
		{
			printf("卡号不能为零\n");
			printf("请您输入新的卡号:");
			scanf("%d", &cardNumberTemp);
		}

		rewind(fPtr);
		panduan = 0;							 /* 判断账号是否存在 */
		while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
		{
			if (cardNumberTemp == temp.cardNumber)
			{
				printf("\n\n对不起,该卡号已存在!");
				panduan = 1;				 /* 说明该账号不能保存  */
				break;
			}
		}

		if (panduan == 0)                   /* 说明该账号可以保存新增纪录  */
		{
			temp.cardNumber = cardNumberTemp;
			printf("\n请您输入新的会员姓名: ");
			scanf("%s", &temp.clientName);
			printf("\n请您输入新的会员地址: ");
			scanf("%s", &temp.clientAdress);
			printf("\n请您输入新的会员身份证号: ");
			scanf("%s", &temp.clientID);
			printf("\n请您输入新的会员手机: ");
			scanf("%s", &temp.clientMobile);
			temp.balance = 0.0;
			fseek(fPtr, 0, SEEK_END);
			fwrite(&temp, sizeof(struct card), 1, fPtr);
			printf("\n 保存加油卡信息成功 ");
		}

		printf("\n\n是否继续录入信息:是:1;否:0;请选择:");
		scanf("%d", &xuanze);  printf("\n");
		if (xuanze != 1) break;
	}
	fclose(fPtr);
}//newCardRecord


/* 修改加油卡会员信息 */
void changeCardRecord()
{
	FILE *fPtr;
	int i = 0, j, panduan;
	int a = 0;
	struct card temp = { 0, "", "", "", "", 0.0 };
	int cardNumberTemp;
	char str[4][MAXN] = { '\0' };
	char receive[MAXN];
	char * s = "\n请您输入会员姓名:";
	strcpy(str[0], s);
	s = "\n请您输入会员地址:";
	strcpy(str[1], s);
	s = "\n请您输入会员ID:";
	strcpy(str[2], s);
	s = "\n请您输入会员手机:";
	strcpy(str[3], s);


	if ((fPtr = fopen("oilcard_base.dat", "rb+")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	panduan = 0;

	printf("请您输入要修改的卡号:");
	scanf("%d", &cardNumberTemp);

	printf("\n不需要修改的项,输入-1即可\n");
	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if (cardNumberTemp == temp.cardNumber)
		{
			panduan = 1;

			for (j = 0; j<4; j++)
			{
				printf("%s", str[j]);
				scanf("%s", receive);
				a = atoi(receive);
				if (a != -1)
				{
					switch (j)
					{
					case 0: strcpy(temp.clientName, receive); continue;
					case 1: strcpy(temp.clientAdress, receive); continue;
					case 2: strcpy(temp.clientID, receive); continue;
					case 3: strcpy(temp.clientMobile, receive); continue;
					}
				}
			}//for

			fseek(fPtr, i * sizeof(struct card), SEEK_SET);
			fwrite(&temp, sizeof(struct card), 1, fPtr);
			break;
		}// end if
		i++;
	}
	if (panduan == 0) printf("\n\n error:对不起,您输入的卡号不存在\n");
	else           printf("\n\n 修改成功\n");
	fclose(fPtr);
}//changeCardRecord

/*加油卡充值，自动生成交易记录*/
void charge()
{
	FILE *fPtr;
	int cardNumberTemp, i = 0, panduan;
	double transaction;

	char * transactionType = { "Charge" };

	struct card temp = { 0, "", "", "", "", 0.0 };
	struct deal chargeRecord = { 0, 0.0, "", "", "", "", 0.00 };

	printf("\n请您输入要充值的卡号:");
	scanf("%d", &cardNumberTemp);

	if ((fPtr = fopen("oilcard_base.dat", "rb+")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	panduan = 0;
	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if (temp.cardNumber == cardNumberTemp)
		{
			printf("\n请输入充值金额:");
			scanf("%lf", &transaction);
			temp.balance += transaction;
			fseek(fPtr, i * sizeof(struct card), SEEK_SET);
			fwrite(&temp, sizeof(struct card), 1, fPtr);
			panduan = 1;

			chargeRecord.card_number = temp.cardNumber;
			chargeRecord.transactionMoney = transaction;
			systemTime(chargeRecord.transactionTime);
			strcpy(chargeRecord.transactionType, transactionType);
			printf("\n请输入加油站名称:");
			scanf("%s", chargeRecord.oilStation);
			printf("\n请输入工作人员名称:");
			scanf("%s", chargeRecord.workername);

			chargeRecord.balance = temp.balance;
			newCardDealRecord(chargeRecord);
			break;
		}
		i++;
	}
	if (panduan == 0) printf("\n\n error:对不起,您输入的卡号不存在\n");
	else           printf("\n\n 充值成功\n");
	fclose(fPtr);
}//charge

/*判断卡号是否存在，余额是否充足*/
int judge(int a, double b)
{
	FILE *fPtr;
	int flag1 = 0, flag2 = 0;
	struct card temp = { 0, "", "", "", "", 0.0 };

	if ((fPtr = fopen("oilcard_base.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}

	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if (a == temp.cardNumber)
		{
			flag1 = 1;
			if (temp.balance > b)  
			{
				flag2 = 1;
				fclose(fPtr);
				return 3;
			}
			break;
		}//if
	}

	if (!flag1)
	{
		printf("\n无此卡号信息\n");
		fclose(fPtr);
		return 1;
	}

	if (!flag2)
	{
		printf("\n余额不足\n");
		fclose(fPtr);
		return 2;
	}
	
}//judge

/*加油，扣费，并自动生成交易记录*/
void consume()
{
	FILE *fPtr;
	int cardNumberTemp, i;
	int a;
	int number;
	char oilNameTemp[MAXN];
	char oilTypeTemp[MAXN];
	double oilPriceTemp;

	char * transactionType = { "Consume" };

	struct card temp = { 0, "", "", "", "", 0.0 };
	struct deal consumeRecord = { 0, 0.0, "", "", "", "", 0.00 };

	while (1)
	{
		printf("\n请您输入油品名称:");
		scanf("%s", oilNameTemp);
		printf("\n请您输入油品型号:");
		scanf("%s", oilTypeTemp);
		if (oilPriceTemp = oilSearch(oilNameTemp, oilTypeTemp)) break;
		printf("\n对不起，无对应的油品，请重新输入\n");
	}//while

	printf("\n请您输入要加油的卡号:");
	scanf("%d", &cardNumberTemp);
	printf("\n请您输入加油的数量:");
	scanf("%d", &number);

	a = judge(cardNumberTemp, number*oilPriceTemp);

	switch (a)
	{
	case 1: return;
	case 2:
		printf("\n请您重新输入加油的数量:");
		scanf("%d", &number);			
		break;
	case 3: break;
	}//switch

	consumeRecord.card_number = cardNumberTemp;
	consumeRecord.transactionMoney = number*oilPriceTemp;
	systemTime(consumeRecord.transactionTime);
	strcpy(consumeRecord.transactionType, transactionType);
	printf("\n请输入加油站名称:");
	scanf("%s", consumeRecord.oilStation);
	printf("\n请输入工作人员名称:");
	scanf("%s", consumeRecord.workername);

	if ((fPtr = fopen("oilcard_base.dat", "rb+")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	i = 0;
	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if (temp.cardNumber == cardNumberTemp)
		{
			temp.balance -= number*oilPriceTemp;
			fseek(fPtr, i * sizeof(struct card), SEEK_SET);
			fwrite(&temp, sizeof(struct card), 1, fPtr);
			consumeRecord.balance = temp.balance;
			newCardDealRecord(consumeRecord);
			break;
		}
		i++;
	}
	printf("\n\n 加油成功\n");
	fclose(fPtr);
} //consume

/* 显示全部卡号 */
void displayCardRecord()
{
	FILE *cfPtr;
	int flag = 0;          /* 用于设置是否输出标题 */
	struct card temp = { 0, "", "", "", "", 0.0 };
	if ((cfPtr = fopen("oilcard_base.dat", "rb")) == NULL)
	{
		printf("无账号信息文件.\n");

	}
	else
	{
		while (fread(&temp, sizeof(struct card), 1, cfPtr) != (int)NULL)
		{
			if (flag == 0)                                //第一次需要输出标题
			{
				printf("\n%-10s%-10s%-10s%-20s%-13s%-10s\n", "卡号", "姓名", "地址", "ID", "手机", "余额");
			}
			printf("%-10d%-10s%-10s%-20s%-13s%-10.2f\n", temp.cardNumber, temp.clientName, temp.clientAdress, temp.clientID, temp.clientMobile, temp.balance);
			flag = 1;
		}
		fclose(cfPtr); /* fclose函数用于关闭文件 */
	} /* end else */
}//displayCardRecord

/* 删除卡号 */
void deleteCardRecord()
{
	FILE *fPtr, *fPtr1;
	int panduan;
	struct card temp = { 0, "", "", "", "", 0.0 };
	int cardNumberTemp;

	printf("请您输入您要删除的卡号:");
	scanf("%d", &cardNumberTemp);

	rename("oilcard_base.dat", "temp.dat");

	if ((fPtr = fopen("temp.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	if ((fPtr1 = fopen("oilcard_base.dat", "wb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}

	panduan = 0;
	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if (cardNumberTemp == temp.cardNumber)    /* 是要删除的信息  */
		{
			panduan = 1;					
		}
		else
		{
			fwrite(&temp, sizeof(struct card), 1, fPtr1);
		}

	}
	if (panduan == 0)
		printf("\n\n 对不起,您输入的账号不存在\n");
	else
		printf("\n\n 删除信息成功!\n");
	fclose(fPtr);
	fclose(fPtr1);
	remove("temp.dat");
} //deleteCardRecord

/*条件查找卡号信息*/
void searchCardRecord()
{
	FILE *fPtr;
	int panduan;
	struct card temp = { 0, "", "", "", "", 0.0 };
	int cardNumberTemp;
	char string[MAXN] = { '\0' };

	if ((fPtr = fopen("oilcard_base.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	panduan = 0;

	printf("请您输入卡号 或姓名 或ID查询:");
	scanf("%s", string);
	cardNumberTemp = atoi(string);
	while ((fread(&temp, sizeof(struct card), 1, fPtr)) != (int)NULL)
	{
		if ((cardNumberTemp == temp.cardNumber) || !strcmp(string, temp.clientName) || !strcmp(string, temp.clientID))
		{
			panduan = 1;
			printf("\n%-10s%-10s%-10s%-20s%-13s%-10s\n", "卡号", "姓名", "地址", "ID", "手机", "余额");
			printf("%-10d%-10s%-10s%-20s%-13s%-10.2f\n", temp.cardNumber, temp.clientName, temp.clientAdress, temp.clientID, temp.clientMobile, temp.balance);
			break;
		}// end if
	}
	if (panduan == 0) printf("\n\n error:对不起,卡号不存在\n");
	fclose(fPtr);
}//searchCardRecord

/*获取系统时间*/
void systemTime(char * a)
{
	time_t t = time(0);
	char temp[MAXN];
	strftime(temp, sizeof(temp), "%Y/%m/%d %X %A", localtime(&t));
	strcpy(a, temp);
	a[MAXN] = '\0';
}

/* 创建新的交易纪录 */
void newCardDealRecord(struct deal temp)
{
	FILE *fPtr;
	if ((fPtr = fopen("oilcard_deal.dat", "ab+")) == NULL)
	{
		printf("写入加油卡交易记录文件有误\n");
		exit(0);
	}
	rewind(fPtr);
	fseek(fPtr, 0, SEEK_END);
	fwrite(&temp, sizeof(struct deal), 1, fPtr);
	printf("\n 保存加油卡交易记录信息成功 ");
	fclose(fPtr);
}//newCardDealRecord

/*显示全部交易记录*/
void displayCardDealRecord()
{
	FILE *cfPtr;
	int flag = 0;          /* 用于设置是否输出标题 */

	struct deal temp = { 0, 0.0, "", "", "", "", 0.00 };
	if ((cfPtr = fopen("oilcard_deal.dat", "rb")) == NULL)
	{
		printf("\n无账号信息文件.\n");

	}
	else
	{
		while (fread(&temp, sizeof(struct deal), 1, cfPtr) != (int)NULL)
		{
			if (flag == 0)                                //第一次需要输出标题
			{
				printf("\n%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "卡号", "交易金额", "类型", "加油站", "操作员", "余额", "交易时间");
			}
			printf("%-10d%-10.2f%-10s%-10s%-10s%-10.2f%-20s\n", temp.card_number, temp.transactionMoney, temp.transactionType, temp.oilStation, temp.workername, temp.balance, temp.transactionTime);
			flag = 1;
		}
		fclose(cfPtr); /* fclose函数用于关闭文件 */
	} /* end else */
}  //displayCardDealRecord

/*条件查找交易记录*/
void searchCardDealRecord()
{
	FILE *fPtr;
	int panduan;
	int flag = 1;
	struct deal temp = { 0, 0.0, "", "", "", "", 0.00 };
	int cardNumberTemp = 0;
	double transactionMoney = 0.00;
	char string[MAXN] = { '\0' };

	if ((fPtr = fopen("oilcard_deal.dat", "rb")) == NULL)
	{
		printf("不能打开文件 \n");
		exit(0);
	}
	panduan = 0;

	printf("请您输入卡号 或交易金额 或交易时间 或加油站名称 或操作员查询:");
	scanf("%s", string);
	cardNumberTemp = atoi(string);	
	transactionMoney = atof(string);    
	while ((fread(&temp, sizeof(struct deal), 1, fPtr)) != (int)NULL)
	{
		if ((cardNumberTemp == temp.card_number) || (transactionMoney == temp.transactionMoney) || !strcmp(string, temp.transactionTime) || !strcmp(string, temp.oilStation) || !strcmp(string, temp.workername))
		{
			panduan = 1;
			if (flag)
			{
				printf("\n%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "卡号", "交易金额", "类型", "加油站", "操作员", "余额", "交易时间");
				flag = 0;
			}
			printf("%-10d%-10.2f%-10s%-10s%-10s%-10.2f%-20s\n", temp.card_number, temp.transactionMoney, temp.transactionType, temp.oilStation, temp.workername, temp.balance, temp.transactionTime);
		}// end if
	}//end while
	if (panduan == 0) printf("\n\n error:对不起,未查询到信息\n");
	fclose(fPtr);
}//searchCardDealRecord





