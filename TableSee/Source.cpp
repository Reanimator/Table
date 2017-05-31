#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{
	table<int,std::string> v(15);

	setlocale(NULL, "Russian");
		v.dobavit(12, std::string("Проверочная строка1"));//числа можно менять
		v.dobavit(31, std::string("Проверочная строка2"));//так же
		v.dobavit(15, std::string("Строка проверки №3"));//и так же

		cout << v[15] << endl;//соответствует число перед заптой
		cout << v[12] << endl;//так же
		cout << v[31] << endl;//и так же

		v.resize(6);
	
	
	cin.get();
}