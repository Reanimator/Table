#pragma once
#include <iostream>

template<class K, class V>
class table
{
private:
	K* masskey;//массив ключей
	V* massval;//массив значений
	int size,used;//количество используемых и размер массивов

public:
	table(int size);// ќнстурктор принимает размер массива
	~table();//десструктор

	void dobavit(K k, V v);//добавл€ем по ключу значение
	void udalit(K k);// удал€ем по ключу
	V& operator[](K k);//получаем значение по ключу
	table& operator = (table& vt);//оператор копирование
	void resize(int newsized);//ресайз

};

template<class K, class V>
table<K,V>::table(int size)
{
	this->size = size;
	masskey = new K[size];
	for (size_t i = 0; i < size; i++)
	{
		masskey[i] = K();
	}
	massval = new V[size];
	used = 0;
}

template<class K, class V>
table<K, V>::~table()
{
	delete[]masskey;
	delete[]massval;
}

template<class K, class V>
void table<K, V>::dobavit(K k, V v)
{
	for (size_t i = 0; i < size; i++)//проходим по всем умассиву
	{
		if (masskey[i] == K())//пока не находим свободный
		{
			masskey[i] = k;//занесли ключ
			massval[i] = v;//занесли значение
			used++;//увеличили счЄтчик
			return;
		}
	}

	throw 1;//если не нашли то таблица заполненна

}

template<class K, class V>
void table<K, V>::udalit(K k)
{
	for (int i = 0; i < size; i++)//проходим по всему массиву
	{
		if (masskey[i] == k)//пока не нашли совпадающий
		{
			used--;//уменьшили счЄтчик
			masskey[i] = K();//очистили ключ
			break;
		}
	}
}

template<class K, class V>
V & table<K, V>::operator[](K k)
{
	for (int i = 0; i < size; i++)
		if (masskey[i] == k)//пока не нашли совпадение ключей
			return massval[i];//вернули значение по индексу

		throw 1;//иначе такого ключа нету

}


template<class K, class V>
table<K,V> & table<K, V>::operator=(table & vt)
{
	size = vt.size;
	masskey = new K[size];
	massval = new V[size];
	used = vt.used;
	for (int i = 0; i < size; i++)
	{
		masskey[i] = vt.masskey[i];
		massval[i] = vt.massval[i];
	}

	return *this;
}

template<class K, class V>
void table<K, V>::resize(int newsized)
{
		if (newsized == size)
			return;
		if (newsized < used)//проверили размер
			throw 1;

		K* keys = new K[newsized];//создали новый массив
		V* vals = new V[newsized];//и ещЄ один новый
		size_t insertindex = 0;//пор€дковый номер в новом массиве
		for (int i = 0; i < size; i++)
		{
			if (masskey[i] != K())//пока ключ не пуст
			{
				keys[insertindex] = masskey[i];//копируем в новый массив в новый инекс
				vals[insertindex] = massval[i];
				++insertindex;//увеличиваем индекс нового массива
			}
		}
		delete[]masskey, massval;//высвобождаем пам€ть
		masskey = keys;//мен€ем указатели
		massval = vals;
		size = newsized;//мен€ем пам€ть
}
