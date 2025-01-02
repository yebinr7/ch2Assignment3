#pragma once
#include <algorithm>//sort이용하기 위해서 어쩔수 없이 인클루드
#include <iostream>//cout 하려고..

//타입 의존 x 템플릿 이용
//생성자, 기본 생성자 크기10인 배열
//숫자하나 받는 생성자 그만큼 크기 배열 만듬

//push_back 맨 뒤에 추가, 꽉차서 추가해도 아무 동작x
//pop_back 맨뒤 원소 제거 , 제거할 원소 없다면 동작x 
//size 인자 없고 원소 개수 반환 
//capacity 배열의 크기 반환 

template <typename T>
class SimpleVector
{
public:
	SimpleVector();
	SimpleVector(int n);
	~SimpleVector();

	//복사 생성자
	//SimpleVector(const T& other);//->모호함 int 들어오면 위 생성자랑같다.
	SimpleVector(const SimpleVector<T>& other);



	////복사 연산자
	//T& operator=(const T& other);

	////무브 생성자
	//SimpleVector(T&& other/*소유권뺏어야하니깐*/);

	////무브 연산자 
	//T& operator=(T&& other);


public:
	void push_back(const T& var);
	void pop_back();
	int size();
	int capacity();
	void resize(int newCapacity);
	void sortData();//sort이용
	void printVector();

private:

	T* _data; //포인터 -> rule of five 지키기 
	int _currentSize;//실제 데이터 담고있는 크기
	int _currentCapacity;//배열의 용량(총 사이즈)
};







template<typename T>
inline SimpleVector<T>::SimpleVector()
	:_data(new T[10]),
	_currentSize(0),
	_currentCapacity(10) //이니셜라이저사용 
{
	//기본형 capacity 10으로 만들기
	//_data = new T[10];
	//0으로 모두 초기화
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

//소멸자
template<typename T>
inline SimpleVector<T>::~SimpleVector()
{
	delete[]_data; //배열은 항상 삭제이렇게 
}

//복사생성자
template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
	:_currentSize(other._currentSize),
	 _currentCapacity(other._currentCapacity)
{
	//포인터는 조심
	_data = new T[_currentCapacity];
	//내용물 복사해오기

	for (size_t i = 0; i <_currentSize ; i++)
	{
		_data[i] = other._data[i];
	}
}

//////복사 생성자
//template<typename T>
//inline SimpleVector<T>::SimpleVector(const T& other)
//{
//
//}


////복사 연산자
//template<typename T>
//inline T& SimpleVector<T>::operator=(const T& other)
//{
//	// TODO: 여기에 return 문을 삽입합니다.
//}
//
////이동 생성자
//template<typename T>
//inline SimpleVector<T>::SimpleVector(T&& other)
//{
//}
//
//
////이동 연산자
//template<typename T>
//inline T& SimpleVector<T>::operator=(T&& other)
//{
//	// TODO: 여기에 return 문을 삽입합니다.
//}




template<typename T>
inline void SimpleVector<T>::push_back(const T& var)
{
	if (_currentSize >= _currentCapacity)
	{
		//배열이 가득 찼을경우
		//기존 배열보다 5만큼 늘리고 거기다 추가
		//힙 배열 새로 만들기
		_currentCapacity += 5;//5만큼 늘리기
		T* newArray = new T[_currentCapacity];

		for (size_t i = 0; i < _currentSize; i++)
		{
			newArray[i] = _data[i]; //내용물 복사
		}
		delete[] _data;
		_data = nullptr;
		_data = newArray;//주소 가져가기
	}

	_data[_currentSize] = var;
	_currentSize++;
}
template<typename T>
inline void SimpleVector<T>::pop_back()
{
	if (_currentSize <= 0)
		return; //0에선 아무일이 일어나지 않는다.

	_currentSize--; //데이터는 사라지던 상관X 어짜피 Size가 index역할함 
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
	//정수 하나 받고받은 정수가 지금 배열의 capacity보다 작으면 return;
	if (newCapacity <= _currentCapacity)
		return;
	else
	{
		//크면 재할당 & 복사 
		
		T* newArray = new T[newCapacity];

		for (size_t i = 0; i < _currentSize; i++)
		{
			newArray[i] = _data[i]; //내용물 복사
		}
		delete[] _data;
		_data = nullptr;
		_data = newArray;//주소 가져가기
		_currentCapacity = newCapacity; //새로운capa로 업뎃
	}
}
template<typename T>
inline void SimpleVector<T>::sortData()
{
	std::sort(_data, _data + _currentSize); //std 포인터에도 쓸수있구나..
}

template<typename T>
inline void SimpleVector<T>::printVector()
{
	std::cout << "현재 벡터 사이즈: " << _currentSize << ", ";
	std::cout << "현재 벡터 용량: " << _currentCapacity << "\n";
	std::cout << "현재 배열 요소:";
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
	//size가 0인경우
	if (_currentSize == 0)
		std::cout << "사이즈가 0입니다.\n";
}
