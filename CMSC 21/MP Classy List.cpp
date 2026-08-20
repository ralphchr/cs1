/*This MP is re-implements the doubly-linked list using a class.

The input consists of a number of lines. The first line of input is the number of test cases, followed by the test cases.  Each test case consists of a series of numbers. The first number identifies the number of sub-cases. Each sub-case will work on its own list.  Each sub-case has a number of operations that has to be performed. This is then followed by the operations: 1 for push_back, 2 for push_front, 3 for insert, 4 for erase, 5 for getItem, 6 for setItem, and 7 for search item.  The type of operation tells you how many inputs are to follow for that test case. For push_back and push_front, just the item to be inserted. For insert, 2 additional items follow, an item and a position (item is inserted in that position). When the list becomes full (we will store 10 items maximum), we print "LIST IS FULL."  For remove and getItem, a position follows. Like the insert, setItem will have 2 additional inputs, an item and a position. For search item, just the item. Print the position where the item is found, print "ITEM NOT FOUND" otherwise.

For the getItem operation simply display the item but if the position is not valid print "OPERATION FAILED". For the other operations (all others except for getItem and search item), display the contents of the list.

For this MP, we should also free the memory allocated for all the lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class node{
public:
   int item;
   node *next, *prev;
};

class list{
public:
    int size;
	node *head, *tail;
	list();
	~list();
	int push_back(int);
	int push_front(int);
	int insert(int,int);
	int erase(int);
	int getItem(int);
	int setItem(int, int);
	int search(int);
	void display();
};

int main(){
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++){
        int subcases;
        cin >> subcases;
        for (int subcase = 0; subcase < subcases; subcase++){
            list l;
            int nums;
            cin >> nums;
            for (int num = 0; num < nums; num++){
                int opType, item, pos, check;
                cin >> opType;
                if (opType == 1){
                    cin >> item;
                    check = l.push_back(item);
                    l.display();
                    if (!check)
                        cout << "LIST IS FULL\n";
                }
                else if (opType == 2){
                    cin >> item;
                    check = l.push_front(item);
                    l.display();
                    if (!check)
                        cout << "LIST IS FULL\n";
                }
                else if (opType == 3){
                    cin >> item >> pos;
                    check = l.insert(item, pos);
                    l.display();
                    if (!check)
                        cout << "LIST IS FULL\n";
                }
                else if (opType == 4){
                    cin >> pos;
                    l.erase(pos);
                    l.display();
                }
                else if (opType == 5){
                    cin >> pos;
                    check = l.getItem(pos);
                    if (check == -99999)
                        cout << "OPERATION FAILED\n";
                    else
                        cout << check << endl;
                }
                else if (opType == 6){
                    cin >> item >> pos;
                    check = l.setItem(item, pos);
                    l.display();
                }
                else if (opType == 7){
                    cin >> item;
                    check = l.search(item);
                    if(check == -1)
                        printf("ITEM NOT FOUND\n");
                    else {
                        printf("%d\n", check);
                    }
                }

            }
        }
    }
    return 0;
}

list::list(){
	size = 0;
	head = tail = NULL;
}

list::~list(){
    //cout<<"object is being destroyed!"<<endl;
	while (size > 0)
		erase(0);
}

int list::push_back(int x){
	node *n = new node();

	if(n==NULL)
		return 0;

	if(size == 10)
	    return 0;

	n->item = x;
	n->next = n->prev = NULL;

	if(head == NULL){
		head = tail = n;
	}
	else{
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
	size++;
	return 1;
}

int list::push_front(int x){
    node *n = new node();

    if(n == NULL)
		return 0;

	if(size == 10)
	    return 0;


	n->item = x;
	n->prev = NULL;
	n->next = NULL;

    if(head == NULL){
		head = tail = n;
	} else {
	    n->next = head;
	    head->prev = n;
	    head = n;
	}
	size++;
	return 1;
}

int list::insert(int x, int pos){

	if(size == 10)
		return 0;
	if (pos<0 || pos > size){
	    return 1;
	}else{
		node *n = new node();
		if(n == NULL)
			return 0;
		n->next = n->prev = NULL;
		n->item = x;
		if(head==NULL)
			head = tail = n;
		else{
			if(pos==0){
				push_front(x);
				return 1;
			} else {
    			node *tmp = head;
    			int ctr = 0;
    			while(ctr < pos-1){
    				tmp = tmp->next;
    				ctr++;
    			}

    			n->next = tmp->next;
    			n->prev = tmp;
    			if(tmp != tail)
    				tmp->next->prev = n;
    			tmp->next = n;
    			if(pos == size)
    				tail = n;
			}
		}

		size++;
		return 1;
	}
}

int list::erase(int pos){
	if(pos<0 || pos >=size)
		return 0;
	else{
		node *del;
		if(pos==0){
			del = head;
			head = del->next;
		}
		else{
			node *tmp = head;
			int ctr = 0;
			while(ctr<pos-1){
				tmp = tmp->next;
				ctr++;
			}
			del = tmp->next;
			tmp->next = del->next;
			if(del == tail)
				tail = tmp;
		}
		size--;
		del->next = NULL;
		delete del;
		return 1;
	}

}

int list::getItem(int p){
	if (p < 0 || p >= size)
	    return -99999;
	node *tmp = head;
	for(int i=0; i<size; i++){
		if(i==p)
			return tmp->item;
		tmp = tmp->next;
	}
	return -99999;
}

int list::setItem(int x, int p){
    if (p < 0 || p >= size)
	    return 0;
    node *tmp = head;
	for(int i=0; i<size; i++){
		if(i==p){
			tmp->item = x;
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int list::search(int x){
	node *tmp = head;
	for(int i=0; i<size; i++){
		if(tmp->item == x)
			return i;
		tmp = tmp->next;
	}
	return -1;
}

void list::display(){
	node *tmp = head;
	while(tmp!=NULL){
		printf("%i ",tmp->item);
		tmp = tmp->next;
	}
	printf("\n");
}