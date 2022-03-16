#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct {int source, dest, numOfBox;} Deliver;

bool Compare(Deliver& d1, Deliver& d2){
    if(d1.dest == d2.dest) return d1.source < d2.source;
    return d1.dest < d2.dest;
}

int main(void){
    
    int NumOfTown, DeliverCapacity, NumOfDelivery;
    
    cin >> NumOfTown >> DeliverCapacity >> NumOfDelivery;
    
    vector<Deliver> delivers;
    
    Deliver deliver;
    for(int i = NumOfDelivery - 1; i >= 0; i--){
        cin >> deliver.source >> deliver.dest >> deliver.numOfBox;
        delivers.push_back(deliver);
    }
    sort(delivers.begin(), delivers.end(), Compare);
    
    int capacityTable[2001], deliverSum = 0, Mn;
    fill(capacityTable, capacityTable + 2001, DeliverCapacity);
    
    for(Deliver& d : delivers){
        Mn = min(d.numOfBox, *min_element(capacityTable + d.source, capacityTable + d.dest));
        if(Mn <= 0) continue;
        
        for(int i = d.source; i < d.dest; i++) capacityTable[i] -= Mn;
        deliverSum += Mn;
    }
    
    cout << deliverSum;
    
    return 0;
}
