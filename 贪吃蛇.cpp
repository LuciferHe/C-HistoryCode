#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAXW 27     //界面宽度
#define MAXH 22     //界面高度
#define MAXITEM 10  //屏幕上最多道具数目
#define ITEMCOUNT 5 //道具种类
/*若要增加道具
首先道具种类要修改
之后drawItem增加一个case 设置道具形状和颜色
activeItem也增加一个case 设置道具吃了后的效果
init 设置吃道具后的加分 及刷新概率
*/
#define ITEMINTERVAL 2200     //2次道具获取最小间隔(ms)
#define ITEMDESTROYTIME 7500  //道具存在时间

#define zUP 0
#define zDOWN 1
#define zLEFT 2
#define zRIGHT 3

#define SAVEFILEPATH "DATA.SAV"  //游戏存档
#define GAMETITLE "#DOS贪吃蛇 v0.8 Alpha 平衡操作版#"

struct { //游戏参数
	int Speed;//速度
	int State;//运行状态
	int Score;//分数
	clock_t lastitemclock; //上次获取道具时间
	clock_t cztime;		   //时钟
	char map[MAXW][MAXH]; //地图
	short color[20]; //颜色
	bool alrddraw;
	bool pause;
	bool freshnow;
	int howtodead;
} Game;

struct { //游戏记录
	char flag[3];
	short version;
	int highscore;
	int hash;
} gameSave;

struct _pos { //坐标参数
	int x;
	int y;
};

struct {  //蛇参数
	struct _pos pos[MAXW*MAXH];
	int lfx; //上个方向
	int fx;		//方向
	int lengh;  //蛇身长度
} snake[2];

struct {  //道具 0号默认给苹果
	bool able;		 //激活
	struct _pos pos; //坐标
	int itemNum;     //物品代码
	clock_t crttime; //创建时间
} sItem[MAXITEM];

struct {  //道具信息 0号默认给苹果
	int Score;
	int Probability; //道具出现概率
	short color;
} itemInfo[ITEMCOUNT];

HANDLE hOut, g_hConsoleOutput;  // 控制台输出句柄
char deadmsg[5][20] = { { "撞墙上了" }, { "撞到自己了" } };

void gotoxyWithFullwidth(short x, short y);
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor);
void init();
void drawSnake();
void moveSnack();
void checkCrash();
void createItem();
void addItem(int itemNum);
void drawItem(int n);
void keyPress(int key);
void activeItem(int itemNum);
void drawMap();
void drawIntroduction();
void loadGameSave();
void saveGameSave();

int main() {
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // 光标信息
	g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台输出句柄
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // 设置光标隐藏
	SetConsoleTitleA(GAMETITLE);

	int press = 0;
	clock_t lclk;
	lclk = Game.cztime = clock();
	Game.State = 3;
	int left, choose = 0;
	left = (MAXW - strlen(GAMETITLE) / 2) / 2;
	/*
	Game.State的值
	0 终止循环(退出)
	1 游戏状态
	2 撞蛇了
	3 初始化界面
	4 等待开始界面
	5 暂停界面
	*/
	loadGameSave(); //读取游戏记录
	while (Game.State) {
		switch (Game.State) {
		case 1:
			if (!Game.pause) {
				Game.cztime = clock();
				if (Game.freshnow || Game.cztime - lclk>Game.Speed) {
					srand(time(0));
					Game.freshnow = false;
					gotoxyWithFullwidth(0, 0);
					createItem();  //道具相关
					moveSnack();  //蛇移动
					checkCrash(); //检测碰撞
					drawSnake(); //画蛇身体
					SetColor(Game.color[1], 0);
					gotoxyWithFullwidth(MAXW + 1, 10);
					printf("蛇身长度: %d米", snake[0].lengh);
					gotoxyWithFullwidth(MAXW + 1, 11);
					printf("游戏分数: %d分", Game.Score);
					gotoxyWithFullwidth(MAXW + 1, 12);
					printf("爬行速度: %.2f米/秒", 1000.0 / Game.Speed);
					lclk = Game.cztime;
				}
			}
			break;
		case 2:
			if (!Game.alrddraw) {
				Game.alrddraw = true;

				drawMap();
				SetColor(Game.color[1], 0);
				gotoxyWithFullwidth(left, 4);
				printf("游戏结束,因为你%s", deadmsg[Game.howtodead]);
				gotoxyWithFullwidth(left, 6);
				printf("你的分数: %d", Game.Score);
				if (Game.Score>gameSave.highscore) {
					gameSave.highscore = Game.Score;
					saveGameSave();
				}
				gotoxyWithFullwidth(left, 8);
				printf("最高分数: %d", gameSave.highscore);
				gotoxyWithFullwidth(left, MAXH - 9);
				printf("  >按R重新开始游戏");
				gotoxyWithFullwidth(left, MAXH - 8);
				printf("  >按Q结束游戏");
			}
			break;
		case 3:
			init();
			drawMap();
			drawIntroduction();
			Game.alrddraw = false;
			Game.State = 4;
			break;
		case 4:
			if (!Game.alrddraw) {
				gotoxyWithFullwidth(left, MAXH / 2 - 5);
				printf(GAMETITLE);
				gotoxyWithFullwidth(left, MAXH / 2 - 3);
				printf("最高分: %d分", gameSave.highscore);
				gotoxyWithFullwidth((MAXW - 10) / 2, MAXH - 8);
				printf(">>>>按N开始游戏<<<<");
				Game.alrddraw = true;
			}
			break;
		}
		if (_kbhit()) {
			press = _getch();
			keyPress(press);
		}
	}
	CloseHandle(g_hConsoleOutput);
	return 0;
}

