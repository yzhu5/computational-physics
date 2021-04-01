#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class List
{
public:
    typedef int Item;

private:
    static const unsigned size = 5;
    Item ll[size];
    unsigned L;

public:
    List(const Item arr[] = NULL, unsigned n = 0);
		bool isFull (void) const;
		bool isEmpty (void) const;
		bool append (const Item& item);
		void visit (void (*pf) (Item& item));
};

void show(List::Item& item);
#endif // LIST_H_INCLUDED
