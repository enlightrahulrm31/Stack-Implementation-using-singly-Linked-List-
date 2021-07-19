#include<bits/stdc++.h>
using namespace std;
struct Node{   // creating node data structure
    int data;
    Node *next;
};
class Stack{
    Node *head = NULL;
    Node *prev = NULL;
    int cnt ;

public:
    Stack(){
    	head = new Node;
    	prev = new Node;
    	cnt = 0;
    }
    void pop();
    void push(int num);
    void top();
    void display();

};

void Stack::push(int num){
    cnt++;
    if(cnt==1){
        head -> data = num;
        head -> next = NULL;
        prev =head;
        cout<<"element pushed successfully\n";
        return ;
    }
    else{
    Node *cur = new Node;
    cur->data = num;
    cur->next = NULL;
    prev->next =cur;
    prev = cur;
    cout<<"element pushed successfully\n";
    return ;
    }
}

void Stack :: pop(){
    if(cnt == 1){
    	cnt--;
    }
    else if(cnt == 0){
        cout<<"Stack is already empty \n";
    }
    else{
    int secondlast = 0;
    Node *itr = head;
    while(itr!=NULL){
        secondlast ++ ;
        if(secondlast == cnt-1){
            itr->next= NULL;
            prev = itr;
            break;
        }
        itr = itr -> next;
    }
    cnt -=1;
    cout<<"Element Popped out successfully \n";
    }
}

void Stack:: top(){
    if(cnt==0){
        cout<<"The Stack is Already empty \n";
    }
    else{
        cout<<"The top element is : "<< prev->data<< "\n";
    }
}
void Stack::display(){
	if(cnt==0){
		cout<<"The stack is empty\n";
	}
	else{
        cout<<"The elements of stack are :";
	Node *itr = head ;
	while(itr!=NULL){
		cout<<itr->data<<" ";
		itr = itr->next;
	}
	cout<<"\n";

	}

}
int main(){

    Stack s;
    while(true){
        cout<<"       CHOOSE FROM THE FOLLOWING  \n";
        cout<<"1> Push element into stack"<<"\n";
        cout<<"2> Pop element into stack"<<"\n";
        cout<<"3> Get top element of stack"<<"\n";
        cout<<"4> Display elements into stack"<<"\n";
        cout<<"5> Exit"<<"\n";
        int choice ;
        cin>>choice ;
        switch(choice){
        case 1:
            cout<<"Enter the number: ";
            int num;
            cin>> num;
            s.push(num);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            s.display();
            break;
        case 5:
            return 0;
        }
    }
}
