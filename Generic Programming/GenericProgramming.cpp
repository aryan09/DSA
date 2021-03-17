#include<iostream>
#include<list>
#include<cstring>
using namespace std;

//Templates     //Freedom from different data types
template<typename T>                                //typename or class can be used
int Search(T arr[] , int n , T key)
{
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]==key)
            return i;
    }
    return n;
}

//Templates + Iterators       //Freedom from different types of containers
typename<class ForwardIterator , class T>
ForwardIterator Search(ForwardIterator Start , ForwardIterator End , T key)
{
    while(Start!=End)
    {
        if(*Start == key)
            return Start;
        Start++;
    }
    return End;
}

//Templates + Iterators + Comparators    //Freedom from different operations
//ALl these names can be anything x , y , z...
template<class ForwardIterator , class T , class Compare>
ForwardIterator Search(ForwardIterator Start , ForwardIterator End , T key , Compare cmp)
{
    while(Start!=End)
    {
        if( cmp(*Start , key) )
            return Start;
        Start++;
    }
    return End;
}

class Book
{
public:
    int price;
    string name;
    Book(){}
    Book(string n , int p)
    {
        name = n;
        price = p;
    }
};

class BookCompare
{
public:
    //Operator overloading
    bool operator ()(Book b1 , Book b2)          //Overloading the operator --> ()   We will use it by an object .
    {                                           // suppose compare is the object which will use it.
        if(b1.name == b2.name)                  // compare() is not a function it is a functor or a function object.
            return true;
        else
            return false;
    }
};

int main()
{
    Book b1("c++" , 100);
    Book b2("java" , 120);
    Book b3("python" , 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("c++" , 110);
    BookCompare compare;

    auto it = Search(l.begin() , l.end() , bookToFind , compare);              //it here is list<Book>::iterator

    if(it!=l.end())
        cout<<"BOOK FOUND ";
    else
        cout<<"NOT FOUND";

return 0;
}
