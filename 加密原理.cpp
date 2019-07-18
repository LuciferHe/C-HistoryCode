#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
       FILE *file1,*file2;
       int i;
       int paslen;
       char ch;
       char source[300],destin[300],password[10];
       printf("Please input the source file(less than 300 charcters):\n");
       gets(source);
       printf("please input the destination file(less than 300 charcters):\n");
       gets(destin);
       printf("please input the password(less than 10 ditigals):\n");
       gets(password);
       paslen=strlen(password);//获取密码长度
       if((file1=fopen(source,"rb"))!=NULL)
       {
              printf("the source file %s opened successfully.\n",source);
              if((file2=fopen(destin,"wb+"))!=NULL)
              {
                     printf("the destination file %s created successfully\n",destin);
                     ch=fgetc(file1);
                     i=0;
                     while(ch!=EOF)
                     {
                            ch=ch^(password[i++]); //利用密码进行加密
                            if(i>=paslen)
                            i=0;
                            fputc(ch,file2);
                            ch=fgetc(file1);
                     }
                     fclose(file1);
                     fclose(file2);
              }
              else
              {
                     printf("the destination file %s created error\n",destin);
              }
       }
       else
       {
              printf("the source file %s opened error.\n",source);
       }
       getchar();
       return 0;
}