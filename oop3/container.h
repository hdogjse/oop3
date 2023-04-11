#pragma once
#include <iostream>

template <class T> class Container
{
protected:
	int size; //������
	T* mas; //��������� �� ������
public:
	Container() //����������� �� ���������
	{
		size = 1;
		mas = new T[size];
	}
	Container(int size) //����������� � �����������
	{
		this->size = size;
		mas = new T[this.size];
	}
	Container(const Container& container) //����������� �����������
	{
		size = container.size;
		mas = new T[size];
		for (int i = 0; i < size; ++i)
		{
			mas[i] = container.mas[i];
		}
	}
	~Container() //����������
	{
		delete[] mas;
	}


	void pushObject(int index, T* object) //��������� ������ � ��������� ��� ������
	{
		if (index >= size) index = size-1;
		if (index < 0) index = 0;

		T* nmas = new T[size + 1];

		for (int i = 0; i < index; ++i)
		{
			nmas[i] = mas[i];
		}

		for (int i = index + 1; i < size-1; ++i)
		{
			nmas[i] = mas[i];
		}

		nmas[index] = *object;

		delete[] mas;
		mas = nmas;
		++size;
	}
	void setObject(int index, T* object) //��������� ������ � �������
	{
		if (index >= size) index = size-1;
		if (index < 0) index = 0;
		mas[index] = *object;
	}
	T* delObject(int index) //������� ������ �� ����������
	{
		if (size == 1)
			return nullptr;
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;
		
		T* nmas = new T[size - 1];
		T object = mas[index];
		
		for (int i = 0; i < index; ++i)
		{
			nmas[i] = mas[i];
		}
		for (int i = index + 1; i < size-1; ++i)
		{
			nmas[i] = mas[i];
		}

		delete[] mas;
		mas = nmas;
		--size;
		return &object;
	}
	T* getObject(int index) //�������� ������ �� ����������
	{
		if (size == 0)
			return nullptr;
		if (index < 0) index = 0;
		if (index >= size) index = size-1;
		return &mas[index];
	}
	int getSize() //������ ����������
	{
		return size;
	}
};