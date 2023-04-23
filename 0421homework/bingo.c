#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitTable(int table[][5]);
void Shuffle(int table[][5]);
void ShowTable(int table[][5]);
void SelectNumber(int table[][5]);
int CheckBingo(int table[][5]);

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int Table[5][5];
	int isContinue = 1;

	while(isContinue)
	{
		InitTable(Table);

		Shuffle(Table);

		while (1)
		{
			system("cls");

			int BingoCount = CheckBingo(Table);

			ShowTable(Table);

			printf("현재 빙고수 : %d\n\n", BingoCount);

			if (BingoCount == 3)
			{
				printf("빙고 3개를 맞췄습니다.\n");
				break;
			}

			SelectNumber(Table);

			Sleep(2000);

			CheckBingo(Table);
		}

		printf("1. 새 게임 0. 종료\n");
		scanf_s("%d", &isContinue);
	}
	return 0;
}

void InitTable(int table[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			table[i][j] = (i * 5) + j + 1;
		}
	}
}

void Shuffle(int table[][5])
{
	for (int i = 0; i < 100; i++)
	{
		int src_index1 = rand() % 5;
		int src_index2 = rand() % 5;
		int dest_index1 = rand() % 5;
		int dest_index2 = rand() % 5;

		int temp = table[src_index1][src_index2];
		table[src_index1][src_index2] = table[dest_index1][dest_index2];
		table[dest_index1][dest_index2] = temp;
	}
}

void ShowTable(int table[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("| %d\t|", table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SelectNumber(int table[][5])
{
	int number;

	printf("1 ~ 25 중의 숫자중 하나를 골라주세요. ");
	scanf_s("%d", &number);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i][j] == number)
				table[i][j] = 0;
		}
	}
}

int CheckBingo(int table[][5])
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) // 가로
		{
			if (table[i][j] == 0)
			{
				if (j == 4)
					count++;
			}
			else
				break;
		}
		for (int j = 0; j < 5; j++) // 세로
		{
			if (table[j][i] == 0)
			{
				if (j == 4)
					count++;
			}
			else
				break;
		}
	}
	for (int i = 0; i < 5; i++) // 오른쪽 아래방향 대각
	{
		if (table[i][i] == 0)
		{
			if (i == 4)
				count++;
		}
		else
			break;
	}
	for (int i = 0; i < 5; i++) // 오른쪽 윗방향 대각
	{
		if (table[i][4-i] == 0)
		{
			if (i == 4)
				count++;
		}
		else
			break;
	}

	return count;
}
