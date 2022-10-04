#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
	
	LinkedList *list = new LinkedList();

	list->add2(4);
	list->add2(5);
	list->add2(2);
	list->add2(1);
	list->add2(8);

	list->print();
	list->reverse();
	return 0;
}