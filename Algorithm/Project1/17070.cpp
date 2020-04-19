/* https://www.acmicpc.net/problem/17070 : �������ű��
 * DFS ����
*/

#include <cstdio>
#include <string.h>

int arr[17][17];
int N;
int CNT = 0;
int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };

void DFS(int y, int x, int dir)
{
	//printf("y = %d , x = %d, dir =%d\n", y, x, dir);

	if (y == (N - 1) && x == (N - 1))
	{
		CNT++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		// �����ʿ��� �ٷ� �Ʒ���, �Ʒ����� �ٷ� ���������� ������ ���
		if ((i == 0 && dir == 2) || (dir == 0 && i == 2)) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];

		// N ������ �Ѱų�, ���� ������ ���
		if (ny >= N || nx >= N || arr[ny][nx] == 1) continue;
		// �밢���� ��� ������ ������ Ȯ��
		if (i == 1 && (arr[y][x + 1] == 1 || arr[y + 1][x] == 1)) continue;
		DFS(ny, nx, i);
	}
}


int main(void)
{
	scanf("%d", &N);

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	DFS(0, 1, 0);

	printf("%d\n", CNT);

	return 0;
}