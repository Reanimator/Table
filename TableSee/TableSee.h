#pragma once
#include <iostream>

template<class K, class V>
class table
{
private:
	K* masskey;//������ ������
	V* massval;//������ ��������
	int size,used;//���������� ������������ � ������ ��������

public:
	table(int size);//����������� ��������� ������ �������
	~table();//�����������

	void dobavit(K k, V v);//��������� �� ����� ��������
	void udalit(K k);// ������� �� �����
	V& operator[](K k);//�������� �������� �� �����
	table& operator = (table& vt);//�������� �����������
	void resize(int newsized);//������

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
	for (size_t i = 0; i < size; i++)//�������� �� ���� ��������
	{
		if (masskey[i] == K())//���� �� ������� ���������
		{
			masskey[i] = k;//������� ����
			massval[i] = v;//������� ��������
			used++;//��������� �������
			return;
		}
	}

	throw 1;//���� �� ����� �� ������� ����������

}

template<class K, class V>
void table<K, V>::udalit(K k)
{
	for (int i = 0; i < size; i++)//�������� �� ����� �������
	{
		if (masskey[i] == k)//���� �� ����� �����������
		{
			used--;//��������� �������
			masskey[i] = K();//�������� ����
			break;
		}
	}
}

template<class K, class V>
V & table<K, V>::operator[](K k)
{
	for (int i = 0; i < size; i++)
		if (masskey[i] == k)//���� �� ����� ���������� ������
			return massval[i];//������� �������� �� �������

		throw 1;//����� ������ ����� ����

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
		if (newsized < used)//��������� ������
			throw 1;

		K* keys = new K[newsized];//������� ����� ������
		V* vals = new V[newsized];//� ��� ���� �����
		size_t insertindex = 0;//���������� ����� � ����� �������
		for (int i = 0; i < size; i++)
		{
			if (masskey[i] != K())//���� ���� �� ����
			{
				keys[insertindex] = masskey[i];//�������� � ����� ������ � ����� �����
				vals[insertindex] = massval[i];
				++insertindex;//����������� ������ ������ �������
			}
		}
		delete[]masskey, massval;//������������ ������
		masskey = keys;//������ ���������
		massval = vals;
		size = newsized;//������ ������
}
