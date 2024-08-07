#pragma once
#include <iostream>

#define SIZE 100

class Graph
{
private:
	int matrix[SIZE][SIZE]; //������� ���������, ���� ������ ������������, �� �������� 1, � ��������� ������ - 0
	int vertexes[SIZE]; //��������� ������
	std::string userName[SIZE]; //����� ��������� ����� ������������� ��� ���� �� ���������, ��� � � ��������� ������
	int UserCount; //���-�� ������������� (������)
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