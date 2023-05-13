#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    bool chance;
    node *next;
    node()
    {
        data=0;
        chance=false;
        next=NULL;
    }

};
class list
{
    public:
   node *head;
   node *curr;
   node *tail;
    int len;
    int frames;
    void *append(int a)
    {
        node* temp= new node(a);
			if(head==NULL){
				head=temp;
				tail=temp;
                len++;
			}
			else{
                if(len==frames){
                   // deleteHead();
                }
				else{
				len++;
				}
				tail->next=temp;
				tail=temp;

			}
		}
    }
};
int main()
{

}