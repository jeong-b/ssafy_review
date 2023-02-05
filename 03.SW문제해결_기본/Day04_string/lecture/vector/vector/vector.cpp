/*
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v; // v(paremeter) 0으로 초기화, 동적배열

int main()
{
	v.push_back(1); // 맨 뒤로 원소룰 하나 추가
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	v.pop_back(); // 맨 뒤의 원소를 하나 지움

	cout << v.front() << "\n";
	cout << v.back();
	return 0;
}