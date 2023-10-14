#include "ElementDual.h"



float ElementDual::getData()
{
	return data;
}

void ElementDual::setData(float data)
{
	this->data = data;
}

ElementDual* ElementDual::getNext()
{
	return next;
}

void ElementDual::setNext(ElementDual* next)
{
	this->next = next;
}

ElementDual* ElementDual::getPrev()
{
	return prev;
}

void ElementDual::setPrev(ElementDual* prev)
{
	this->prev = prev;
}

void ElementDual::setExponent(int exponent)
{
	this->exponent = exponent;
}

int ElementDual::getExponent()
{
	return exponent;
}
