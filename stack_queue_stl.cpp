#include <bits/stdc++.h>
using namespace std;
int main(){
    queue <int>queue;
    stack <int>stack;
    int a;
    stack.push(4);
    stack.push(5);
    a=stack.top();
    cout<<a<<endl;
    stack.pop();
    a=stack.top();
    cout<<a<<endl;
    stack.pop();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    a=queue.front();
    cout<<a<<endl;
    queue.pop();
    a=queue.front();
    cout<<a<<endl;
    queue.pop();
    return 0;
}