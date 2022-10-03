#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
	
	LinkedList *list = new LinkedList();

	list->add(4);
	list->add(5);
	list->add(2);
	list->add(1);
	list->add(8);

	list->print();

	return 0;
}