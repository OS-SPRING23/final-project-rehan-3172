#pragma once
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(){
			data=0;
			next=NULL;
		}
		node(int a){
			data=a;
			next=NULL;
		}
};
class linkedList{
	public:
		node* head;
		node* tail;
        int len;
        int frames;
		linkedList(int frames){
			head=NULL;
			tail=NULL;
            this->frames=frames;
            len=0;
		}
		void append(int a){
			node* temp= new node(a);
			if(head==NULL){
				head=temp;
				tail=temp;
                len++;
			}
			else{
                if(len==frames){
                    deleteHead();
                }
				else{
				len++;
				}
				tail->next=temp;
				tail=temp;

			}
		}
		
		void deleteHead(){
			node* temp= new node;
			temp=head;
			head=head->next;
			delete temp;
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
		bool deleteSpecific(int val){
			node* temp=head;
			node* del;
			len--;
			if(temp->data==val){
				deleteHead();
				return true;
			}
				cout<<temp->data<<"|";
			while(temp->next!=NULL){
				if(temp->next->data==val && temp->next!=NULL){
					
					del=temp->next;
					temp->next=del->next;
					delete del; 
					return true;
				}
				temp=temp->next;
			}
			return false;
		}
		void foundLRU(int val){
			if(deleteSpecific(val)){
				append(val);
			}
		}
		
};