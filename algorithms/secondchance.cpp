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
  // node *tail;
    int len;
    int frames;
    list(int frames)
    {
    	head=NULL;
		//tail=NULL;
        this->frames=frames;
        len=0;
    }
    void *append(int a)
    {
        node* temp= new node(a);
		if(head==NULL)
        {
			head=temp;
			//tail=temp;
            curr=head;
            head->next=head;
            len++;
		}
		else
        {
            if(len==frames)
            {
                   update(a);    
            }
			else
            {
				len++;
			}
			node*temp1=head;
            while(temp1->next!=head)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->next=head;
            curr=temp;

		}
	}
    void *update(int a)
    {
        int flag=0;
        node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            if(temp->data==a)
            {
                temp->chance=true;
                flag=1;
            }
        }
        if(flag==1)
        {

        }
        // else if(curr->chance==true)
        // {
        //     curr->chance=false;
        //     curr=curr->next;
        // }
        // else 
        // {
        //     curr->data=a;
        // }
        while(curr->chance==true)
        {
            curr->chance=false;
            curr=curr->next;
        }
        curr->data=a;
        curr=curr->next;

        
    }
    
};
int main()
{

}