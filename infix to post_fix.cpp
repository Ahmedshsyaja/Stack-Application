#include <iostream>
#include <string>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	node* next;
};
struct node1
{
	char data;
	node1* next;
};
struct link {
	char data;
	link* next;
};
class Stack {
	link* top2 = NULL;
	link* nod = NULL;
	link* curr2;
	node* top = NULL;
	node1* top1 = NULL;
	node* curr = NULL;
	node1* curr1 = NULL;
	node1* symbol = NULL;
	node* number = NULL;
public:
	void push(string data) {
		char in = 0;
		for (int i = 0; i < data.length(); i++) {
			if (data[i] > 47 && data[i] < 58) {
				cout << data[i];
			}
			else {
				if (symbol == NULL) {
					curr1 = symbol;
					symbol = new node1;
					symbol->data = data[i];
					symbol->next = NULL;
					top1 = symbol;
				}
				else {
					calculate1(data[i]);
					curr1 = symbol;
					symbol = new node1;
					symbol->data = data[i];
					top1 = symbol;
					top1->next = curr1;
				}
				if (data[i] == ')') {
					calculate(data[i]);
				}
			}
		}
		while ( top1!= NULL) {
			pop();
		}
	};
	char calculate1(char x) {
		node1* temp = top1;
		node1* temp1 = temp;
		if (top1 == NULL) {
			return 0;
		}
		char data;
		if (temp->data == '*' && x == '+') {
			pop();
			return '+';
		}
		if (temp->data == '*' && x == '-') {
			pop();
			return '-';
		}
		if (temp->data == '*' && x == '*') {
			pop();
			return '*';
		}
		if (temp->data == '*' && x == '/') {
			pop();
			return '/';
		}
		if (temp->data == '/' && x == '+') {
			cout << temp->data;
			pop();
			return '+';
		}
		if (temp->data == '/' && x == '-') {
			pop();
			return '-';
		}
		if (temp->data == '/' && x == '*') {
			pop();
			return '*';
		}
		if (temp->data == '/' && x == '/') {
			pop();
			return '/';
		}
		if (temp->data == '+' && x == '+') {
			pop();
			return '+';
		}
		if (temp->data == '+' && x == '-') {
			pop();
			return '-';
		}
		if (temp->data == '-' && x == '+') {
			pop();
			return '+';
		}
		if (temp->data == '-' && x == '-') {
			pop();
			return '+';
		}
	}
	char calculate(char x) {
		node1* temp = top1;
		char data = pop();
		while (data != '(') {
			data = pop();
		}
		delete top1;
		if (curr1 == NULL) {
			symbol = NULL;
			top1 = NULL;
			return 0;
		}
		else {
			top1 = curr1;
			symbol = top1;
			curr1 = curr1->next;
		}
		return 0;
	}
	char pop() {
		if (top1 != NULL) {
			if (top1->data != ')' && top1->data != '(') {
				cout << top1->data;
			}
		}
		if (top1->next == NULL) {
			delete top1;
			top1 = NULL;
			curr1 = NULL;
			symbol = NULL;
			return 0;
		}
		char data;
		
		delete top1;
		top1 = curr1;
		if (curr1 == NULL) {
			return 0;
		}
		else {
			curr1 = curr1->next;
		}
		return top1->data;
	}
	void Display() {
		link* temp = top2;
		cout << endl;
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->next;
		}
	}
	void Display_number() {
		node* temp1 = top;
		cout << endl;
		while (temp1 != NULL) {
			cout << temp1->data << " ";
			temp1 = temp1->next;
		}
	}
};
int main()
{
	string pre = "(6+2)*5-8/4";
	Stack a;
	cout << "Your Data\n";
	cout << "----------\n";
	cout << pre;
	cout << endl;
	cout << "Your Data in \n";
	cout << "----------\n";
	a.push(pre);
	cout << endl;
	system("pause");
	return 0;
}
