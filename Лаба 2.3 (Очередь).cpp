// Лаба 2.3 Очередь.cpp: определяет точку входа для консольного приложения.
//  by Ливинский Ф.

#include "stdafx.h"
#include <time.h>
#include <locale.h>
#include <iostream>
using namespace std;

int n;	//Размерность очереди

struct Ochered
{
	int *arr;
	int first;
	int last;
	int count;
};

void Initial (int N, Ochered *&p) 
	//Инициализация стека
{
	p=new Ochered[N];
	p->arr=new int[N];
	p->first=0;
	p->last=0;
	p->count=0;
}

bool Full (Ochered *&p)
	//Проверка на полноту
{
	if (p->count==n)
		return true;
	else
		return false;
}

bool Empty (Ochered *&p)
	//Проверка на пустоту
{
	if (p->count==0)
		return true;
	else
		return false;
}

void add (int a, Ochered *&p)
	//Добавление в очередь
{
	if (Full(p)==false)
	{
		p->arr[p->last]=a;
		p->last++;
		if (p->last==n)
		p->last=0;
		p->count++;
	}
	else
		cout <<"Ошибка! Очередь заполнена." << endl;
}

void del (Ochered *&p)
	//Удаление из очереди
{
	if (Empty(p)==false)
	{
		p->arr[p->first]=0;
		p->first++;
		if (p->first==n)
		p->first=0;
		p->count--;
	}
	else
		cout <<"Ошибка! Очередь пустая." << endl;
}

void Show(Ochered *p) 
	//Вывод очереди
{
	int i, temp; 
	for (i=p->first, temp=0; temp < p->count ; temp++, i++) 
	{ 
		if (i==n) 
			i=0; 
		cout << p->arr[i] << endl; 
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Ochered *p;
	cout << "Введите размерность очереди: ";
	cin >> n;
	Initial(n, p);					//Инициализируем очередь

	for (int i = 0; i<n; i++)		//Заполняем ее
		add(rand()%100, p);

	Show(p);
	cout << endl;
	cout << "После удаления: " <<endl;
	del(p);
	Show(p);
	system("pause");
}
