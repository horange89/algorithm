/* https://www.acmicpc.net/problem/17140 : ������ �迭�� ����
 * ���� ����
*/

#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int R, C, K; //��,��, ��ǥ��
int arr[101][101];// �迭
int num[101];
int rLen, cLen, CNT = 0;

void solve(void)
{
	while (true)
	{
		if (arr[R][C] == K)
		{
			printf("%d\n", CNT);
			break;
		}

		if (CNT > 100)
		{
			printf("-1\n");
			break;
		}

		vector<int> Size;

		// ���� ���� >= ���� ����
		if (rLen >= cLen)
		{
			for (int y = 1; y <= rLen; y++)
			{
				vector<pair<int, int>> v;
				memset(num, 0, sizeof(num));

				// ���ڿ� ���� ã��
				for (int x = 1; x <= cLen; x++)
				{
					num[arr[y][x]]++;
				}

				// Vector ����
				for (int k = 1; k < 101; k++)
				{
					if (num[k] != 0)
					{
						v.push_back(make_pair(num[k], k));
					}
				}

				// ����
				sort(v.begin(), v.end());
				for (int x = 1; x <= cLen; x++) arr[y][x] = 0;
				int idx = 1;

				// ���γֱ�
				for (int k = 0; k < v.size(); k++)
				{
					arr[y][idx++] = v[k].second;
					arr[y][idx++] = v[k].first;
				}

				idx--;
				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			cLen = Size.back();
		}
		// ���� ���� > ���� ����
		else
		{
			for (int x = 1; x <= cLen; x++)
			{
				vector<pair<int, int>> v;
				memset(num, 0, sizeof(num));

				// ���ڿ� ���� ã��
				for (int y = 1; y <= rLen; y++)
				{
					num[arr[y][x]]++;
				}

				// Vector ����
				for (int k = 1; k < 101; k++)
				{
					if (num[k] != 0)
					{
						v.push_back(make_pair(num[k], k));
					}
				}

				// ����
				sort(v.begin(), v.end());
				for (int y = 1; y <= rLen; y++) arr[y][x] = 0;
				int idx = 1;

				// ���γֱ�
				for (int k = 0; k < v.size(); k++)
				{
					arr[idx++][x] = v[k].second;
					arr[idx++][x] = v[k].first;
				}

				idx--;
				Size.push_back(idx);

			}
			sort(Size.begin(), Size.end());
			rLen = Size.back();
		}

		CNT++;

	}
}

int main(void)
{
	scanf("%d %d %d", &R, &C, &K);

	memset(arr, 0, sizeof(arr));
	rLen = 3; cLen = 3;

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &arr[i][j]);


	if (arr[R][C] == K)
	{
		printf("0\n");
	}
	else {
		solve();
	}


	return 0;
}