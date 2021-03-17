#include<iostream>
#include<list>
using namespace std;

//Forward Iterator
//Forward iterators are considered to be the combination of input as well as output iterators.
//It provides support to the functionality of both of them. It permits values to be both accessed and modified.
//Forward iterators are used to read the contents from the beginning to the end of a container.
//Forward iterator use only increments operator (++) to move through all the elements of a container. ...
//A Forward iterator is a multi-pass iterator.

template<class ForwardIterator , class T>           //Freedom from different types of containers
ForwardIterator Search(ForwardIterator Start , ForwardIterator End , T key)
{
    while(Start!=End)
    {
        if( (*Start)==key )
            return Start;
        Start++;
    }
    return End;
}


//std::replace: As we know this algorithm is used to replace all the elements in the range which are equal
//to a particular value by a new value. So, let us look at its internal working (Don’t go into detail just
//look where forward iterators can be used and where they cannot be):
// Definition of std::replace()
/*template void replace(ForwardIterator first, ForwardIterator last,
                      const T& old_value, const T& new_value)
{
    while (first != last) {
        if (*first == old_value) // L1
            *first = new_value; // L2
        ++first;
    }
} */

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(2);

    auto it = Search(l.begin() , l.end() , 5);              //it here is list<int>::iterator . similarily can be of anything else
    if(it == l.end())
        cout<<"\nNot found";
    else
        cout<<*it<<" found";

return 0;
}
