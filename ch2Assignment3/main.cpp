#include <iostream>
#include "SimpleVector.h"

using namespace std;


int main(void)
{
	SimpleVector<int> sv1;
	SimpleVector<int> sv2(4);

	sv1.push_back(1);
	sv1.push_back(2);
	sv1.push_back(3);
	sv1.push_back(4);
	sv1.push_back(5);
	sv1.push_back(6);
	sv1.push_back(7);
	sv1.push_back(8);
	sv1.push_back(9);
	sv1.push_back(10);
	sv1.push_back(11);//<-�ʰ��϶� if�� �Ǵ���üũ

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
	sv1.pop_back();//<-�ʰ��϶� if�� �Ǵ���üũ


	return 0;
}
