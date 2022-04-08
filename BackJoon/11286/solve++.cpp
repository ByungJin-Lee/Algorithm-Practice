#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Heap{
private:
    unsigned int last = 1;
    unsigned int capacity;
    int *data;
    bool(*evaluate)(int, int);
public:
    Heap(unsigned int _capacity, bool(*_evaluate)(int, int)){
        this->evaluate = _evaluate;
        this->capacity = _capacity;
        this->data = new int[_capacity + 1];
    }
    void Push(int value){
        int pos = last++;
        while (pos > 1 && evaluate(value, data[pos / 2])){
            data[pos] = data[pos / 2];
            pos = pos >> 1;
        }
        data[pos] = value;
    }
    int Pop(){
        if (last == 1) return 0;
        int res = data[1], value = data[--last];
        int parent = 1, child = 2;
        while (child < last){
            if (child + 1 < last && evaluate(data[child + 1], data[child])) child++;

            if (evaluate(value, data[child])) break;

            data[parent] = data[child];
            parent = child;
            child *= 2;
        }
        data[parent] = value;
        return res;
    }
};

bool asending(int lhs, int rhs){
    if (abs(lhs) == abs(rhs)) return lhs < rhs;
    return abs(lhs) < abs(rhs);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int V;

    cin >> N;

    Heap heap(N, asending);

    while (N-- != 0){
        cin >> V;
        if (V == 0) cout << heap.Pop() << '\n';
        else heap.Push(V);
    }

    return 0;
}
