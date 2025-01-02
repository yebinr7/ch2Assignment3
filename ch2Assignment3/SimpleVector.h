#pragma once

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


public:
	void push_back(const T& var);
	void pop_back();
	int size();
	int capacity();

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
	delete[]_data; //배열은 항상 삭제이렇게 
};

template<typename T>
inline void SimpleVector<T>::push_back(const T& var)
{
	if (_currentSize >= _currentCapacity)
		return;//아무일 일어나지 않는다.

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
;
