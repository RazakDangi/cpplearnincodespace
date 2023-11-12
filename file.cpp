#include <iostream>

using namespace std;


struct Node{
  
  int val;
  Node* next;


};

Node* CreateNode(int val){
    Node* node = new Node;
    node->val = val;
    node->next = nullptr;
    return node;
}

void AppendNode (Node* head , int newVal)
{
    
    if(head == nullptr){
        head = CreateNode(newVal);
    }else{
        Node * current = head;
        while(current->next !=nullptr){
            current = current-> next;
        }    
        current->next = CreateNode(newVal);
    }
}

void showAll(Node* head){
    Node *current = head;
    while (current != nullptr)
    {
        cout<< current -> val <<endl;
        current = current ->next;
    }
    
}
int main ()
{
    Node* head = nullptr;
    head = CreateNode(1);

    int num= 0;
    cout<<" enter 5 values of int"<< endl;
    
    while(num < 5){
    int val;
    cin>>val;
    AppendNode(head, val);
    num++;
    }
    showAll(head);

    return 0;
}