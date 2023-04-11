#pragma once
#include <iostream>

template <class T> class Container
{
protected:
	int size; //размер
	T* mas; //указатель на массив
public:
	Container() //конструктор по умолчанию
	{
		size = 1;
		mas = new T[size];
	}
	Container(int size) //конструктор с параметрами
	{
		this->size = size;
		mas = new T[this.size];
	}
	Container(const Container& container) //конструктор копирования
	{
		size = container.size;
		mas = new T[size];
		for (int i = 0; i < size; ++i)
		{
			mas[i] = container.mas[i];
		}
	}
	~Container() //деструктор
	{
		delete[] mas;
	}


	void pushObject(int index, T* object) //добавляем объект в контейнер без замены
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
	void setObject(int index, T* object) //добавляем объект с заменой
	{
		if (index >= size) index = size-1;
		if (index < 0) index = 0;
		mas[index] = *object;
	}
	T* delObject(int index) //удаляем объект из контейнера
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
	T* getObject(int index) //получаем объект из контейнера
	{
		if (size == 0)
			return nullptr;
		if (index < 0) index = 0;
		if (index >= size) index = size-1;
		return &mas[index];
	}
	int getSize() //размер контейнера
	{
		return size;
	}
};