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

			printf("���� ����� : %d\n\n", BingoCount);

			if (BingoCount == 3)
			{
				printf("���� 3���� ������ϴ�.\n");
				break;
			}

			SelectNumber(Table);

			Sleep(2000);

			CheckBingo(Table);
		}

		printf("1. �� ���� 0. ����\n");
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

	printf("1 ~ 25 ���� ������ �ϳ��� ����ּ���. ");
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
		for (int j = 0; j < 5; j++) // ����
		{
			if (table[i][j] == 0)
			{
				if (j == 4)
					count++;
			}
			else
				break;
		}
		for (int j = 0; j < 5; j++) // ����
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
	for (int i = 0; i < 5; i++) // ������ �Ʒ����� �밢
	{
		if (table[i][i] == 0)
		{
			if (i == 4)
				count++;
		}
		else
			break;
	}
	for (int i = 0; i < 5; i++) // ������ ������ �밢
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
