/*姓名：谭庆波
  学号：20134342
  班级：计算计三班
  时间：2014/12/19
  */
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<malloc.h>
using namespace std;
typedef struct message
{
	int num;//景点代码
	char name[100];//景点名称
	char pro[500];//简介
}Ciceroni;
Ciceroni school[30];
void showview()  //校园鸟瞰图
{
    cout<<"\t\t\t$?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?$\n";
    cout<<"\t\t\t$                                                                                     $\n";
    cout<<"\t\t\t$   4.浴池                                     16.校医院                              $\n";
    cout<<"\t\t\t$      |                                            |                                 $\n";
    cout<<"\t\t\t$      |                                            |                                 $\n";
    cout<<"\t\t\t$  3.公主楼-----7.美食中心------13.公寓群------15.工程楼-------------------23.神秘的  $\n";
    cout<<"\t\t\t$      |                                            |                         南校区  $\n";
    cout<<"\t\t\t$      |           -- 9.文法楼                      |                            |    $\n";
    cout<<"\t\t\t$      |          |                                 |                            |    $\n";
    cout<<"\t\t\t$  1.主楼-----6.松鼠园--------12.田径场             |                       22.文博楼 $\n";
    cout<<"\t\t\t$      |          |                |                |                            |    $\n";
    cout<<"\t\t\t$      |           -- 8.信息楼    11.行政楼         |                       21.校史馆 $\n";
    cout<<"\t\t\t$      |                           |                |                            |    $\n";
    cout<<"\t\t\t$  2.理学楼----5.锦绣楼------10.丹青楼--------14.图书馆-----18.草坪/冰场         |    $\n";
    cout<<"\t\t\t$                                                   |              |             |    $\n";
    cout<<"\t\t\t$                                            17.逸夫楼------19.游泳馆-------20.体育馆 $\n";
    cout<<"\t\t\t$                                                                                     $\n";
    cout<<"\t\t\t$?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?∽?$\n";
    cout<<"\n\t\t\t\t按任意键返回主菜单";
    getch();
}
void creattour()  //初始化信息
{
    char name1[50][50]={"主楼","理学楼","公主楼","浴池","锦绣楼","松鼠园","美食中心","信息楼","文法楼","丹青楼","行政楼",
    "田径场","公寓群","图书馆","工程楼","校医院","逸夫楼","草坪/滑冰场","游泳馆","体育馆","校史馆","文博楼","神秘的南校区"};
    for(int i=1;i<=23;i++)
    {
        //school=(Ciceroni*)malloc(30*sizeof(Ciceroni));
         school[i].num=i;
         strcpy(school[i].name,name1[i-1]);
    }
     strcpy(school[1].pro,"主楼，我们学校的门面，非常霸气，咋一看去有气吞山河的气势，牛逼到不能用高大上形容。");
     strcpy(school[2].pro,"理学楼，听到理学两个字，不知道文科生有没有醉了呢？我们一般做物理实验都在这栋楼里。");
     strcpy(school[3].pro,"公主楼，因为楼里有电梯，而且住的是女生，所以叫公主楼。（禽兽啊！！给女生装电梯不给男生装）");
     strcpy(school[4].pro,"浴池，俗话说：“人生就像在林大的浴池洗澡，花同样的钱，但出水的多少却要看运气。”");
     strcpy(school[5].pro,"锦绣楼，又称一教，最早的教学楼，名字虽好听，其实非常破，而且下课时还特别挤，人山人海中有你有我。");
     strcpy(school[6].pro,"松鼠园，有花有草还有树，有喷泉还有特产小松鼠，尹志平说：这么好的环境，我就在这对小笼包下手吧！");
     strcpy(school[7].pro,"美食中心，特别大，但里面的食物绝对称不上“美食”二字。");
     strcpy(school[8].pro,"信息楼，据说楼很破，开的专业也很破，能够培养出我这样的屌丝，就知道这个评价很对。");
     strcpy(school[9].pro,"文法楼，不是很了解，听说盛产美女，这肯定是谣言，林大有美女吗？没发现啊！");
     strcpy(school[10].pro,"丹青楼，又称二教，学霸的天堂，学渣的地狱，因为每次考试都在这里进行，让你的每次挂科此楼有关。");
     strcpy(school[11].pro,"行政楼，非常霸气和好看，可惜与你无关，都被校领导霸占着。");
     strcpy(school[12].pro,"田径场，是个散步的好地方，但因为有“三走”就不好了。");
     strcpy(school[13].pro,"公寓群，住着林大的莘莘学子。");
     strcpy(school[14].pro,"图书馆，它确实很牛逼，藏书很多，座位很多，占地面积也很大。");
     strcpy(school[15].pro,"工程楼，貌似很高也很大，具体不了解。");
     strcpy(school[16].pro,"校医院，医药费很便宜，服务态度很差，技术很水。");
     strcpy(school[17].pro,"逸夫楼，欧美建筑风格，很漂亮，很浪漫，也很好看。");
     strcpy(school[18].pro,"草坪/滑冰场，夏天很美，看了多说好，冬天是天然滑冰场，“光滑的地板上摩擦摩擦”。");
     strcpy(school[19].pro,"游泳馆，分深水和浅水两个区，里面很大很暖和。");
     strcpy(school[20].pro,"体育馆，据说是东三省最大的体育馆，一般哈尔滨有什么大型活动都来这里办，明星也经常光顾。");
     strcpy(school[21].pro,"校史馆，其实也是黑龙江森林博物馆，省级博物馆，到底有多牛逼就不说了，只见一股屌气冲天而起。");
     strcpy(school[22].pro,"文博楼，听说也盛产美女，不过应该是谣言。");
     strcpy(school[23].pro,"神秘的南校区，正在新建中，硬件、软件都非常好，可惜与我无关了。");
}
void log() //缓慢输出
{
    printf("\t\t\t\t\t\t");	printf("欢");	Sleep(100);	printf("迎");
	Sleep(100); printf("进");Sleep(100);	printf("入");Sleep(100);
printf("东");Sleep(100);printf("北");	Sleep(100);printf("林");
	Sleep(100);printf("业");Sleep(100);printf("大");	Sleep(100);
	printf("学");Sleep(100);	printf("校");
	Sleep(100);printf("园");Sleep(100);printf("导");	Sleep(100);	printf("游");Sleep(100);printf("咨");	Sleep(100);printf("询");
Sleep(100);printf("系");Sleep(100);printf("统");	Sleep(100);	printf("\n");
}
void showmessage()  //景点介绍
{
    int n;
    cout<<"\n\t\t\t提示：输入 0 退出查询。\n";
    cout<<"\n\t\t\t请输入景点编号查看景点信息：";
    cin>>n;
    if(n<1&&n>23)
    {
        cout<<"\n\t\t\t输入有误，请重新输入：";
        cin>>n;
    }
    while(n)
    {
         for(int i=1;i<=23;i++)
      {
        if(n==school[i].num)
        {
            //puts(school[i].pro);
            cout<<"\n\t\t\t"<<school[i].pro<<endl;
            //cout<<endl;
            break;
        }
      }
      cout<<"\n\t\t\t提示：输入 0 退出查询。\n";
    cout<<"\n\t\t\t请输入景点编号查看景点信息：";
    cin>>n;
    if(n<1&&n>23)
    {
        cout<<"\n\t\t\t输入有误，请重新输入：";
        cin>>n;
    }
    }
    /*for(int i=1;i<=23;i++)
    {
        if(n==school[i].num)
        {
            //puts(school[i].pro);
            cout<<"\n\t\t\t"<<school[i].pro<<endl;
            //cout<<endl;
            break;
        }
    }*/
    cout<<"\n\t\t\t\t按任意键返回主菜单";
    getch();
}
void outview()   //显示景点名
{
    for(int i=1;i<=23;i++)
    {
        cout<<"     "<<school[i].num<<'.'<<school[i].name;
        if(i%5==0) cout<<endl;
    }
    cout<<"\n\t\t\t\t按任意键返回主菜单";
    getch();
}
int main()
{
	creattour() ;
    system("mode con: cols=140 lines=130");
    int b;
    log();
    while(1)
   {
       cout<<"\t\t\t\t************************************\n";
       cout<<"\t\t\t\t*                                  *\n";
       cout<<"\t\t\t\t*          校园主要景点列表        *\n";
       cout<<"\t\t\t\t*             谭庆波制作！         *\n";
       cout<<"\t\t\t\t*                                  *\n";
       cout<<"\t\t\t\t************************************\n";
       cout<<"\t\t\t\t   1.主楼    6.松鼠园   12.田径场   \n";
       cout<<"\t\t\t\t  14.图书馆  17.逸夫楼  18.草坪/滑冰场\n";
       cout<<"\t\t\t\t   20.体育馆  21.校史馆  23.南校区   \n";
       cout<<"\n\t\t\t                    功能目录          \n";
       cout<<"\n\t\t\t\t   1.显示东北林业大学旅游指导地图。  \n";
       cout<<"\n\t\t\t\t   2.查看每个景点的编号与名称。  \n";
       cout<<"\n\t\t\t\t   3.查看各个景点简介。   \n";
       cout<<"\n\t\t\t\t   0.退出。   \n";
       cout<<"\n\t\t\t\t   请输入你的选择：";
       cin>>b;
       switch(b)
       {
           case 1: showview();system("cls");break;
           case 2: outview();system("cls");break;
           case 3: showmessage();system("cls");break;
           case 0:exit(0);
           default: cout<<"错误\n";
       }
   }
    return 0;
}