void init() {
	system("cls");

	int i;
	//初始化蛇的位置
	snake[0].pos[0].x = 5;
	snake[0].pos[0].y = 5;
	snake[0].pos[1].x = 4;
	snake[0].pos[1].y = 5;
	snake[0].pos[2].x = 3;
	snake[0].pos[2].y = 5;
	for (i = 3; i<MAXH*MAXW; i++) {
		snake[0].pos[i].x = -5;
		snake[0].pos[i].y = -5;
	}
	snake[0].lengh = 3;
	snake[0].fx = zRIGHT;
	snake[0].lfx = snake[0].fx;
	//初始化游戏参数
	//Game.Speed=256;
	Game.Speed = 500;
	Game.Score = 0;
	Game.freshnow = false;
	Game.lastitemclock = clock();
	Game.color[0] = 0xF; //边框颜色
	Game.color[1] = 0xF; //提示文本颜色
	Game.color[2] = 0xC; //蛇头
	Game.color[3] = 0x8; //蛇身
	Game.color[4] = 0x0; //游戏背景
	Game.pause = false;
	//初始化道具
	for (i = 0; i<MAXITEM; i++) {
		sItem[i].able = false;
		sItem[i].itemNum = 0;
		sItem[i].pos.x = 0;
		sItem[i].pos.y = 0;
		sItem[i].crttime = 0;
	}
	itemInfo[0].Score = 5;
	itemInfo[1].Score = 8;
	itemInfo[2].Score = 15;
	itemInfo[3].Score = 25;
	itemInfo[4].Score = 20;
	itemInfo[0].Probability = 100;
	itemInfo[1].Probability = 50;
	itemInfo[2].Probability = 50;
	itemInfo[3].Probability = 33;
	itemInfo[4].Probability = 11;
	itemInfo[0].color = 0xC;
	itemInfo[1].color = 0xC;
	itemInfo[2].color = 0xC;
	itemInfo[3].color = 0xC;
	itemInfo[4].color = 0xC;
}

void loadGameSave() { //读取游戏记录
	FILE *fp;
	if (!(fp = fopen(SAVEFILEPATH, "r"))) {
		//记录无效
	}
	else {
		if (EOF != fread(&gameSave, sizeof(gameSave), 1, fp)) {
			if (gameSave.flag[0] == 'T'&&gameSave.flag[1] == 'C'&&gameSave.flag[2] == 'S'&&gameSave.version == 0) {

				return;
			}
		}
		fclose(fp);
	}
	gameSave.highscore = 0;
	gameSave.flag[0] = 'T';
	gameSave.flag[1] = 'C';
	gameSave.flag[2] = 'S';
	gameSave.version = 0;
	gameSave.hash = 666;
}
void saveGameSave() { //保存游戏记录
	FILE *fp;
	if (fp = fopen(SAVEFILEPATH, "w")) {
		fwrite(&gameSave, sizeof(gameSave), 1, fp);
		fclose(fp);
	}
}

void drawMap() {
	//初始化地图
	int i, j;
	for (i = 0; i<MAXW; i++)Game.map[i][0] = Game.map[i][MAXH - 1] = 1;
	for (i = 0; i<MAXH; i++)Game.map[0][i] = Game.map[MAXW - 1][i] = 1;
	for (i = 0; i<MAXW; i++) {
		for (j = 0; j<MAXH; j++) {
			gotoxyWithFullwidth(i, j);
			if (Game.map[i][j] == 1) {
				SetColor(Game.color[0], Game.color[0]);
				printf("%2s", "");
			}
			else {
				SetColor(Game.color[4], Game.color[4]);
				printf("%2s", "");
			}
		}
	}
}
void drawIntroduction() {
	//初始化提示文本
	SetColor(Game.color[1], 0);
	int i = 0;
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf("道具介绍");
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf(" ○ 食物 身长+1");
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf(" ● 食物 身长+3");
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf(" △ 减速 速度减慢");
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf(" ☆ 加速 速度加快");
	gotoxyWithFullwidth(MAXW + 1, i++);
	printf(" ⊙ 反转 头尾对换");

	gotoxyWithFullwidth(0, MAXH + 1);
	printf("(C)2013 HarrySean QQ 447449873");

	gotoxyWithFullwidth(0, MAXH);
	printf("操作:[上下左右]或者[WSAD]控制小蛇行进 [P]暂停游戏 [Q]退出游戏");
}

