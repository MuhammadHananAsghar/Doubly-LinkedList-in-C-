
// CREATED BY MUHAMMAD HANAN ASGHAR
//  PYTHONIST
#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node *prev;
} *root;
class Doubly{
  public:
  Doubly(){
    root = NULL;
  }
  void InsertEnd(int data){
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(root == NULL){
      root = node;
      node->prev = root;
    }else{
      Node *temp = root;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = node;
      node->prev = temp;
    }
  }
  void Display(){
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp = root;
      while(temp!= NULL){
        cout<<temp->data<<" - ";
        temp = temp->next;
      }
    }
  }
  void InsertBegin(int data){
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp;
      temp = root;
      node->next = root;
      root = node;
    }
  }
  void InsertPos(int data,int key){
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp = root;
      Node *prev;
      while(temp->data != key){
        prev = temp;
        temp = temp->next;
      }
      prev->next = node;
      node->next = temp->next;
      node = prev;
    }
  }
  void DeleteEnd(){
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp = root;
      Node *prev;
      while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
      }
      delete temp->next;
      prev->next = NULL;
    }
  }
  void DeleteStart(){
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp;
      temp = root;
      root = root->next;
      delete temp;
    }
  }
  void DeletePos(int key){
    if(root == NULL){
      cout<<"No Node Present";
    }else{
      Node *temp=root;
      Node *prev;
      while(temp->data != key){
        prev = temp;
        temp = temp->next;
      }
      prev->next = temp->next;
      temp->next = prev;
    }
  }
};


int main() {
  Doubly d;
  d.InsertEnd(10);
  d.InsertEnd(20);
  d.InsertEnd(30);
  d.InsertBegin(5);
  d.InsertBegin(1);
  d.Display();
  cout<<endl;
  d.InsertPos(34, 5);
  d.Display();
  cout<<endl;
  d.DeleteEnd();
  d.Display();
  cout<<endl;
  d.DeleteStart();
  d.Display();
  cout<<endl;
  d.DeletePos(10);
  d.Display();
}
