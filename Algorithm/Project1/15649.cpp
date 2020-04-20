/* https://www.acmicpc.net/problem/15649 : N과 M 수열구하기
 * DFS 문제
*/

#include <cstdio>

int N, M;
int arr[100];
bool visit[100];

// DFS
void DFS(int cnt)
{
	if (M == cnt)
	{
		for (int i = 1; i <= M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			arr[cnt + 1] = i;
			visit[i] = true;
			DFS(cnt + 1);
			arr[cnt + 1] = -1;
			visit[i] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS(0);

	return 0;
}