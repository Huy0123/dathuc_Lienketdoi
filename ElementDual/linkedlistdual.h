#pragma once
#include"ElementDual.h"
#include<iostream>
class linkedlistdual
{
private:
	ElementDual* head;
	ElementDual* tail;
public:
	bool addHead(ElementDual* a);
	bool addTail(ElementDual* a);
	void display();
	double evaluate(int inputValue);
	void inputPolynomial();
	linkedlistdual* add(linkedlistdual* a);
	linkedlistdual* multiply(linkedlistdual* a);
	bool deleteMiddle(ElementDual* a);
	void rutgon();
};

