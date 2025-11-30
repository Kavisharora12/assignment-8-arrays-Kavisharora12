#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int>p;
    p.push(10);
    p.push(5);
    p.push(20);
    cout<<"Top of priority queue: "<<p.top()<<endl;
    p.pop();
    cout<<"Top of Priority Queue: "<<p.top()<<endl;
    return 0;

};

