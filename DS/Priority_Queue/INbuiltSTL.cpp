#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Meracomparator{
public:
    bool operator()(int a, int b)    //OPERATOR OVERLOADING      //FUNCTOR
    {
        return a>b;    //FOR MIN OR MAX
    }

};

int main()
{
    priority_queue<int,vector<int>,Meracomparator> h;
    h.push(5);
    h.push(8);
    h.push(4);
    h.push(2);
    h.push(1);
    h.push(15);

    while(!h.empty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }


    return 0;
}
