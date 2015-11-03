// iterTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	list<int> li = { 1, 2, 3, 4, 5 };
	list<int>::iterator iter = li.begin();
	li.push_back(11);
	for (list<int>::iterator i = li.begin(); i != iter; i++){
		cout << *i << endl;
	}
	return 0;
}

