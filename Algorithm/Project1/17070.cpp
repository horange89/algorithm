/* https://www.acmicpc.net/problem/17070 : 파이프옮기기
 * DFS 문제
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
		// 오른쪽에서 바로 아래로, 아래에서 바로 오른쪽으로 돌리는 경우
		if ((i == 0 && dir == 2) || (dir == 0 && i == 2)) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];

		// N 범위를 넘거나, 벽을 만났을 경우
		if (ny >= N || nx >= N || arr[ny][nx] == 1) continue;
		// 대각선인 경우 나머지 구역도 확인
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