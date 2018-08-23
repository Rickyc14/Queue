#include <iostream>
#include <list>
#include <queue> ///queue class
#include <deque>
using namespace std;
queue<int> q;
int main()
{
    int x,z=0;
    char op;
    cout << "// creating a QUEUE using C++'s __queue class__ //\n\n";
    cout << "|| enter ' -1 ' to quit program\n\n";
    do{
    do{
        cout <<q.size() + 1 << " - ";
        cin >> x;
        if(x != -1){
            q.push(x);
            z++;
        }
    }while(x != -1 );
    cout<<"\n[QUEUE DATA]\n"<<endl;
    while(!q.empty()){
        cout<<q.front()<<"\t";
        q.pop();
    }
    cout<<"\n\n|| queue size = "<<z<<endl;
    cout<<"|| queue reseted "<<endl;
    z=0;
    cout<<"|| go again?"<<endl;
    cout<<"|| y - yes // n - no"<<endl;
    cin>>op;
    }
    while(op == 'y' );
}
