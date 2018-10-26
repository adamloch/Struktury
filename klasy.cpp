#include "klasy.h"


void list_and_methods::display()
{
	if (first == nullptr)
	{
		std::cout << "Error 213521423253 .List is empty\n";
		return;
	}
	element *ptr = first;
	while (ptr->next != nullptr)
	{
		std::cout << ptr->number << ";";
		std::cout << ptr->next << "    ";
		ptr = ptr->next;
	}
	std::cout << ptr->number << ";";
	std::cout << ptr->next << " \n";
}
void list_and_methods::insert(int new_num, int loc)
{
	element *ptr = first;
	for (int i = 0; i < loc; i++)
	{
		ptr = ptr->next;
		if (ptr == nullptr)
		{
			std::cout << "Error 404 .Localization not found\n";
			return;
		}
	}
	ptr->number = new_num;
}
void list_and_methods::pop()
{
	if (first == nullptr)
		std::cout << "Error .There are no elements in the list\n";
	else
	{
		element *temp = first->next;
		delete first;
		first = temp;
	}
}
void list_and_methods::push(int new_numb)
{
	if (first == nullptr)
	{
		first = new element;
		first->number = new_numb;
	}
	else
	{
		element *temp = new element;
		temp->next = first;
		temp->number = new_numb;
		first = temp;
	}
}
void list_and_methods::pop_at(int loc)
{
	if (loc == 0)
	{
		pop();
		return;
	}
	if (first == nullptr)
	{
		std::cout << "Error 234 .List is empty\n";
		return;
	}
	element *ptr = first;
	element *ptr2 = nullptr;
	for (int i = 0; i < loc; i++)
	{
		if (i == loc - 1)
			ptr2 = ptr;
		ptr = ptr->next;
		if (ptr == nullptr)
		{
			std::cout << "Error 404 .Localization not found\n";
			return;
		}
	}
	ptr2->next = ptr->next;
	delete ptr;
}
void list_and_methods::delete_value(int value)
{
	if (first == nullptr)
		std::cout << "Error 235 .List is empty\n";
	while (first->number == value)
		pop();
	element *ptr = first;
	element *ptr2 = first->next;
	while (ptr2 != nullptr)
	{
		if (ptr2->number == value)
		{
			ptr->next = ptr2->next;
			delete ptr2;
			ptr2 = ptr->next;
		}
		else
		{
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
	}
}
void list_and_methods::delete_list()
{
	if (first == nullptr)
		std::cout << "Error .There are no elements in the list\n";
	while (first != nullptr)
	{
		element *temp = first->next;
		delete first;
		first = temp;
	}
	first = nullptr;
}
void list_and_methods::sort()
{
	bool sorted = false;
	while (sorted == false)
	{
		int clear_run = 0;
		element *ptr = first;
		element *ptr2 = first->next;
		while (ptr2 != nullptr)
		{
			if (ptr->number > ptr2->number)
			{
				int temp = 0;
				temp = ptr2->number;
				ptr2->number = ptr->number;
				ptr->number = temp;
				sorted = false;
				clear_run++;
			}
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}
		if (clear_run == 0)
			sorted = true;
	}
}