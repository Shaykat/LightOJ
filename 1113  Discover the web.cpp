#include<bits/stdc++.h>
using namespace std;

stack<string>Forward;
stack<string>Backward;
string currentpage,command,url;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        while(1){
            currentpage = "#";
            cin >> command;
            if(command == "QUIT"){
                break;
            }
            else  if(command == "VISIT"){
                cin >> url;
                if(currentpage != "#"){
                    Backward.push(currentpage);
                    currentpage  = url;
                    cout << "else" << endl;
                    cout << currentpage << endl;
                }
                else{
                    currentpage = url;
                    cout << currentpage << endl;
                }

            }
            else if(command == "BACK"){
                if(Backward.empty()){
                    cout << "Ignored" << endl;
                }
                else {
                    Forward.push(currentpage);
                    cout << Backward.top() << endl;
                    currentpage = Backward.top();
                    Backward.pop();
                }

            }
            else if(command == "FORWARD"){
                if(Forward.empty()){
                    cout << "Ignored" << endl;
                }
                else {
                    Backward.push(currentpage);
                    cout << Forward.top() << endl;
                    currentpage = Forward.top();
                    Forward.pop();
                }
            }
        }
        //cout << Backward.top() << endl;
    }
    return 0;
}
