#include <iostream>
#include <time.h>
#include "container.h"
using namespace std;

class Object //Родительский класс объекта
{
protected:
	int something;
public:
	Object()
	{
		something = 0;
	}
	void setsomething(int something) //сеттер
	{
		this->something = something;
	}
	int getsomething() //геттер 
	{
		return something;
	}
};
class DaughterObject : public Object //Дочерний класс объекта
{
public:
	DaughterObject() : Object()
	{
		something = 1;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int itterations = 100;
	Container<Object> storage;
	while (itterations <= 10000)	//цикл для тестирования контейнера
	{
		long double time = 0;
		clock_t start = clock();
		for (int i = 0; i < itterations; ++i)
		{
			switch (rand() % 3)	//случайное действие
			{
			case 0:
				storage.pushObject(rand() % itterations, new DaughterObject); //добавляем объект
				break;
			case 1:
				storage.delObject(rand() % itterations); //удаляем
				break;
			case 2:
				int setget = rand() % 2;
				if (setget == 0) storage.getObject(rand() % itterations)->getsomething(); //геттер объекта
				else storage.getObject(rand() % itterations)->setsomething(rand()%100); //сеттер
				break;
			}
		}
		clock_t end = clock();
		time += (long double)(end - start) / CLOCKS_PER_SEC; //считаем время
		cout << itterations << " Итераций: " << time << " секунд" << endl; //вывод
		itterations *= 10;
	}
}