#include "Graph.h"
#define VERYBIGINIT 1000000
Graph::Graph()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	UserCount = 0;
}

Graph::~Graph()
{
}

void Graph::addUser(std::string name)
{
	for (int i = 0; i < UserCount; i++)
	{
		if (userName[i] == name)
		{
			std::cout << "Данный пользователь уже добавлен!" << std::endl;
			return;
		}
	}
	userName[UserCount] = name;
	vertexes[UserCount] = UserCount;
	UserCount++;
}

void Graph::addFriends(std::string UserName, std::string friendsName)
{
	int indexUser = -1;
	int indexFriend = -1;
	for (int i = 0; i < UserCount; i++)
	{
		if (UserName == userName[i])
		{
			indexUser = i;
		}
		if (friendsName == userName[i])
		{
			indexFriend = i;
		}
	}
	if (indexUser == -1 || indexFriend == -1)
	{
		std::cout << "Пользователь не найден!" << std::endl;
		return;
	}

	matrix[indexUser][indexFriend] = 1;
	matrix[indexFriend][indexUser] = 1;
}

void Graph::print()
{
	for (int i = 0; i < UserCount; i++)
	{
		for (int j = 0; j < UserCount; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Graph::findMinDistancesFloyd()
{
	int weights[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
			{
				weights[i][j] = 0;
			}
			else
			{
				if (!edgeExists(i, j))
					weights[i][j] = VERYBIGINIT;
				else
					weights[i][j] = matrix[i][j];
			}
			
		}
	}
	for (int k = 0; k < UserCount; k++)
	{
		int ck = vertexes[k];
		for (int i = 0; i < UserCount; i++)
		{
			if (i == k)
			{
				continue;
			}
			int ci = vertexes[i];
			for (int j = 0; j < UserCount; j++)
			{
				if (j == i)
				{
					continue;
				}
				int cj = vertexes[j];
				if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
				{
					weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
				}
			}

		}
	}
	for (int i = 0; i < UserCount; i++)
	{
		for (int j = 0; j < UserCount; j++)
		{
			if (i == j)
			{
				continue;
			}
			std::cout << userName[i] << " - " << userName[j] << ": " << weights[i][j] << ". ";
		}
		std::cout << std::endl;
	}
	std::cout<<std::endl;
	std::cout << "Все пары знакомств через три рукопожатия:" << std::endl;
	for (int i = 0; i < UserCount; i++)
	{
		for (int j = 0; j < UserCount; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (weights[i][j] <= 3)
				std::cout << userName[i] << " - " << userName[j] << std::endl;
		}
	}
}

bool Graph::edgeExists(int i, int j)
{
	return matrix[i][j];
}
