#pragma once

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


public:
	void push_back(const T& var);
	void pop_back();
	int size();
	int capacity();

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
	int c = capacity();
	for (size_t i = 0; i < c ; i++)
	{
		_data[i] = 0;
	}

};

template<typename T>
inline SimpleVector<T>::SimpleVector(int n)
	:_data(new T[n]),
	_currentSize(0),
	_currentCapacity(n)
{
	int c = capacity();
	for (size_t i = 0; i < c; i++)
	{
		_data[i] = 0;
	}
};


template<typename T>
inline SimpleVector<T>::~SimpleVector()
{
	delete[]_data; //�迭�� �׻� �����̷��� 
};

template<typename T>
inline void SimpleVector<T>::push_back(const T& var)
{
	if (_currentSize >= _currentCapacity)
		return;//�ƹ��� �Ͼ�� �ʴ´�.

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
;
