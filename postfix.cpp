//--------------------------------------------------------------------
//
//  Laboratory 6, Programming Exercise 1                   postfix.cpp
//
//  SOLUTION: Postfix expression evaluator
//
//--------------------------------------------------------------------

// Reads a postfix expression (single digit, nonnegative integers and
// arithmetic operators) from the keyboard and outputs the value of
// the expression.

#include <iostream>
#include <iomanip>
#include <cctype>
// Chose one of the two below
#include "StackLinked.cpp"
//#include "StackLinked.cpp"

using namespace std;

void evalPostfix( Stack<float>& resultStack );

/*int main ()
{
    // Another demonstration that you can pass a derived class
    // to a function whose formal parameter specifies the base class.

    StackLinked<float> resultStack;   // Stack of intermediate results

    // Or could use StackArray
    //StackArray<float> resultStack;   // Stack of intermediate results

    evalPostfix(resultStack );

    return 0;
}*/

//--------------------------------------------------------------------

void evalPostfix( Stack<float>& resultStack ) 

// Evaluates a postfix expression from standard input

{
    float operand1,             // Right operand (infix form)
	  operand2,             // Left operand (infix form)
	  opResult;             // Result of current operation
    char ch;                    // Operand or operator

    cout << endl;
    cout << "Enter expression in postfix form : ";

    cin.get(ch);
    while( ch == ' ' )
	cin.get(ch);
    while ( ch != '\n' )
    {
	if ( isdigit(ch) )
	{
	    operand1 = ch - '0';
	    resultStack.push(operand1);
	}
	else
	{
	    operand1 = resultStack.pop();
	    operand2 = resultStack.pop();
	    switch ( ch )
	    {
		case '+' :  opResult = operand2 + operand1;  break;
		case '-' :  opResult = operand2 - operand1;  break;
		case '*' :  opResult = operand2 * operand1;  break;
		case '/' :  opResult = operand2 / operand1;
	    }
	    resultStack.push(opResult);
	}
	cin.get(ch);
	while( ch == ' ' )
	    cin.get(ch);
    }

    opResult = resultStack.pop();
    cout << " = " << setprecision(2) << opResult << endl;
}
