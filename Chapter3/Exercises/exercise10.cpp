#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter a mathematical operation followed by two operands\n";

    string operation;
    double operand1;
    double operand2;

    cin>>operation>>operand1>>operand2;

    if (operation == "+" || operation == "plus")
        cout<<operand1 + operand2;
    else if(operation == "-" || operation == "minus")
        cout<<operand1 - operand2;
    else if (operation == "*" || operation == "mult")
        cout << operand1 * operand2;
    else if (operation == "/" || operation == "div")
        cout << operand1 / operand2;
}