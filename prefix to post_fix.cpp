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
	string data = "\0";
	node1* next;
};
struct link {
	char data;
	link* next;
};
class Stack {
	string Data1;
	string result = "\0";
	node1* top1 = NULL;
	node1* curr1 = NULL;
	node1* Number = NULL;
	int count = 0;
public:
	void push(char data) {
		char in = 0;
		if ((data > 96 && data < 123) || (data == '(') || (data == ')')) {
			if (Number == NULL) {
				curr1 = Number;
				Number = new node1;
				Number->data = Number->data + data;
				Number->next = NULL;
				top1 = Number;
			}
			else {
				curr1 = top1;
				Number = new node1;
				Number->data = Number->data + data;
				top1 = Number;
				top1->next = curr1;
			}
		}
		else {
			calculate(data);
		}

	};
	char calculate(char x) {
		string res;
		node1* temp = top1;
		string data = pop();
		if (data != ")") {
			string data2 = pop();
			if (top1 == NULL) {
				curr1 = top1;
				Number = new node1;
				top1 = Number;
				temp = top1;
				top1->next = curr1;
			}
			else {
				curr1 = top1;
				Number = new node1;
				top1 = Number;
				temp = top1;
				top1->next = curr1;
			}
			temp->data = temp->data + data;
			temp->data = temp->data + data2;
			temp->data = temp->data + x;
		}
		return 0;
	}
	void Display() {
		cout << top1->data;
	}
	string pop() {
		string data;
		if (top1 != NULL) {
			data = top1->data;
		}
		if (top1->next == NULL) {
			delete top1;
			top1 = NULL;
			curr1 = NULL;
			Number = NULL;
			return data;
		}
		delete top1;
		top1 = curr1;
		if (curr1 == NULL) {
			return 0;
		}
		else {
			curr1 = curr1->next;
		}
		return data;
	}
};
int main()
{
	string data="\0";
	string pre = "*+ab-cd";
	Stack a;
	cout << "Your Data\n";
	cout << "----------\n";
	cout << pre;
	cout << endl;
	cout << "Your Data in \n";
	cout << "----------\n";
	for (int i = pre.length()-1; i >=0; i--) {
		data = data + pre[i];
	}
	for (int i = 0; i < data.length(); i++) {
		a.push(data[i]);
	}
	a.Display();
	cout << endl;
	system("pause");
	return 0;
}
