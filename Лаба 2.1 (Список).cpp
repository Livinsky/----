// Лаба 2.1 Список.cpp: определяет точку входа для консольного приложения.
//	by Ливинский Ф.

#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

struct List
{
	int value;
	List* next;

	void Add(int a, List *&p, List *&pF) 
		//Добавление элемента в начало списка
	{
		p=new List;
		p->value=a;
		p->next=pF;
		pF=p;
	}

	void GetValue (int n, List*p, List *pF)
		//Получение элемента из списка по его номеру
	{
		for (int i = 0; i < n; i++)
		{
			p=pF;
			pF=pF->next;
		}
		cout << "Значение: " << p->value << endl;
	}
	
	void Delete(int n, List *p, List *pF)
		//Удаление элемента из списка по номеру
	{
		int i;
		for (i=0; i<(n-1); i++)
		{
			p=pF;
			pF=pF->next;
		}
		pF=pF->next;

		for (i+=2; i<n; i++)
		{
			p=pF;
			pF=pF->next;
		}
	}
};


void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	List	*pFirst = NULL,	//Указатель на начало списка
			*p;				//Указатель на список
	int		n=5;			//Кол-во элементов в списке

	for (int i=0; i<n; i++) 
		//Заполним список случайными значениями
	{
		p->Add(rand()%100, p, pFirst);
	}

	//Выводим список
	while (p)
	{
		cout << p->value << endl;
		p=p->next;
	}

	//Выводим значение элемента из списка
	int m;
	cout << "Введите номер элемента списка: ";
	cin >> m;
	p->GetValue(m, p, pFirst);

	//Удаляем значение из списка
	int k;
	cout << "Введите номер элемента списка, который Вы хотите удалить: ";
	cin >> k;
	for (int i = 0; i<n; i++)
	{
		if ((i+1) == k)
		{
			p->Delete(k+1, p, pFirst);  
		}
		else	//Выводим список
		{
			p->GetValue(i+1, p, pFirst);
		}
	}
	system("pause");
}
