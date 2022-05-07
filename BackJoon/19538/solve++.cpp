#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef struct {int hour, sec;} Time;

inline bool IsBeforeOrSame(Time& target, Time& standard){
    if(target.hour == standard.hour) return target.sec <= standard.sec;
    return target.hour < standard.hour;
}

inline bool IsBetweenOrSame(Time& lhs, Time& target, Time& rhs){
    return IsBeforeOrSame(target, rhs) && IsBeforeOrSame(lhs, target);
}

inline Time ParseTime(string& time){
    return {
        stoi(time.substr(0,2)),
        stoi(time.substr(3,2))
    };
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string stime, nick;
    
    set<string> users;
    int count = 0;
    
    Time start, end, send, time;

    //Start - End - SEnd time
    cin >> stime; start = ParseTime(stime);
    cin >> stime; end = ParseTime(stime);
    cin >> stime; send = ParseTime(stime);
    
    while(true){
        cin >> stime >> nick;
        if(cin.eof() == true) break;
        
        time = ParseTime(stime);
        
        //Check Time
        if(IsBeforeOrSame(time, start)){
            users.insert(nick);
        }
        if(IsBetweenOrSame(end, time, send)){
            if(users.find(nick) != users.end()){
                count++;
                users.erase(nick);
            }
        }
    }
    
    cout << count;

    return 0;
}
