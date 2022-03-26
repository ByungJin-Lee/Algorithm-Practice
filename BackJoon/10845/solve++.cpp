#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node{
private:
    int value;
    Node *after;
public:
    Node(int value);
    Node* Next();
    void SetNext(Node* next);
    int Value();
};
Node::Node(int value){ this->value = value; }
Node* Node::Next(){ return after; }
void Node::SetNext(Node* next){ this->after = next; }
int Node::Value(){ return value; }

class Queue{
private:
    Node *head, *tail;
    int size = 0;
public:
    int Size();
    int Front();
    int Back();
    void Push(int value);
    int Pop();
    bool Empty();
};
int Queue::Size() { return size; }
int Queue::Front() { return Empty() ? -1 : head->Value(); }
int Queue::Back(){ return Empty() ? -1 : tail->Value(); }
bool Queue::Empty(){ return size == 0; }
void Queue::Push(int value){
    Node* nNode = new Node(value);
    if(Empty()){
        head = tail = nNode;
    }else{
        tail->SetNext(nNode);
        tail = nNode;
    }
    size++;
}
int Queue::Pop(){
    if(Empty()) return -1;
    size--;
    int value = head->Value();
    Node* temp = head->Next();
    delete head;
    head = temp;
    return value;
}

void push(Queue& que){
    int val;
    cin >> val;
    que.Push(val);
}
void pop(Queue& que){ cout << que.Pop() << '\n'; }
void size(Queue& que){ cout << que.Size() << '\n'; }
void empty(Queue& que){ cout << que.Empty() << '\n'; }
void front(Queue& que){ cout << que.Front() << '\n'; }
void back(Queue& que){ cout << que.Back() << '\n'; }

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int NumOfCmd;
    
    map<string, void (*)(Queue&)> cmd_map;
    Queue q;
    
    cin >> NumOfCmd;
    
    string commands[] = {"push", "pop", "size", "empty", "front", "back"};
    void (*cmd_handler[])(Queue&) = {push, pop, size, empty, front, back};
    for(int i = 0; i < 6; i++) cmd_map.insert({commands[i], cmd_handler[i]});
    
    string cmd;
    while(NumOfCmd-- != 0) {
        cin >> cmd;
        cmd_map.find(cmd)->second(q);
    }
    
    
    return 0;
}
