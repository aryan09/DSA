//Priority_QUEUE  //HEAP

#include<iostream>
#include<vector>
using namespace std;

class Minheap
{

    vector<int> v;

    void heapify(int index)
    {
        int min_index=index;
        int left=2*index;
        int right=2*index+1;

        if(left<=v.size()-1 && v[left]<v[min_index])
        {
            min_index=left;
        }
        if(right<=v.size()-1 && v[right]<v[min_index])
        {
            min_index=right;
        }
        if(min_index!=index)
        {
            swap(v[index],v[min_index]);
            heapify(min_index);
        }
    }



public:
    Minheap()
    {
        v.push_back(-1);
    }

    void push(int data)
    {
        v.push_back(data);

        int index=v.size()-1;  //to calculate index of last elemnt
        int parent = index/2;

        while(parent>0 && v[parent]>v[index])
        {
            swap(v[parent],v[index]);

            index=parent;
            parent=parent/2;
        }
    }


    void pop()
    {
        int last_index=v.size()-1;
        swap(v[1],v[last_index]);
        v.pop_back();
        heapify(1);
    }


    int top()
    {
        return v[1];
    }


    bool empty()
    {
        return v.size()==1;
    }

};

void printHeap(Minheap h)
    {
        while(!h.empty())
        {
        cout<<h.top()<<endl;
        h.pop();
        }
    }

void PrintMaxK(int k)
    {
        Minheap h;
        int i=k;
        int data;
        while(1)
        {
            cin>>data;

            if(data==-1)
            {
                printHeap(h);

            }

            else
            {
                if(i>0)
                {
                h.push(data);
                i--;
                }

                else
                {
                if(data>h.top())
                    {
                    h.pop();
                    h.push(data);
                    }
                }
            }

        }
    }


//MAKE MAXHEAP
class Maxheap{



};

int main()
{
    int k;
    cout<<"Enter no. of max elements to be printed :";
    cin>>k;
    PrintMaxK(k);

//    Minheap h;
//    h.push(5);
//    h.push(8);
//    h.push(4);
//    h.push(2);
//    h.push(1);
//    h.push(15);
//
//    while(!h.empty())       //THIS IS ALSO HEAP SORT (FOR GIVING K TOP ELEMENTS )
//    {
//        cout<<h.top()<<endl;
//        h.pop();
//    }

return 0;
}
