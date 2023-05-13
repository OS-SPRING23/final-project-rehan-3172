#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    bool chance;
    node *next;
    //int c;
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
       // c=0;

    }

};
class list
{
    public:
   node *head;
   node *curr;
   int c;
  // node *tail;
    int len;
    int frames;
    list(int frames)
    {
    	head=NULL;
        curr=NULL;
		//tail=NULL;
        this->frames=frames;
        len=0;
        c=0;
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
            //cout<<curr->data<<endl;
		}
		else if(len==frames)
        {
            update(a);
        }
		else
        {
				len++;
			node*temp1=head;
            while(temp1->next!=head)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->next=head;
            curr=temp;
		}
            //cout<<curr->data<<endl;
	}
	
    void update(int a)
    {
        if(c==0)
        {
        curr=curr->next;
            c=1;
        }
        int flag=0;
        node *temp=head;
        // while(temp->next!=head)
        do
        {
            if(temp->data==a)
            {
                temp->chance=true;
                flag=1;
                break;
            }
            temp=temp->next;
        }while(temp!=head);
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
        curr=curr->next;
        //curr->chance=false;
        }

        cout<<curr->data<<endl;
        
    }
    bool search(int val){
        node* temp=head;
        if(head==NULL){
            return false;
        }
        do{
            // cout<<temp->data<<"|";
            if(temp->data==val){
                return true;
            }
            temp=temp->next;
        }while(temp!=head);
        return false;
    }
    void print(){
        node* temp=head;
        cout<<"{";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while (temp!=head);
        cout<<"}\n";
        temp=head;
        cout<<"{";
        do
        {
            cout<<temp->chance<<" ";
            temp=temp->next;
        } while (temp!=head);
        cout<<"}\n";
        
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
    this->frames=frames;
    list exec(frames);
    
    for(int i=0;i<proc.size();i++){
        int currProc=proc[i];
        if(exec.search(currProc)){
            // exec.deleteSpecific(currProc);
            //exec.foundLRU(currProc);
            // exec.deleteSpecific(currProc);
            exec.append(currProc);
           // exec.update(currProc);
            hits++;
            cout<<i+1<<" Proc: "<<currProc<<" Hits: "<<hits<<endl;
        }
        else{
            // cout<<i;
            exec.append(currProc);
            //exec.search_v(proc,i,currProc);	//this will search for future pages and then order the list according to that.
           // exec.update(currProc);
            faults++;
            cout<<i+1<<" Proc: "<<currProc<<" Fault: "<<faults<<endl;
        }
        exec.print();
    }
}


int main()
{
    vector<int> proc={2, 5, 10, 1, 2 ,2 ,6, 9 ,1 ,2 ,10, 2, 6, 1, 2, 1 ,6 ,9, 5, 1};
    //vector<int> p1={2 ,5 ,10, 1 ,2 ,2, 6, 9, 1,2, 10, 2, 6, 1 ,2 ,1, 6 ,9 ,5 ,1};
   vector<int> p={3, 2, 1, 4, 2, 1, 7, 6, 2, 1, 2, 3, 6, 5, 1, 2, 3, 6, 4, 2};
    //list l(3);
    SCD test;
    test.executeSCD(p,3);
    cout<<"\nFaults: "<<test.getFaults();
    cout<<"Hits: "<<test.getHits();
}