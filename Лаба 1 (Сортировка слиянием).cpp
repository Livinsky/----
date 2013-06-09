// Лаба 1 Сортировка слиянием.cpp: определяет точку входа для консольного приложения.
//	by Ливинский Ф.

#include <vector>
#include <time.h>
#include <locale.h>
#include <iostream>
using namespace std;

vector <int> merge (vector <int> a, vector <int> b)
	//Функция для слиияния двух векторов
{
   vector <int> c(a.size()+b.size());	//Результирующий вектор
					//Количество использованных вершин
    int kol1 = 0;	//	в векторе а
    int kol2 = 0;	//	в векторе b
		
		//Заполняем массив c
    for(int i = 0; i < c.size(); i++)
    {
			//Если мы уже полностью использовали вектора а,
			//	то нам осталось дописать элементы вектора b
        if(kol1==a.size())
        {
            c.at(i) = b.at(kol2);
            kol2++;
            continue;
        }
			//Наоборот
        if(kol2==b.size())
        {
            c.at(i) = a.at(kol1);
            kol1++;
            continue;
        }
			//Так как наши вектора еще не полностью использованы,
			//	то нужно сравнить какое значение ставить на следующее место
        if(a.at(kol1)<=b.at(kol2))
        {
            c.at(i) = a.at(kol1);
            kol1++;
        }
        else
        {
            c.at(i) = b.at(kol2);
            kol2++;
        }
    }
    return c;
}

vector <int> merge_sort(vector <int> a)
	//Функция для сортировки вектора
{
		//Если размер вектора меньше 1, то он отсортирован
    if(a.size()<=1)
        return a;
    vector <int> b, c;

    b.assign(a.begin(), a.end()-(a.size()/2));

    c.assign(a.end()-(a.size()/2), a.end());

    return merge(merge_sort(b), merge_sort(c));
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
    vector <int> a;
	cout << "Исходный массив:" << endl;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(rand()%100);
		cout << a.at(i) << "  ";
    }
	cout << "\n\n";

    a=merge_sort(a);
	cout << "Массив после сортировки:" << endl;
    for(int i=0; i < a.size(); ++i)
    {
        cout << a.at(i) << "  ";
    }
	cout << "\n\n";
    system("pause");
}
