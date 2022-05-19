#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	// (6) 3-5
	Example static obj6(2333);
	for(int i=0;i<n;i++){
		e[i]->getData();
	}
	for(int i=0;i<n;i++){
		delete e[i];
		e[i]=NULL;
	}
	
	obj6.getData();
	
	cout << "--------create_example is over--------\n";
}

// (7)
Example static obj1(23);

int main() {

	cout << "--------main_function is ready--------\n";

	// (8)
	Example obj2(233);
		
	create_example(3);
	
	// (9)
	Example obj7(23333);
	obj1.getData();
	obj2.getData();
	obj7.getData();

	cout << "--------main_function is over---------\n";

	return 0;
}
