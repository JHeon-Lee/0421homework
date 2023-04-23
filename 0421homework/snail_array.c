#include <stdio.h>

/*
		2 * 2 : 2번꺾임
		3 * 3 : 4번꺾임
		4 * 4 : 6번꺾임
		5 * 5 : 8번꺾임
		6 * 6 : 10번꺾임

		n * n : (2 * n) - 2 번 꺾임 = count

		증가수
		count	0	1	2	3	4	5	6	7	8	9	10
		2 * 2 : 2	1	1
		3 * 3 : 3	2	2	1	1
		4 * 4 : 4	3	3	2	2	1	1
		5 * 5 : 5	4	4	3	3	2	2	1	1
		6 * 6 : 6	5	5	4	4	3	3	2	2	1	1

		n * n : count 일때 n - (count + 1) / 2 번 올라감

*/

int main()
{
	int Table[50][50] = { 0 };
	int count = 0; // 꺾인 횟수
	int count_max; // 최대 꺾이는 횟수
	int scale; // 행렬의 길이

	printf("길이를 정하시오.(최대 50) ");
	scanf_s("%d", &scale);
	if (scale > 50 || scale < 0)
	{
		printf("다시 길이를 정하시오.(최대 50)");
		scanf_s("%d", &scale);
	}

	int right_limit = scale - 1;
	int low_limit = scale - 1;
	int left_limit = 0;
	int upper_limit = 0;
	count_max = (scale * 2) - 2;
	int circle = 0 ; // 몇바퀴 돌았는지 확인

	for (int j = 0; count <= count_max; j++)
	{
		if (count == 0) // count = 0 일때는 circle 횟수에 안넣음, limit의 변화에 i값의 범위도 변하기 때문에 값 계산에 보정을 위해 사용
		{
			for (int i = left_limit; i <= right_limit; i++)
			{
				Table[upper_limit][i] = i + 1;
			}
			count++;
			upper_limit++;
		}
		if (count % 4 == 1)
		{
			for (int i = upper_limit; i <= low_limit; i++)
			{
				Table[i][right_limit] = (i - circle) + Table[upper_limit - 1][right_limit];
			}
			count++;
			right_limit--;
		}
		if (count % 4 == 2)
		{
			for (int i = right_limit; i >= left_limit; i--)
			{
				Table[low_limit][i] = ((scale - 1) - (i + circle)) + Table[low_limit][right_limit + 1];
			}
			count++;
			low_limit--;
		}
		if (count % 4 == 3)
		{
			for (int i = low_limit; i >= upper_limit; i--)
			{
				Table[i][left_limit] = ((scale - 1) - (i + circle)) + Table[low_limit + 1][left_limit];
			}
			count++;
			left_limit++;
		}
		if (count % 4 == 0 && count != 0)
		{
			for (int i = left_limit; i <= right_limit; i++)
			{
				Table[upper_limit][i] = (i - circle) + Table[upper_limit][left_limit - 1];
			}
			count++;
			upper_limit++;
			circle++;
		}
	}

	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			if (Table[i][j] == 0)
				continue;
			printf("| %d\t|", Table[i][j]);
		}
		printf("\n");
	}

	return 0;
}
