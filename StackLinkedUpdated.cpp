//--------------------------------------------------------------------
//
//  Laboratory 6                                       StackLinked.cpp
//
//  ** SOLUTION: Linked list implementation of the Stack ADT **
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_CPP
#define STACKLINKED_CPP

#include <iostream>

#include "StackLinked.h"

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& newDataItem,
					  StackLinked<DataType>::StackNode* nextPtr)

// Creates a stack node containing item newDataItem and next pointer
// nextPtr.

    : dataItem(newDataItem), next(nextPtr)
{
	dataItem = newDataItem;
	next = nextPtr;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) 
: top(0) 

// Creates an empty stack. The parameter maxNumber is provided for 
// compatability with the array implementation and is ignored.

{
	StackLinked stack = new StackLinked(maxNumber);
	DataType dataItem = 0;
	
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)

// Copy constructor for linked stack

: top( 0 )
{
    (void) operator=(other);	// Use operator=, ignore return value
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)

// Overloaded assignment operator for the StackLinked class.
// Because this function returns a StackLinked object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
	if (!other.isEmpty())
	{
		top = new StackNode(other.top->dataItem, 0);
		StackNode* x = other.top->next;
		StackNode* temp = 0;
		StackNode* y = top;

		while (x != 0)
		{
			temp = new StackNode(x->dataItem, 0);

			y->next = 0;
			y = top->next;
			x = top;
			}
		}
	return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::~StackLinked() 

// Destructor. Frees the memory used by a stack.

{
	clear();
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error) 

// Inserts newDataItem onto the top of a stack.

{
    if (isFull()) {
	// Not likely with linked implementation
	throw logic_error("push() while stack full");	
    }

	if (isEmpty())
	{
		top = new StackNode(newDataItem, 0);

	}
	else
	{
		StackNode* temp1 = top;
		top = new StackNode(newDataItem, temp1);

	}

}

//--------------------------------------------------------------------

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error) 

// Removes the topmost item from a stack and returns it.

{
    if (isEmpty()) {
	throw logic_error("pop() while stack empty");
    }

	StackNode* temp2 = top;
	top = top->next;

	DataType temp3 = t->dataItem;
	delete temp2;

	return temp3;

}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::clear() 

// Removes all the data items from a stack.

{
	top = -1;
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const 

// Returns true if a stack is empty. Otherwise, returns false.

{
	if (top == 0)
		return true;
	else
		return false;
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackLinked<DataType>::isFull() const 

// Returns true if a stack is full. Otherwise, returns false. 

{
    return false;

    /*
    // Alternatively, can use implementation below.
    // This is a somewhat awkward way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
    // We are not aware of any other standard/portable way of 
    // performing the test. And this can fail due to external issues
    // such as the system exhausting swap or another thread stealing
    // the remaining memory between when isFull returns its result and
    // the caller does something that assumes that isFull() returned
    // a valid answer.
    //
    // Alternatives include just the line "return false", which is
    // probably good enough in this context, or platform-dependent
    // checks for available memory.
    StackNode* temp;
    DataType junk;

    try
    {
        temp = new StackNode( junk, 0 );
    }
    catch ( bad_alloc &e )
    {
        return true;
    }

    delete temp;
    return false;
    */
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }
}

#endif		//#ifndef STACKLINKED_CPP
