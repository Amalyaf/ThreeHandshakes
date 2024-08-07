#pragma once
#include <iostream>

#define SIZE 100

class Graph
{
private:
	int matrix[SIZE][SIZE]; //матрица смежности, если дружат пользователи, то значение 1, в противном случае - 0
	int vertexes[SIZE]; //хранилище вершин
	std::string userName[SIZE]; //будут храниться имена пользователей под теми же индексами, что и в хранилище вершин
	int UserCount; //кол-во пользователей (вершин)
public:
	Graph();
	~Graph();
	void addUser(std::string name);
	int getIndex(std::string name);
	void addFriends(std::string UserName, std::string friendsName);
	void print();
	void findMinDistancesFloyd();
	bool edgeExists(int i, int j);
};