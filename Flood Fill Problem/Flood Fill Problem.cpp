// Flood Fill Problem
// Parker Padgett
// 11-6-23

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// check if valid coordinate
int validCoord(int x, int y, int n, int m)
{
	if (x < 0 || y < 0)
	{
		return 0;
	}
	if (x >= n || y >= m)
	{
		return 0;
	}
	return 1;
}

void bfs(int n, int m, int data[][8], int x, int y, int color)
{
	// visiting array
	int vis[101][101];

	// initializing all as 0
	memset(vis, 0, sizeof(vis));

	// creating queue of pairs
	queue<pair<int, int>> obj;

	// pushing pair of {x,y}
	obj.push({ x,y });

	// marking {x,y} as visited
	vis[x][y] = 1;

	while (obj.empty() != 1)
	{
		// taking front element of queue
		pair<int, int> coord = obj.front();
		int x = coord.first;
		int y = coord.second;

		// storing current color value
		int preColor = data[x][y];

		// updating color value
		data[x][y] = color;

		// popping front pair of queue
		obj.pop();

		// checking above
		if (validCoord(x+1,y,n,m) && vis[x+1][y] == 0 && data[x + 1][y] == preColor)
		{
			obj.push({ x + 1,y });
			vis[x + 1][y] = 1;
		}

		// checking below
		if (validCoord(x-1,y,n,m) && vis[x-1][y] == 0 && data[x - 1][y] == preColor)
		{
			obj.push({ x - 1,y });
			vis[x - 1][y] = 1;
		}

		// checking left
		if (validCoord(x,y-1,n,m) && vis[x][y-1] == 0 && data[x][y - 1] == preColor)
		{
			obj.push({ x,y - 1 });
			vis[x][y - 1] = 1;
		}

		// checking right
		if (validCoord(x,y+1,n,m) && vis[x][y+1] == 0 && data[x][y + 1] == preColor)
		{
			obj.push({ x,y + 1 });
			vis[x][y + 1] = 1;
		}
	}

	// printing new matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n, m, x, y, color;
	n = 8;
	m = 8;
	int data[8][8] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 1, 1 },
	{ 1, 2, 2, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 2, 2, 0 },
	{ 1, 1, 1, 1, 1, 2, 1, 1 },
	{ 1, 1, 1, 1, 1, 2, 2, 1 },
	};
	x = 4, y = 4, color = 3;
	// Function Call
	bfs(n, m, data, x, y, color);
	return 0;
}