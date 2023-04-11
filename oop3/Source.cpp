#include <iostream>
#include <time.h>
#include "container.h"
using namespace std;

class Object //������������ ����� �������
{
protected:
	int something;
public:
	Object()
	{
		something = 0;
	}
	void setsomething(int something) //������
	{
		this->something = something;
	}
	int getsomething() //������ 
	{
		return something;
	}
};
class DaughterObject : public Object //�������� ����� �������
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
	while (itterations <= 10000)	//���� ��� ������������ ����������
	{
		long double time = 0;
		clock_t start = clock();
		for (int i = 0; i < itterations; ++i)
		{
			switch (rand() % 3)	//��������� ��������
			{
			case 0:
				storage.pushObject(rand() % itterations, new DaughterObject); //��������� ������
				break;
			case 1:
				storage.delObject(rand() % itterations); //�������
				break;
			case 2:
				int setget = rand() % 2;
				if (setget == 0) storage.getObject(rand() % itterations)->getsomething(); //������ �������
				else storage.getObject(rand() % itterations)->setsomething(rand()%100); //������
				break;
			}
		}
		clock_t end = clock();
		time += (long double)(end - start) / CLOCKS_PER_SEC; //������� �����
		cout << itterations << " ��������: " << time << " ������" << endl; //�����
		itterations *= 10;
	}
}