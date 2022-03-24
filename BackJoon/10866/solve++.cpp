#include <iostream>
#include <cstring>

using namespace std;

class NodeInt{
private:
    int value;
    NodeInt* prev, *next;
public:
    NodeInt(int value);
    NodeInt* Before();
    NodeInt* After();
    void SetBefore(NodeInt* node);
    void SetAfter(NodeInt* node);
    int Get();
    void Set(int value);
};

NodeInt::NodeInt(int value){
    this->value = value;
    this->prev = this->next = NULL;
}
NodeInt* NodeInt::Before(){
    return this->prev;
}
NodeInt* NodeInt::After(){
    return this->next;
}
void NodeInt::SetBefore(NodeInt* node){
    prev = node;
}
void NodeInt::SetAfter(NodeInt* node){
    next = node;
}
void NodeInt::Set(int value){
    this->value = value;
}
int NodeInt::Get(){
    return this->value;
}

class Deck {
private:
    unsigned int length = 0;
    NodeInt *head, *tail;
public:
    Deck();
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    int front();
    int back();
};
Deck::Deck(){
    this->head = this->tail = NULL;
}
void Deck::push_front(int value){
    NodeInt* node = new NodeInt(value);
    if(empty()){
        head = tail = node;
    }else{
        node->SetAfter(head);
        head->SetBefore(node);
        head = node;
    }
    length++;
}
void Deck::push_back(int value){
    NodeInt* node = new NodeInt(value);
    if(empty()){
        head = tail = node;
    }else{
        tail->SetAfter(node);
        node->SetBefore(tail);
        tail = node;
    }
    length++;
}
int Deck::pop_front(){
    if(length == 0) return -1;
    NodeInt* next = head->After();
    int value = head->Get();
    delete head;
    head = next;
    length--;
    return value;
}
int Deck::pop_back(){
    if(length == 0) return -1;
    NodeInt* next = tail->Before();
    int value = tail->Get();
    delete tail;
    tail = next;
    length--;
    return value;
}
int Deck::size(){
    return length;
}
bool Deck::empty(){
    return length == 0;
}
int Deck::front(){
    return empty() ? -1 : head->Get();
}
int Deck::back(){
    return empty() ? -1 : tail->Get();
}

int deckWork(Deck& deck, char command[11]){
    int ret = -2, value;
    if(strcmp(command, "push_back") == 0){
        cin >> value;
        deck.push_back(value);
    }else if(strcmp(command, "push_front") == 0){
        cin >> value;
        deck.push_front(value);
    }else if(strcmp(command, "back") == 0){
        ret = deck.back();
    }else if(strcmp(command, "front") == 0){
        ret = deck.front();
    }else if(strcmp(command, "size") == 0){
        ret = deck.size();
    }else if(strcmp(command, "pop_front") == 0){
        ret = deck.pop_front();
    }else if(strcmp(command, "pop_back") == 0){
        ret = deck.pop_back();
    }else{
        ret = deck.empty();
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    
    cin >> N;
    
    Deck deck;
    
    char command[11];
    
    while(N-- != 0){
        cin >> command;
        int ret = deckWork(deck, command);
        if(ret != -2) cout << ret << '\n';
    }
    return 0;
}
