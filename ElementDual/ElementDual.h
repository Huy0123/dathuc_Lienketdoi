#pragma once

class ElementDual
{
private:
	float data;
	int exponent;
	ElementDual* prev, * next;
public:
	float getData();
	void setData(float data);
	ElementDual* getNext();
	void setNext(ElementDual* next);
	ElementDual* getPrev();
	void setPrev(ElementDual* prev);
	void setExponent(int exponent);
	int getExponent();
};

