#include<iostream>
#include<vector>
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
    node(int data)
    {
        this->data=data;
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
    void append(int a)
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
    void update(int a)
    {
        curr=curr->next;
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
        // else if(curr->chance==true)
        // {
        //     curr->chance=false;
        //     curr=curr->next;
        // }
        // else 
        // {
        //     curr->data=a;
        // }
        if(flag!=1)
        {
        while(curr->chance==true)
        {
            curr->chance=false;
            curr=curr->next;
        }
        curr->data=a;
        curr->chance=false;
        curr=curr->next;
        }
        
    }
    bool search(int val){
        node* temp=head;
        while(temp!=NULL){
            if(temp->data==val){
                return true;
            }
            temp=temp->next;
        }
        return false;
        }
};
class SCD{
public:
    SCD();
    bool executeSCD(vector<int>, int);
    void setFrames(int);
    int getHits();
    int getFaults();
private:
    int frames,hits,faults;
    // int hits;
    // int

};
SCD::SCD(){
    this->frames=3;//default
    hits=0;
    faults=0;
}
void SCD::setFrames(int frames){
    this->frames=frames;
}
int SCD::getHits(){
    return hits;
}
int SCD::getFaults(){
    return faults;
}

bool SCD::executeSCD(vector<int>proc, int frames){
    list exec(frames);
    
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(exec.search(currProc)){
            // exec.deleteSpecific(currProc);
            //exec.foundLRU(currProc);
            // exec.deleteSpecific(currProc);
            // exec.append(currProc);
            exec.update(currProc);
            hits++;
            cout<<i<<" Proc: "<<currProc<<" Hits: "<<hits<<endl;
        }
        else{
            //exec.append(currProc);
            //exec.search_v(proc,i,currProc);	//this will search for future pages and then order the list according to that.
            exec.update(currProc);
            faults++;
            cout<<i<<" Proc: "<<currProc<<" Fault: "<<faults<<endl;
        }
    }
}


int main()
{
    vector<int> proc={2, 5, 10, 1, 2 ,2 ,6, 9 ,1 ,2 ,10, 2, 6, 1, 2, 1 ,6 ,9, 5, 1};
    //list l(3);
    SCD test;
    test.executeSCD(proc,3);


}