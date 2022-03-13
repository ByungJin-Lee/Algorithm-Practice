#include <iostream>
#include <unordered_set>

using namespace std;

bool IsAlright(int arr[], int N){
    int i = 0, j, top, expect;
    unordered_set<int> uset;
    //Loop until the biggest Number = N is biggest Num
    while(i < N && arr[i] <= N){
        uset.insert(arr[i]);
        //top is max number until now
        top = arr[i];
        //next number is less than top. then is must be descending!
        for(j = i + 1, expect = top - 1; j < N && arr[j] < top; j++){
            //Get expext Number
            while(uset.find(expect) != uset.end()){ expect--; }
            
            if(arr[j-1] < arr[j] || arr[j] != expect) return false;
            
            uset.insert(expect);
        }
            
        i = j;
    }
    //After The biggeset number, Descending...
    for(; i < N; i++)
        if(arr[i-1] < arr[i]) return false;
    //All pass
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int arr[100000], N, i = 0, top = 0;
    
    cin >> N;
    
    while(i < N) { cin >> arr[i++]; }
    
    //Check Stack Numbers is possible?
    if(IsAlright(arr, N)){
        i = 0;
        while(i < N && arr[i] <= N){
            if(arr[i] > top){
                for(int j = top; j < arr[i]; j++)
                    cout << "+\n";
                top = arr[i];
            }
            //Pop Current Number
            cout << "-\n";
            i++;
        }
        //After The Biggest Number then pop all number!!
        while(i < N){
            cout << "-\n";
            i++;
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}
