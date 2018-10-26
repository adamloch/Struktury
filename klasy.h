#pragma once
#include <iostream>
class element
{
	friend class list_and_methods;
private:
	int number;
	element *next;
	element() { next = nullptr; };
};
class list_and_methods
{
private:
	element *first;
public:
	list_and_methods() { first = nullptr; };
	void push(int new_numb);
	void pop();
	void display();
	void insert(int new_numb, int adres);
	void pop_at(int loc);
	void delete_value(int value);
	void delete_list();
	void sort();
};

