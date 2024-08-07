#include"Graph.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Graph g;
	g.addUser("Oleg");
	g.addUser("Nikita");
	g.addUser("Nastya");
	g.addUser("Vanya");
	g.addUser("Jenya");
	g.addUser("Oleg");
	g.print();

	g.addFriends("Oleg", "Nikita");
	g.addFriends("Nikita", "Nastya");
	g.addFriends("Nastya", "Vanya");
	g.addFriends("Vanya", "Jenya");

	g.print();

	g.findMinDistancesFloyd();
}