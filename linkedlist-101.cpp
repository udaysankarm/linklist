#include<iostream>
using namespace std;
class Node // each circles
{
	public:
	//data
	int data;
	//pointer to point ot next element
	Node *nxt;
	Node()
	{
		nxt=NULL;
	}
};

class LinkedList
{
	public:
	//head
	Node *head;
	Node *last;
	LinkedList()
	{
		head=NULL;
		last=NULL;
	}
	//insert
	void insert(int value)
	{
		//creating the new object
		Node *temp=new Node;
		//assinging the value to the new memory location
		temp->data=value;  
		//we need to assingn the pointing variable of last to the new object created
		//if it is the first element 
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			last->nxt=temp;
		}
		last=temp;
	}
	//display
	void display()
	{
		Node *current;//current stores the address of the current node
		current = head; //initializing current
		while(current!=NULL)// loop to swipe throughj the link list 
		{
			cout<<current->data<<" ";//printing the data in each
			current=current->nxt;//modifing the current node
		}
	}
	//insertAT
	void insertAt(int pos,int value)
	{
		Node *temp=new Node;// dynamically creating the memory for new node
		temp->data=value;//storing value in the new node
		if(pos >1)//if position is not at the first position
		{
			int i=1; //control variable
			Node *current=head;
			while(i<pos-1)//loop acessing each element
			{
				current=current->nxt;//acessing the next element
				i++;//increamenting i
			}
			temp->nxt=current->nxt;//storing the adress of (pos+1)th element in the new node
			current->nxt=temp;//storing the address of new node in (pos-1)th position
			if(temp->nxt==NULL)
			{
				last=temp;
			}
		}
		else
		{
			temp->nxt=head;
			head=temp;
		}
	}
	//delete
	void Delete()
	{
		Node *current=head; //curent acceces each node
		while(current->nxt->nxt!=NULL)//loop to search fro end of linklist
		{
			current=current->nxt;//going to the next element
		}	
		current->nxt=NULL;//making the current element the last 
		last->data=NULL; //erasing the value at the node that is to be deleted
		delete last;//delete last element
		last=current;// modifing last to the now location
	}
	void DeleteAt(int pos)
	{
		if(pos==1)
		{
			delete head;
			head=head->nxt;
		}
		else
		{
			Node *current,*temp;
			int i=1;
			current=head;
			while(i<pos-1)
			{
				current=current->nxt;
				i++;
			}
			temp=current;
			delete current->nxt;
			current->nxt=temp->nxt->nxt;
		}
	}
};
int main()
{
	LinkedList A;
	A.insert(5);
	A.insert(3);
	A.insert(4);
	A.insert(7);
	A.insertAt(5,9);
	A.insert(6);
	A.insert(11);
	A.DeleteAt(7);
	A.display();
	return 0;
}
