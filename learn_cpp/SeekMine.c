#define _CRT_SECURE_NO_WARNINGS

//宏定义
//棋盘数量
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//地雷数量
#define easy_count 10

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//变量声明
//雷布置
char mine[ROWS][COLS];
//扫雷展示界面
char show[ROWS][COLS];
//时间记录
time_t start, end;
//存储标记坐标
int mark[60][2];
int mark_;

//函数声明

//菜单
void menu();
//游戏
void game();
//棋盘初始化
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col);//就算打印也是拓展数组,只不过打印部分
//布置地雷
void SetMine(char board[ROWS][COLS], int row, int col);//保证棋盘大小的一致性
//扫雷
void FindMine(char board[ROWS][COLS], int row, int col);
//显示附近的雷
void CountMine(char board[ROWS][COLS], int x, int y, int row, int col);
//检查非雷格子数目
int CheckMine(char board[ROWS][COLS], int row, int col);
//彩色打印函数
void printf_red(char* s);
void printf_green(char* s);
void printf_yellow(char* s);
void printf_blue(char* s);
//清空缓存区无用输入
void clear();



//菜单
void menu()
{
	printf("*********************************\n");
	printf("********   Minesweeping   *******\n");
	printf("********      1.play	  *******\n");
	printf("********      0.exit	  *******\n");
	printf("*********************************\n");

}

//棋盘初始化
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------Minesweeping game------------\n");
	for (j = 0; j <= col; j++)//打印列号
	{
		//printf("%c ", j + '0');
		printf("%-2d ", j);//打印的棋盘,不改变原有棋盘,所以这里可以为 整形 ,不用 字符型
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%-2d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			int jump = 0;//用于跳出多重 for循环 
			//标记坐标
			int k = 0;
			for (k = 0; k < mark_; k++)
			{
				if ((i == mark[k][0]) && (j == mark[k][1]) && (arr[i][j] == '*'))
				{
					printf_red("*  ");
					jump = 1;
					continue;
				}
			}

			if (jump == 1)
			{
				jump = 0;//还原
				continue;
			}
			//不同地雷数目的格子用不同颜色打印
			if (arr[i][j] == '1')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };//用于与printf_green参数一致.32为空格的ASCII码值,其实也可以用' ',不过懒得换了
				printf_green(tmp);
				continue;
			}
			if (arr[i][j] == '2')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_blue(tmp);
				continue;
			}
			if (arr[i][j] == '3')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_yellow(tmp);
				continue;
			}
			if (arr[i][j] > '3')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_red(tmp);
				continue;
			}
			printf("%c  ", arr[i][j]);
		}
		//除了以上特殊打印,剩下的正常打印
		printf("\n");
	}
	printf("----------Minesweeping game------------\n");

}

//布置地雷
//debug: board[][COLS],这里不能是 COL ,否则不完整 
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//雷坐标
	int x = 0;
	int y = 0;
	//雷数量
	int count = easy_count;
	while (count)
	{
		//随机数范围, 1 ~ row
		x = rand() % row + 1;
		y = rand() % col + 1;
		//判断坐标合法性
		if (board[x][y] == '0')//随机数范围包含了 x >= 1 && x <= row && y >= 1 && y <= col && 
		{
			board[x][y] = '1';
			count--;
		}
	}

}

