#include <iostream>
#include "SimpleVector.h"

using namespace std;


int main(void)
{
	SimpleVector<int> sv1;
	SimpleVector<int> sv2(4);
	sv2.printVector();
	
	sv1.push_back(11);//<-초과일때 if문 되는지체크
	sv1.push_back(10);
	sv1.push_back(9);
	sv1.push_back(8);
	sv1.push_back(7);
	sv1.push_back(6);
	sv1.push_back(5);
	sv1.push_back(4);
	sv1.push_back(3);
	sv1.push_back(2);
	sv1.push_back(1);
	
	sv1.sortData();//오름차순 정렬 
	sv1.printVector();

	SimpleVector<int> sv3(sv1);//복사 생성자 실행
	sv3.printVector();
	sv3.push_back(12);//사이즈초과시 재할당&복사(이사)
	sv3.printVector();


	sv3.resize(1000);//사이즈 재할당 & 복사(이사)
	sv3.printVector();


	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();
	sv1.pop_back();//<-초과일때 if문 되는지체크
	sv1.printVector();

	for (size_t i = 0; i < 12; i++)
	{
		sv3.pop_back();
	}
	sv3.printVector();

	return 0;
}
