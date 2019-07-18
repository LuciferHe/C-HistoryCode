/*
姓名：王冰
学号：13101020125
班级：计13-1 */


#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
       FILE *file2;
       int i;
       int paslen;
       char ch;
       char destin[300],password[10];
       printf("please input the destination file(less than 300 charcters):\n");
       gets(destin);
       printf("please input the password(less than 10 ditigals):\n");
       gets(password);
       paslen=strlen(password);//获取密码长度
        if((file2=fopen(destin,"rb+"))!=NULL)
        {  
		printf("the destination file %s opened successfully\n",destin);
            ch=fgetc(file2);
				i=0;
              while(ch!=EOF)
              {
				  ch=ch^(password[i++]); //利用密码进行解密
                   if(i>=paslen)
                       i=0;
					printf ( "%c", ch );
                    ch=fgetc(file2);
              }
             fclose(file2);
		}
        else
        {
            printf("the destination file %s opened error\n",destin);
        }
       getchar();
       return 0;
}