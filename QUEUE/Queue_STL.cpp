#include<iostream>
#include<queue>
using namespace std;

int main(){
    //Standard STL library of the queue
    queue<int> q;

    cout<<"Check if empty :"<<endl;
    if(q.empty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is Not Empty"<<endl;
    }
    //size
    cout<<"Before insert the size of the queue is : "<<q.size()<<endl;
    //Enqueue - insert operation
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<"After insert the size of the queue is : "<<q.size()<<endl;

    //Dequeue - Delete Operation
    q.pop();

    cout<<"After Delete the size of the queue is : "<<q.size()<<endl;

    cout<<"Front of queue is : "<<q.front()<<endl;

    cout<<"Back of the Queue is :"<<q.back()<<endl;
    q.
    return 0;
}
