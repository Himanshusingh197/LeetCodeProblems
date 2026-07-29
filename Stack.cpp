//write a program to implement a Stack 5 elements and then remove one element from it.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int stack[5];
    int top = -1;

    // Push elements
    cout<<"Enter 5 elements to push into stack: ";
    for(int i = 0; i < 5; i++){
        cin>>stack[++top];
    }

    // pop one element
    cout<<"Pop element from stack : "<<stack[top]<<endl;

    return 0;
}

//write a program to implement a Queue 5 elements and then remove one element from it.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int queue[5];
    int front = 0, rear = -1;

    // Enqueue elements
    cout<<"Enter 5 elements to enqueue: ";
    for(int i = 0; i < 5; i++){
        cin>>queue[++rear];
    }

    // Dequeue element
    cout<<"Dequeue elements from queue : ";
        cout<<queue[front++]<<" ";

    return 0;
}