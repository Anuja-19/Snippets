#include <bits/stdc++.h>
using namespace std;
#define N 5
int findMinCost(int cost[][N])
{
	int lookup[N];
	for (int i = 0; i < N; i++)
		lookup[i] = cost[0][i];
	bool is_filled = false;
	while (!is_filled)
	{
		is_filled = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (lookup[i] > lookup[j] + cost[j][i]) {
					lookup[i] = lookup[j] + cost[j][i];
					is_filled = false;
				}
			}
		}
	}
	return lookup[N-1];
}
int main()
{
	int cost[N][N] =
	{
		{ 0, 25, 20, 10, 105 },
		{ 20, 0, 15, 80, 80 },
		{ 30, 15, 0, 70, 90 },
		{ 10, 10, 50, 0, 100 },
		{ 40, 50, 5, 10, 0 }
	};
	cout << "The minimum cost is " << findMinCost(cost) << "$";
    return 0;
}