//扫雷
void FindMine(char board[ROWS][COLS], int row, int col)//board[ROWS][COLS] 应该相当于指针变量
{
	//非雷格子数目
	int all_count = ROW * COL - easy_count;
	int count = 1;
	while (count < all_count)	//如果初始只有 1 个非雷格子,程序漏洞,通关
	{
		int x = 0;
		int y = 0;
		int z = 0;
		//清空缓存区无用输入
		clear();
		printf("Please select input:>\n1. Mine sweeping coordinates  2. Mark coordinates \n3. Cancel last marking  4. Cancel a certain point marking\n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			//清空缓存区无用输入
			clear();
			printf("Input minesweeping coordinates:>\n");
			scanf("%d %d", &x, &y);
			//输入坐标合法性检测
			if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
			{
				//有雷,被炸死,游戏结束
				if (board[x][y] == '1')
				{
					printf_red("Unfortunately, you were killed by the explosion and the mission failed.\n");
					goto lable;
					break;
				}
				//无雷,显示附近的雷,游戏继续
				if (board[x][y] == '0')
				{
					//显示附近的雷
					CountMine(board, x, y, ROW, COL);//雷的数量

					DisplayBoard(show, ROW, COL);//打印界面
					//检查非雷格子数目
					count = CheckMine(show, ROW, COL);
				}
			}
			else
			{
				printf("Coordinate error, please re-enter\n");
			}
			break;

		case 2:
			printf("Enter marker coordinates:>\n");
			scanf("%d %d", &x, &y);
			//输入坐标合法性检测
			if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
			{
				//存入标记坐标
				mark[mark_][0] = x;
				mark[mark_][1] = y;
				mark_++;
				DisplayBoard(show, ROW, COL);//打印界面
			}
			else
			{
				printf("Coordinate error, please re-enter\n");
			}
			break;

		case 3:
			if (mark_ <= 0)
			{
				printf("unmarked\n");
				break;
			}
			printf("Cancel Last Mark:>\n");
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
			DisplayBoard(show, ROW, COL);//打印界面
			break;

		case 4:
			//定点清除标记
			printf("Enter the coordinates of the marker to be cleared:>\n");
			int x0 = 0;
			int y0 = 0;
			scanf("%d %d", &x0, &y0);
			//输入坐标合法性检测
			if (x0 >= 1 && x0 <= row && y0 >= 1 && y0 <= col && show[x0][y0] == '*')
			{
				int i = 0;
				for (i = 0; i < mark_; i++)
				{
					if ((mark[i][0] == x0) && (mark[i][1] == y0))//后面的坐标整体向前挪动,覆盖此坐标
					{
						memmove(&(mark[i][0]), &(mark[i + 1][0]), (mark_ - i - 1) * sizeof(mark[0]));//mark[0]相当于首行元素名,sizeof(mark[0])首行大小
						mark_--;
						break;
					}
				}
				DisplayBoard(show, ROW, COL);//打印界面
			}
			else
			{
				printf("Coordinate error, please re-enter\n");
			}
			break;

		default:
			printf("Coordinate error, please re-enter\n");
		}

	}
	if (count == all_count)
	{

		end = time(NULL);//结束时间
		unsigned int time = (unsigned int)difftime(end, start);//计算耗时 /秒
		printf_green("Congratulations, game clearance!\n");
		printf("\033[0m\033[1;32mYour total time spent: %d second.\033[0m\n", time);
		//清除存储的标记坐标
		while (mark_)
		{
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
		}

	}
lable:
	if (count < all_count)
	{
		end = time(NULL);//结束时间
		unsigned int time = (unsigned int)difftime(end, start);//计算耗时 /秒
		printf("\033[0m\033[1;31mYour total time spent: %d second.\033[0m\n", time);
		//清除存储的标记坐标
		while (mark_)
		{
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
		}
	}

}

//显示附近的雷
void CountMine(char board[ROWS][COLS], int x, int y, int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{	//&& (i !=0 || j !=0)可省略,因为中心坐标无雷才能进行这一步
			if (board[x + i][y + j] == '1' && (i != 0 || j != 0))//&& (i !=0 || j !=0)作用:i,j不同时为 0
			{
				count++;
			}
		}
	}
	//存入(x,y)坐标周围雷数量
	//show[x][y] = 1+ count + '0';//char类型,不是 int ,按照ASCII码转换	+1证明求过该坐标
	show[x][y] = count + '0';	//不用 +1 证明,因为原有值 '*' ,不是 '0'
	//一个雷也没有,爆炸式展开
	if (count == 0)
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				//注意:不往回路爆炸展开,防止栈溢出  && show[x + i][y + j] == '*'  ,不等于 '*' ,则是展开过的地方
				//爆炸展开边界	&& x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col
				if (x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col && show[x + i][y + j] == '*')
					CountMine(board, x + i, y + j, row, col);
			}
		}
	}

	//show[x][y] =count + '0' -1;	// -1还原坐标

}


//检查非雷格子数目
int CheckMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] != '*')
				count++;
		}

	}
	return count;
}


//彩色打印函数
//格式 \033[输入属性m    代码属性;前景色;后景色
// 0 重置 1 高亮
//前景色 31 红 32 绿 33 黄 34 蓝
//后景色 40 黑 41 红
void printf_red(char* s)
{
	printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(char* s)
{
	printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(char* s)
{
	printf("\033[0m\033[1;33m%s\033[0m", s);
}

void printf_blue(char* s)
{
	printf("\033[0m\033[1;34m%s\033[0m", s);
}


//清空缓存区无用输入
void clear()
{
	//从贪吃蛇代码中学到的思路
	//但是似乎起不到预期效果
	fflush(stdin);
	//gets();//是读取一行,并返回字符串指针,也达不到预期效果;同理,getchar(),_getch()也达不到预期效果.

}




//数组应用,扫雷游戏2.0
//功能优化:
//			1.爆炸式边界展开
//			2.增加标记功能  (功能优化4.0)
//			3.操作步数记录  (为了更具有意义,改为时间记录)
//头文件

//游戏
void game()
{
	//存储标记坐标
	int mark[60][2] = { 0 };
	int mark_ = 0;//序号
	//棋盘初始化
	InitBoard(mine, ROWS, COLS, '0');//数组名,数组首元素的地址
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置地雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL,0,0,0);//测试代码用,作弊
	//扫雷
	FindMine(mine, ROW, COL);

}

int main()
{
	//输入值
	int input = 0;
	//雷布置
	char mine[ROWS][COLS] = { 0 };
	//扫雷展示界面
	char show[ROWS][COLS] = { 0 };
	//随机种子
	srand((unsigned int)time(NULL));


	do
	{
		//菜单
		menu();
		//选择
		printf("Please enter a selection\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Game start.\n");
			start = time(NULL);
			//游戏
			game();
			break;
		case 0:
			printf("Exit game.\n");
			break;
		default:
			printf("Input error, please re-enter\n");
			break;
		}
	} while (input);



	return 0;
}