// Лаба 4.1 Двоичное сбалансированное дерево.cpp: определяет точку входа для консольного приложения.
//  by Ливинский Ф.

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <list>
#include <locale.h>

using namespace std;

class Graph //Граф
{
	int top1, top2, //Вершина графа (величина) для конечностей ребра
		Link;		//Длина связи
public:
	Graph()
	{
		top1 = 0;
		top2 = 0;
		Link = 0;
	}

	Graph(int length, int FirstT, int SecondT) 
		//Подаём параметры величины и вершин
	{
		top1 = FirstT;
		top2 = SecondT;
		Link = length;
	}

	int FindTop(int Chis) 
		//Находим следующую вершину
	{
		if(top1 == Chis)
			return top2; 

		else if(top2 == Chis)
			return top1;

		else
			return 0;
	}

	int GetLenth()
		//Получить длину ребра (связи)
	{
		return Link; 
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int top_Number, *Ways, LinksN;			//Количество вершин, кратчайшие пути из единицы
	int EdgeValue, Neighbour1, Neighbour2;
	list <Graph> Edge;						//Список из ребер графа
	list <Graph> :: iterator Iter1;			//Итератор

	cout << "Enter number of tops: ";
	cin >> top_Number;
	cout << "Enter number of edges (top links): ";
	cin >> LinksN;

	Ways = new int[top_Number-1];			//Создаем пути ( по количеству вершин - 1)

	for (int i = 0; i<top_Number-1; i++)
		Ways[i] = 99999999;					//Значение считается бесконечностью (пути не существует)

	cout << endl << endl << "Enter information about \n";
	Iter1 = Edge.end();						//Итератор на конец списка для добавления

	for(int i = 0; i<LinksN; i++)
	{
		cout << "\nEdge " << i+1 << ": Enter value of edge: ";
		cin >> EdgeValue;
		cout << "The top of which it connects: ";
		cin >> Neighbour1;
		cin >> Neighbour2;
		Edge.push_back(Graph(EdgeValue, Neighbour1, Neighbour2));	//Записываем в конец списка новые элементы 
	}

	cout << endl << endl << "Применим алгоритм Дейкстры\n";
	int CurPnt, point, lenth;
	for (int i = 0; i<top_Number; i++)
	{
		CurPnt = i + 1;				//Получение точки 
		Iter1 = Edge.begin();		//Начало списка

		while(Iter1 != Edge.end())
		{
			point = (*Iter1).FindTop(CurPnt); 
			//Ищем соседние элементы, соединения
			if(point >= CurPnt)
			{
				//Находим пути, запоминаем и сравниваем с предыдущими путями
				lenth = (*Iter1).GetLenth();
				if (point - 3 >=0)
				{
					if (Ways[point - 2] > lenth + Ways[point - 3])
						Ways[point - 2] = lenth + Ways[point - 3];
					*Iter1++;
				}
				else
				{
					if (Ways[point - 2] > lenth)
						Ways[point - 2] = lenth;
					*Iter1++;
				}
			}
			else
			{
				*Iter1++;
			}
		}
	}
	for (int i = 0; i<top_Number-1; i++) 
		//Показать путь
	{
		cout << "distance from top "<< 1 << " to " << i+2 << ": ";
		if (Ways[i] == 99999999)
			cout << "Infinity\n";
		else
			cout << Ways[i] << endl;
	}
	system("pause");
}
