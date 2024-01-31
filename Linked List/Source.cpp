#include<iostream>
#include<conio.h>
using namespace std;


class node
{
	int data;
	node* nextnode;
public:
	node()
	{
		data = 0;
		nextnode = NULL;
	}
	void set_data(int s)
	{
		data = s;
	}
	int get_data()
	{
		return data;
	}
	void set_nextnode(node* gh)
	{
		nextnode = gh;
	}
	node* get_nextnode()
	{
		return nextnode;
	}
};


class LinkedList
{
	node* head;
	string name;
	int size;
	node* current;
	node* previous;
	node* newnode;
public:
	LinkedList()
	{
		head = NULL;
		size = 0;
		name = "My List";
	}
	void set_name(string a)
	{
		name = a;
	}
	string get_name()
	{
		return name;
	}

	void insert_at_end(int data)
	{
		newnode = new node();
		newnode->set_data(data);
		newnode->set_nextnode(NULL);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			current = head;
			while (current->get_nextnode() != NULL)
			{
				current = current->get_nextnode();
			}
			current->set_nextnode(newnode);
		}
		size++;

	}

	void delete_at_end()
	{
		if (head == NULL)
		{
			cout << "list is empty";
		}
		else
		{
			current = head;
			previous = head;
			while (current->get_nextnode() != NULL)
			{
				previous = current;
				current = current->get_nextnode();
			}
			previous->set_nextnode(NULL);
			delete current;
			size--;
		}


	}
	void insert_at_start(int data)
	{
		newnode = new node();
		newnode->set_data(data);
		newnode->set_nextnode(NULL);

		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->set_nextnode(head);
			head = newnode;
		}
		size++;
		
	}

	void delete_at_start()
	{

		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			current = head;
			head = head->get_nextnode();
			delete current;
			size--;
			
		}
	}

	void insert_at_specific_location(int d, int loc)
	{
		newnode = new node();
		newnode->set_data(d);
		if ((head == NULL) && (loc == 1))
		{
			head = newnode;
			newnode->set_nextnode(NULL);
			size++;
		}
		else if ((loc <= size) && (loc > 0))
		{
			if (loc == 1)
			{
				newnode->set_nextnode(head);
				head = newnode;
				size++;
			}
			else
			{
				current = head;
				previous = head;
				for (int i = 1; i < loc; i++)
				{
					previous = current;
					current = current->get_nextnode();
				}
				previous->set_nextnode(newnode);
				newnode->set_nextnode(current);
				size++;
			}
		}
	}


	void delete_at_specific_location(int loc)
	{
		if ((head == NULL) && (loc == 1))
		{

			cout << "List is empty " << endl;
		}
		else if ((loc <= size) && (loc > 0))
		{
			if (loc == 1)
			{
				current = head;
				head = head->get_nextnode();
				delete current;
				size--;
			}
			else
			{
				current = head;
				previous = head;
				for (int i = 1; i < loc; i++)
				{
					previous = current;
					current = current->get_nextnode();
				}
				previous->set_nextnode(current->get_nextnode());
				delete current;
				size--;
			}
		}

	}


	void display()
	{

		if (head == NULL)
			cout<<"list is empty "<<endl;
		else
		{
		
			current = head;
			while (current->get_nextnode() != NULL)
			{
				cout<<current->get_data()<<" " ;
				current = current->get_nextnode();
			}

			cout<<current->get_data();
		}

	}


	void display_style()
	{
		cout << "\t\t\t\t\t\t *************** " << endl;
		cout << " \t\t\t\t\t\t   Linked list    \t\t\t" << endl;
		cout << "\t\t\t\t\t\t *************** " << endl;
		cout << "\t\tList name :  " << name << "\t\t\t\t\t\t   size:   " << size << endl;
		cout << "\t\t\t\t\t\t ";
		display();
		cout << "\n\n\n";
	}



};

