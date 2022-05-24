#include <iostream>
#include <string>
#include <stack>
#include <list>
using namespace std;
int main(){
    stack<string> inputs;
    while (!cin.eof()) {
        string temp;
        cin >> temp;
        if (temp == "")
            break;
        inputs.push(temp);
    }
    string element;
    int operation1;
    int operation2;
    int result;
    stack<int> operations;
    list<string> prints;
    bool firstTime = true;
    while (!inputs.empty()) {
        element=inputs.top();
        inputs.pop();
        if (element!="+" && element!="-" && element!="*" && element!="/")
            operations.push(stoi(element));
        else {
            if (operations.size()>=2) {
                operation1 = operations.top();
                operations.pop();
                operation2 = operations.top();
                operations.pop();
            }
            else {
                cout<<"ERROR";
                return 0;
            }
            if (element=="+")
                result = operation1 + operation2;
            else if (element=="-")
                result = operation1 - operation2;
            else if (element=="*")
                result = operation1 * operation2;
            else if (operation2!=0)
                result = operation1 / operation2;
            else {
                cout<<"ERROR";
                return 0;
            }
            if (!inputs.empty() && (element=="+" || element=="-"))
                prints.push_front("(");
            if (firstTime) {
                prints.push_back(to_string(operation1));
                firstTime = false;
            }
            prints.push_back(element);
            prints.push_back(to_string(operation2));
            if (!inputs.empty() && (element=="+" || element=="-"))
                prints.push_back(")");
            operations.push(result);
        }
    }
    if (inputs.size()==0 && operations.size()==1){
        while(!prints.empty()) {
            cout<<prints.front();
            prints.pop_front();
        }
        cout<<"="<<operations.top();
    }
    else
        cout<<"ERROR";
    return 0;
}