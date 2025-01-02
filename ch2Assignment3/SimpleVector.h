#pragma once
#include <algorithm>//sort�̿��ϱ� ���ؼ� ��¿�� ���� ��Ŭ���
#include <iostream>//cout �Ϸ���..

//Ÿ�� ���� x ���ø� �̿�
//������, �⺻ ������ ũ��10�� �迭
//�����ϳ� �޴� ������ �׸�ŭ ũ�� �迭 ����

//push_back �� �ڿ� �߰�, ������ �߰��ص� �ƹ� ����x
//pop_back �ǵ� ���� ���� , ������ ���� ���ٸ� ����x 
//size ���� ���� ���� ���� ��ȯ 
//capacity �迭�� ũ�� ��ȯ 

template <typename T>
class SimpleVector
{
public:
	SimpleVector();
	SimpleVector(int n);
	~SimpleVector();

	//���� ������
	//SimpleVector(const T& other);//->��ȣ�� int ������ �� �����ڶ�����.
	SimpleVector(const SimpleVector<T>& other);



	////���� ������
	//T& operator=(const T& other);

	////���� ������
	//SimpleVector(T&& other/*�����ǻ�����ϴϱ�*/);

	////���� ������ 
	//T& operator=(T&& other);


public:
	void push_back(const T& var);
	void pop_back();
	int size();
	int capacity();
	void resize(int newCapacity);
	void sortData();//sort�̿�
	void printVector();

private:

	T* _data; //������ -> rule of five ��Ű�� 
	int _currentSize;//���� ������ ����ִ� ũ��
	int _currentCapacity;//�迭�� �뷮(�� ������)
};







template<typename T>
inline SimpleVector<T>::SimpleVector()
	:_data(new T[10]),
	_currentSize(0),
	_currentCapacity(10) //�̴ϼȶ�������� 
{
	//�⺻�� capacity 10���� �����
	//_data = new T[10];
	//0���� ��� �ʱ�ȭ
	/*int c = capacity();
	for (size_t i = 0; i < c ; i++)
	{
		_data[i] = 0;
	}*/

};

template<typename T>
inline SimpleVector<T>::SimpleVector(int n)
	:_data(new T[n]),
	_currentSize(0),
	_currentCapacity(n)
{
	//int c = capacity();
	//for (size_t i = 0; i < c; i++)
	//{
	//	_data[i] = 0;
	//}
};

//�Ҹ���
template<typename T>
inline SimpleVector<T>::~SimpleVector()
{
	delete[]_data; //�迭�� �׻� �����̷��� 
}

//���������
template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
	:_currentSize(other._currentSize),
	 _currentCapacity(other._currentCapacity)
{
	//�����ʹ� ����
	_data = new T[_currentCapacity];
	//���빰 �����ؿ���

	for (size_t i = 0; i <_currentSize ; i++)
	{
		_data[i] = other._data[i];
	}
}

//////���� ������
//template<typename T>
//inline SimpleVector<T>::SimpleVector(const T& other)
//{
//
//}


////���� ������
//template<typename T>
//inline T& SimpleVector<T>::operator=(const T& other)
//{
//	// TODO: ���⿡ return ���� �����մϴ�.
//}
//
////�̵� ������
//template<typename T>
//inline SimpleVector<T>::SimpleVector(T&& other)
//{
//}
//
//
////�̵� ������
//template<typename T>
//inline T& SimpleVector<T>::operator=(T&& other)
//{
//	// TODO: ���⿡ return ���� �����մϴ�.
//}




template<typename T>
inline void SimpleVector<T>::push_back(const T& var)
{
	if (_currentSize >= _currentCapacity)
	{
		//�迭�� ���� á�����
		//���� �迭���� 5��ŭ �ø��� �ű�� �߰�
		//�� �迭 ���� �����
		_currentCapacity += 5;//5��ŭ �ø���
		T* newArray = new T[_currentCapacity];

		for (size_t i = 0; i < _currentSize; i++)
		{
			newArray[i] = _data[i]; //���빰 ����
		}
		delete[] _data;
		_data = nullptr;
		_data = newArray;//�ּ� ��������
	}

	_data[_currentSize] = var;
	_currentSize++;
}
template<typename T>
inline void SimpleVector<T>::pop_back()
{
	if (_currentSize <= 0)
		return; //0���� �ƹ����� �Ͼ�� �ʴ´�.

	_currentSize--; //�����ʹ� ������� ���X ��¥�� Size�� index������ 
}
template<typename T>
inline int SimpleVector<T>::size()
{
	return _currentSize;
}
template<typename T>
inline int SimpleVector<T>::capacity()
{
	return _currentCapacity;
}

template<typename T>
inline void SimpleVector<T>::resize(int newCapacity)
{
	//���� �ϳ� �ް���� ������ ���� �迭�� capacity���� ������ return;
	if (newCapacity <= _currentCapacity)
		return;
	else
	{
		//ũ�� ���Ҵ� & ���� 
		
		T* newArray = new T[newCapacity];

		for (size_t i = 0; i < _currentSize; i++)
		{
			newArray[i] = _data[i]; //���빰 ����
		}
		delete[] _data;
		_data = nullptr;
		_data = newArray;//�ּ� ��������
		_currentCapacity = newCapacity; //���ο�capa�� ����
	}
}
template<typename T>
inline void SimpleVector<T>::sortData()
{
	std::sort(_data, _data + _currentSize); //std �����Ϳ��� �����ֱ���..
}

template<typename T>
inline void SimpleVector<T>::printVector()
{
	std::cout << "���� ���� ������: " << _currentSize << ", ";
	std::cout << "���� ���� �뷮: " << _currentCapacity << "\n";
	std::cout << "���� �迭 ���:";
	for (size_t i = 0; i < _currentSize; i++)
	{
		if (i >= _currentSize-1)
		{
			std::cout << _data[i] << std::endl;
		}
		else
		{
			std::cout << _data[i] << ", ";
		}
	}
	//size�� 0�ΰ��
	if (_currentSize == 0)
		std::cout << "����� 0�Դϴ�.\n";
}