void createItem() {
	int i;
	if (!sItem[0].able) { //苹果木有了
		addItem(0);
	}
	for (i = 1; i<MAXITEM; i++)
		if (sItem[i].able && (Game.cztime - sItem[i].crttime>ITEMDESTROYTIME)) {
		//时间太长的道具消失
		sItem[i].able = false;
		gotoxyWithFullwidth(sItem[i].pos.x, sItem[i].pos.y);
		printf("　");
		}
	if (rand() % 10<3 && Game.cztime - Game.lastitemclock>ITEMINTERVAL) {

		i = rand() % (ITEMCOUNT - 1) + 1;
		if (rand() % 100<itemInfo[i].Probability) {
			addItem(i);
			Game.lastitemclock = Game.cztime;
		}
	}
}
void addItem(int itemNum) {
	int over = 0, i, j;
	if (itemNum) {//不是基本食物
		for (i = 1; i<MAXITEM; i++) {
			if (!sItem[i].able)break;
		}
		if (i == MAXITEM)return; //如果所有道具都激活 就不创建
	}
	else {
		i = 0;
	}
	if (!sItem[i].able) {
		while (!over) {
			sItem[i].pos.x = rand() % MAXW;
			sItem[i].pos.y = rand() % MAXH;
			over = 1;
			if (Game.map[sItem[i].pos.x][sItem[i].pos.y] == 1)over = 0;
			for (j = 0; j<snake[0].lengh; j++)if (snake[0].pos[j].x == sItem[i].pos.x&&snake[0].pos[j].y == sItem[i].pos.y)over = 0;
			for (j = 0; j<MAXITEM; j++)if (sItem[j].able&&sItem[j].pos.x == sItem[i].pos.x&&sItem[j].pos.y == sItem[i].pos.y)over = 0;

		}
		sItem[i].crttime = Game.cztime;
		sItem[i].itemNum = itemNum;
		sItem[i].able = true;
		drawItem(i);
	}
}
void drawItem(int n) {

	gotoxyWithFullwidth(sItem[n].pos.x, sItem[n].pos.y);

	switch (sItem[n].itemNum) {
	case 0: //基本食物
		SetColor(itemInfo[sItem[n].itemNum].color, 0);
		printf("○");
		break;
	case 1: //减速
		SetColor(itemInfo[sItem[n].itemNum].color, 0);
		printf("△");
		break;
	case 2: //加速
		SetColor(itemInfo[sItem[n].itemNum].color, 0);
		printf("☆");
		break;
	case 3: //对换
		SetColor(itemInfo[sItem[n].itemNum].color, 0);
		printf("⊙");
		break;
	case 4: //大号食物
		SetColor(itemInfo[sItem[n].itemNum].color, 0);
		printf("●");
		break;
	}
	if (sItem[n].pos.x == MAXW - 2) {
		gotoxyWithFullwidth(MAXW - 1, sItem[n].pos.y);
		SetColor(Game.color[0], Game.color[0]);
		printf("%2s", "");
	}
}

void activeItem(int itemNum) {
	Game.Score += (itemInfo[itemNum].Score + 1000 / Game.Speed + ((itemNum == 1 || itemNum == 4) ? snake[0].lengh / 2 : 0))*(0.8 + rand() % 40 / 100.0);
	int i;
	struct _pos t;
	switch (itemNum) {
	case 0:  //普通食物
		snake[0].lengh++;
		if (Game.Speed*0.03<2)
			Game.Speed *= .85;
		else
			Game.Speed -= 2;
		break;
	case 1:  //加速
		if (Game.Speed*0.1>15)
			Game.Speed *= 1.1;
		else
			Game.Speed += 15;
		break;
	case 2: //减速
		if (Game.Speed*0.1<20)
			Game.Speed *= .85;
		else
			Game.Speed -= 20;
		break;
	case 3:  //对换
		for (i = 0; i<snake[0].lengh / 2; i++) {
			t = snake[0].pos[i];
			snake[0].pos[i] = snake[0].pos[snake[0].lengh - i - 1];
			snake[0].pos[snake[0].lengh - i - 1] = t;
		}
		i = snake[0].pos[0].x - snake[0].pos[1].x + (snake[0].pos[0].y - snake[0].pos[1].y) * 2;
		if (i == 1)snake[0].fx = zRIGHT;
		else if (i == -1)snake[0].fx = zLEFT;
		else if (i == 2)snake[0].fx = zDOWN;
		else snake[0].fx = zUP;
		snake[0].lfx = snake[0].fx;
		break;
	case 4:  //大号食物
		snake[0].lengh += 3;
		Game.Speed *= .95;
	}
	if (Game.Speed<23)Game.Speed = 23;
}


