#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::_total_n=0;

Example::Example(int data) {
	// (3)
	_total_n++;
	_now_n=_total_n;
	_data=data;
	cout<<"Example #"<<_now_n<<" is created"<<endl;
}

void Example::getData() {
	// (4)
	cout<<"The data of Example #"<<_now_n<<" is "<<_data<<endl;
}

Example::~Example() {
	// (5)
	//_total_n--;
	cout<<"Example #"<<_now_n<<" is destroyed"<<endl;
}