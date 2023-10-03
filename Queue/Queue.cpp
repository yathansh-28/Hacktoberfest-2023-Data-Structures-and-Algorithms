#include<iostream>
using namespace std;
const int quesize = 10000;
class Queue
{
public:
    int frnt, rear;
    int que[quesize];
    Queue()
    {
        frnt = -1;
        rear = -1;
    }
};
class Queue q;
void enqueue(int a)
{
    if(q.rear == quesize-1)
        cout<<"Queue is full"<<endl;
    else
    {
        if(q.rear == -1 && q.frnt == -1)
        {
            q.rear = q.rear + 1;
            q.frnt = q.frnt + 1;
            q.que[q.rear] = a;
        }
        else
        {
            q.rear++;
            q.que[q.rear] = a;
        }
    }
}
void dequeue()
{
    if(q.frnt == -1 && q.rear == -1)
        cout<<"Queue is empty"<<endl;
    else
    {
        if(q.frnt == q.rear)
        {
            q.frnt = -1;
            q.rear = -1;
        }
        else
        {
            q.frnt++;
        }
    }
}
void searchVal(int a)
{
    int i;
    if(q.rear != -1 && q.frnt !=-1)
    {
        for(i=q.frnt;i<=q.rear;i++)
            if(q.que[i] == a)
            {
                cout<<"Value is present at "<<(i+1)-q.frnt<<endl;
                break;
            }
        if(i == q.rear+1)
            cout<<"Value Not present"<<endl;
    }
    else
        cout<<"Queue is empty"<<endl;
}
void display()
{
    if(q.rear != -1 && q.frnt !=-1)
    {
        for(int i=q.frnt;i<=q.rear;i++)
            cout<<q.que[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"Queue is empty"<<endl;
}
int main()
{
    int ch, a;
    do
    {
        cout<<"Enter: \n 1 - To enqueue \n 2 - To dequeue \n 3 - To view the queue \n 4 - To Search a value \n 5 - To exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter a element:";
            cin>>a;
            enqueue(a);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Enter a number to search:";
            cin>>a;
            searchVal(a);
            break;
        case 5:
            break;
        default:
            cout<<"INVALID CHOICE"<<endl;;
        }
    }while(ch!=5);
    return 0;
}