void drawSnake() {
	int i = 0;

	while (snake[0].pos[i].x >= 0) {
		gotoxyWithFullwidth(snake[0].pos[i].x, snake[0].pos[i].y);
		SetColor(i == 0 ? Game.color[2] : Game.color[3], 0);
		printf("■");
		i++;
	}
}
void moveSnack() {
	int i = 0;
	if (snake[0].pos[snake[0].lengh - 1].x>0) {
		SetColor(Game.color[4], Game.color[4]);
		gotoxyWithFullwidth(snake[0].pos[snake[0].lengh - 1].x, snake[0].pos[snake[0].lengh - 1].y);
		printf("%2s", "");//擦掉上个尾巴
	}
	for (i = snake[0].lengh - 2; i >= 0; i--) {
		snake[0].pos[i + 1] = snake[0].pos[i];
	}
	if (snake[0].fx == zUP)snake[0].pos[0].y--;
	if (snake[0].fx == zDOWN)snake[0].pos[0].y++;
	if (snake[0].fx == zLEFT)snake[0].pos[0].x--;
	if (snake[0].fx == zRIGHT)snake[0].pos[0].x++;
}
void checkCrash() {
	int i;
	if (Game.map[snake[0].pos[0].x][snake[0].pos[0].y] == 1) {
		Game.alrddraw = false;
		Game.State = 2;//撞墙了
		Game.howtodead = 0;
	}
	for (i = 1; i<snake[0].lengh; i++)if (snake[0].pos[i].x == snake[0].pos[0].x&&snake[0].pos[i].y == snake[0].pos[0].y) {
		Game.alrddraw = false;
		Game.State = 2; //撞身子了
		Game.howtodead = 1;
	}
	for (i = 0; i<MAXITEM; i++) {
		if (sItem[i].able&&snake[0].pos[0].x == sItem[i].pos.x&&snake[0].pos[0].y == sItem[i].pos.y) { //吃到道具了
			sItem[i].able = false;
			activeItem(sItem[i].itemNum);
		}
	}
}
void gotoxyWithFullwidth(short x, short y) {
	static COORD cd;

	cd.X = (short)(x << 1);
	cd.Y = y;
	SetConsoleCursorPosition(g_hConsoleOutput, cd);
}


void keyPress(int key) {
	if (Game.State == 1) {
		switch (key) {
		case 72:
		case 'w':
		case 'W':
			if (snake[0].lfx != zDOWN) {
				Game.freshnow = true;
				snake[0].fx = zUP;
				snake[0].lfx = snake[0].fx;
			}
			break;
		case 80:
		case 's':
		case 'S':
			if (snake[0].lfx != zUP) {
				Game.freshnow = true;
				snake[0].fx = zDOWN;
				snake[0].lfx = snake[0].fx;
			}
			break;
		case 75:
		case 'a':
		case 'A':
			if (snake[0].lfx != zRIGHT) {
				Game.freshnow = true;
				snake[0].fx = zLEFT;
				snake[0].lfx = snake[0].fx;
			}
			break;
		case 77:
		case 'd':
		case 'D':
			if (snake[0].lfx != zLEFT) {
				Game.freshnow = true;
				snake[0].fx = zRIGHT;
				snake[0].lfx = snake[0].fx;
			}
			break;
		case 'p':
			Game.pause = !Game.pause;
			break;
		}
	}
	else if (Game.State == 4) {
		switch (key) {
		case 'n':
		case 'N':
			Game.State = 1;
			drawMap();
			break;
		}
	}
	else if (Game.State == 2) {
		switch (key) {
		case 'r':
		case 'R':
			Game.State = 3;
			break;
		}
	}
	else if (Game.State == 1) {
		;
	}
	if (key == 'q' || key == 'Q') {
		Game.State = 0;
	}
}
void SetColor(unsigned short ForeColor = 0, unsigned short BackGroundColor = 0) {
	/*
	0 = 黑色       8 = 灰色
	1 = 蓝色       9 = 淡蓝色
	2 = 绿色       A = 淡绿色
	3 = 湖蓝色     B = 淡浅绿色
	4 = 红色       C = 淡红色
	5 = 紫色       D = 淡紫色
	6 = 黄色       E = 淡黄色
	7 = 白色       F = 亮白色
	*/
	WORD wColor = ((BackGroundColor & 0x0F) << 4) + (ForeColor & 0x0F);
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, wColor);
}


