#include <stdio.h>

int main()
{
	int Table[5][5];
	int Scale = 25;
	int count = 0; // ���� Ƚ��
	int left_limit = -1;  // ���� �ε��� �Ѱ�
	int right_limit = 5; // ���� �ε��� �Ѱ�
	int upper_limit = 0; // ��� �ε��� �Ѱ�
	int low_limit = 5; // �ϴ� �ε��� �Ѱ�

	while (count != 9)
	{
		for (int i = left_limit + 1; i < right_limit; i++)
		{
			Table[0][i] = i + 1 + count * 5;
			right_limit -= right_limit;
			count++;
		}
		for (int i = upper_limit; i < low_limit; i++)
		{
			Table[i][4] = i + count * 5;
			low_limit -= low_limit;
			count++;
		}
		for (int i = left_limit; i < right_limit; i++)
		{
			Table[4][i] = (-i + 3) + count * 5;
			left_limit += left_limit;
			count++;
		}
		for (int i = upper_limit; i < low_limit; i++)
		{
			Table[i][0] = (-i + 3) + count * 5;
			count++;
		}
	}

	return 0;
}