#include <iostream>

using namespace std;

template <typename T>
class Node{
  public:
  T val;
  Node<T>* next;


};
template <typename T>
Node<T>* CreateNode(T val){
    Node<T>* node = new Node<T>;
    node->val = val;
    node->next = nullptr;
    return node;
}

template <typename T>
void AppendNode (Node<T>*  &head , T newVal)
{
    if(head == nullptr){
        head = CreateNode(newVal);
    }else{
        Node<T> * current = head;
        while(current->next !=nullptr){
            current = current-> next;
        }    
        current->next = CreateNode(newVal);
    }
}
template <typename T>
void showAll(Node<T>* head){
    Node<T> *current = head;
    while (current->next != head)
    {
        cout<< current -> val <<endl;
        current = current ->next;
    }
    cout<< current -> val <<endl;
}

int main ()
{
   /*Node<int>* head = nullptr;
    //head = CreateNode(1);

    int num= 0;
    cout<<" enter 5 values of int"<< endl;
    
    while(num < 5){
    int val;
    cin>>val;
    AppendNode(head, val);
    num++;
    }
    Node<int>* current = head;
    while(current->next != nullptr){
        //cout<< current->val<<endl;
        current = current->next;
    }

    // 1 2 3 4 5
    
    current->next = head;

    showAll(head);
*/

    Node<string>* strhead = nullptr;
    //head = CreateNode(1);

    int num= 0;
    cout<<" enter 5 values of int"<< endl;
    
    while(num < 5){
    string val;
    cin>>val;
    AppendNode(strhead, val);
    num++;
    }
    Node<string>* currentstr = strhead;
    while(currentstr->next != nullptr){
        //cout<< current->val<<endl;
        currentstr = currentstr->next;
    }

    // 1 2 3 4 5
    
    currentstr->next = strhead;

    showAll(strhead);

    return 0;
}