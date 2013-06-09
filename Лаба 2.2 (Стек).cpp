// Лаба 2.2 Стек.cpp: определяет точку входа для консольного приложения.
//  by Ливинский Ф.

#include "stdafx.h"
#include <time.h>
#include <locale.h>
#include <iostream>
using namespace std;

int n;

struct Stack
{
	int *arr;
	int count;
};

void Initial (int N, Stack *&p) 
	//Инициализация стека
{
	p=new Stack[N];
	p->arr=new int[N];
	p->count=0;
}

bool CheckFull (Stack *&p) 
	//Проверка стека на полноту
{
	if (p->count==n)
		return true;
	else
		return false;
}

bool CheckEmpty (Stack *&p) 
	//Проверка стека на пустоту
{
	if (p->count==0)
		return true;
	else
		return false;
}

void push(int a, Stack *&p) 
	//Добавление элемента в стек
{
	if (CheckFull(p)==0)
	{
		p->arr[p->count]=a;
		p->count++;
	}
	else
		cout <<"Ошибка! Стек полон." << endl;
}

void pop (Stack *&p) 
	//Удаление элемента из стека
{
	if (CheckEmpty(p)==0)
		p->count--;
	else
		cout <<"Ошибка! Стек пуст." << endl;
}

void ShowStack (Stack *&p)
{
	for (int i=0; i<p->count; i++)
		cout << p->arr[i] << endl;
}

void ShowElement (int num, Stack *&p)
{
	for (int i=0; i<p->count; i++)
	{
		if (i==(num-1))
			cout <<"Элемент №" << num << ": " << p->arr[i] << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Stack *p;
	cout <<"Введите размерность стека: ";
	cin >> n;
	Initial (n, p);			//Инициализируем стек

	for(int i = 0; i < n; i++)
		push (rand()%100, p);

	ShowStack(p);			//Выводим стек
	pop(p);					//Удаляем элемент из стека
	cout << endl;
	cout << "После удаления" << endl;
	ShowStack(p);			//Выводим стек
	cout << endl;
	ShowElement (2, p);		//Показываем элемент по номеру
	system("pause");
}