int main()
{
	LinkedList* ptr = NULL;
	int ch = 0;
	int j = 0;
	int k;
	int fg = 0;
	int loc;
	bool a = 0;
	int y = 1, p = 1;
	string kl;
	while (ch != 5)
	{
		system("cls");
		do
		{
			cout<<"\t\t\t\t\t\t***************" << endl;
			cout<<"\t\t\t\t\t\t LINKED LIST MENU" << endl;
			cout<<"\t\t\t\t\t\t***************" << endl;
			cout<<"\n\n-> ";
			cout<<"\t\t\t\t\t1.Creation of the list" << endl;
			cout<<"\n\t\t\t\t\t2.Insertion" << endl;
			cout<<"\n\t\t\t\t\t3.Deletion" << endl;
			cout<<"\n\t\t\t\t\t4.Display the list" << endl;
			cout<<"\n\t\t\t\t\t5.Exit" << endl;
			cout<<"\n\t\t\t\t\tEnter your choice ..... ";
			cin>>ch;
			if (ch == 1 || ch == 5)
				a = 1;
			if (a == 0)
			{
				cout<<"\n\t\t\t\t\tCreate the list first" << endl;
				system("pause");
				system("cls");
			}
		} while (a == 0);
		switch (ch)
		{
		case 1:
			ptr = new LinkedList();
			cout<<"\n\t\t\t\t\tEnter the name of the list :";
			cin>>kl;
			ptr->set_name(kl);
			cout<<"\n\t\t\t\t\tList is created successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			j = 0;
			while (y != 0)
			{
				system("cls ");
				ptr->display_style();
				cout<<"\t\t\t\t\t1.Insert at start" << endl;

				cout<<"\n\t\t\t\t\t2.Insert at end" << endl;
				cout<<"\n\t\t\t\t\t3.Insert at specific location " << endl;
				cout<<"\n\t\t\t\t\t4.Back to main menu" << endl;
				cout<<"\n\t\t\t\t\t5.Exit" << endl;
				cout<<"\n\t\t\t\t\t Enter your choice ...";
				cin>>j;
				if (j == 5 || j == 4)
					y = 0;
				switch (j)
				{
				case 1:
					cout <<"\t\t\t\t\tEnter the value :";
					cin>>k;
					ptr->insert_at_start(k);
					break;
				case 2:
					cout <<"\t\t\t\t\tEnter the value :";
					cin>>k;
					ptr->insert_at_end(k);
					break;
				case 3:
					cout <<"\t\t\t\t\tEnter the value :";
					cin>>k;
					cout<<"\t\t\t\t\tEnter at specific location :";
					cin>>loc;
					ptr->insert_at_specific_location(k, loc);
					break;
				case 4:
					break;
				case 5:
					ch = 5;
					break;
				};
			}
			break;
		case 3:
			fg = 0;
			while (p != 0)
			{
				system("cls");
				ptr->display_style();
				cout<<"\t\t\t\t\t1.Delete at start" << endl;
				cout<<"\n\t\t\t\t\t2.Delete at end" << endl;
				cout<<"\n\t\t\t\t\t3.Delete at specific location" << endl;
				cout<<"\n\t\t\t\t\t4.Back to main menu" << endl;
				cout<<"\n\t\t\t\t\t5.Exit-> " << endl;
				cout<<"\n\t\t\t\t\t Enter your choice ...";
				cin>>fg;
				if (fg == 4 || fg == 5)
					p = 0;
				switch (fg)
				{
				case 1:

					ptr->delete_at_start();
					break;
				case 2:
					ptr->delete_at_end();
					break;
				case 3:
					cout <<"\t\t\t\t\tEnter the specific loaction :";
					cin>>loc;
					ptr->delete_at_specific_location(loc);
					break;
				case 4:
					break;
				case 5:
					ch = 5;
					break;
				};
			}
			break;
		case 4:
			cout<<"\t\t\t\t\t ";
			ptr->display();
			cout<<"\n";
			system("pause");
			break;
		case 5:
			ch = 5;
			break;
		};
	}
	system("pause");
	return 0;



	
}