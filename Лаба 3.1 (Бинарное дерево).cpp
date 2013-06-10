// Лаба 3.1 Бинарное дерево.cpp: определяет точку входа для консольного приложения.
//  by Ливинский Ф.

#include "stdafx.h"
#include <time.h>
#include <locale.h>
#include <iostream>
using namespace std;

class Tree
{
	int lvl;		//Уровень дерева
	int right_key,		//Правый ключ
		left_key,	//Левый ключ
		m_Count;	//Количество элементов
	int *top;		//Массив под дерево
	bool full;		//Проверка полное или пустое дерево
public:
	Tree()
	{
		lvl=0;
		top=0;
		right_key=0;
		left_key=0;
	}

	void Fill(int lv, int max_count) 
		//Заполнение дерева
	{
		full=false;
		cout << "Как много ветвей вы хотите добавить: ";
		int c;
		cin >> c;

		if (c==pow(2.0, lv))
			full=true;
		m_Count=c;

		lvl=lv;
		top=new int[max_count];

		cout << "Введите ветвь: " << endl;
		for (int i=0; i<m_Count; i++)
			cin >> top[i];

		for (int i = m_Count; i<max_count; i++)
			top[i] = 0;
	}

	int Check() 
		//Проверяем ветвь на полноту
	{
		if (full)
		{
			return -1;
		}
		else
			return m_Count;
	}

	int Check1() 
		//Проверяем ряд на пустоту
	{
		if (m_Count != 0)
			return m_Count;
		else
			return 0;
	}

	void Add(int Element, int lv, int kol_max, int position) 
		//Добавление элемента справа на пустое место или на новый уровень
	{
		full=false;
		lvl=lv;

		if (position==0)
		{
			m_Count=0;
			if ((m_Count+1)==pow(2.0, lv))
			{
				full=true;
			}
			else
				m_Count+=1;

			top=new int[kol_max];

			for (int i=m_Count; i<kol_max; i++)
				top[i]=0;
		}
		else
		{
			m_Count+=1;
			if (m_Count==pow(2.0, lv))
			{
				full=true;
			}
		};

		top[position]=Element;
		cout << "\n" << m_Count << "\n";
	}

	void Delete() 
		//Удаляем крайний правый элемент
	{
		if (m_Count!=0)
		{
			top[m_Count]=0;
			--m_Count;
			if (full)
				full=false;
		}
		cout << "\n";
	}

	void Print(int lvl_num) 
		//Выводим дерево
	{
		int k1=lvl_num-lvl;
		k1=pow(2.0, k1);
		for(int emp=(m_Count); emp>=0; emp--)
		{
			if (emp==(m_Count))
				for (int j=1; j<k1; j++)
					cout << " ";
			else
			{
				for (int i=0; i<m_Count; i++)
				{
					cout << top[i];
					emp--;
					for(int j=1; j<((2*k1)+1); j++)
						cout << " ";
				}
				cout << "\n";
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int lvl_number;
	cout << "Введите высоту дерева: ";
	cin >> lvl_number;
	Tree *A, *B;
	B=new Tree[lvl_number];		//Выделяем память

	for (int i=0; i<lvl_number; i++)
	{
		//Заполняем уровни
		cout<<"Уровень "<< i <<". Включает ветви: "<<endl;
		int k;
		k = pow(2.0,i);
		B[i].Fill(i, k);
	}
	cout << "Печать дерева: " << endl;

	for (int i = 0; i<lvl_number; i++)
		B[i].Print(lvl_number-1);

	bool first=true;

	//Добавим элемент, проверив сначала полноту уровня
	cout << "\nДобавить элемент 7: " << endl;

	if (B[lvl_number-1].Check()==-1)
	{
		A=new Tree[lvl_number];

		for (int i=0; i<lvl_number; i++)
			A[i]=B[i];
		++lvl_number;
		int i;
		B=new Tree[lvl_number];

		for (i=0; i<lvl_number-1; i++)
			B[i]=A[i];

		int k;
		k=pow(2.0,(lvl_number-1));
		i=lvl_number - 1;
		B[i].Add(7, lvl_number-1, k, 0);

		for (int i=0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}
	else
	{
		int pos;
		pos=B[lvl_number-1].Check();
		int k;
		k=pow(2.0,(lvl_number-1));
		int i=lvl_number - 1;
		B[i].Add(7, lvl_number-1, k, pos);

		for (int i=0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}

	//Теперь удалим элемент, проверив предварительно пустоту уровня
	cout << "После удаления: " << endl;
	if (B[lvl_number-1].Check1()!=0)
	{
		int i=lvl_number - 1;
		B[i].Delete();

		for (int i=0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}
	else
	{
		A=new Tree[lvl_number];

		for (int i=0; i<lvl_number; i++)
			A[i]=B[i];
		--lvl_number;
		int i;
		B=new Tree[lvl_number];

		for (i=0; i<lvl_number; i++)
			B[i]=A[i];

		int k;
		k=pow(2.0,(lvl_number-1));
		i=lvl_number - 1;
		B[i].Delete();

		for (int i=0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}
	system("pause");
}
