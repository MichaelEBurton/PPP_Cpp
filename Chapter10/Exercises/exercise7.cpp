/*
    Exercise 7 Chapter 10: Make a version of the calculator from chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for 
                            example, XXI + CIV == CXXV

    Exercise:
      Update Grammar

    Simple Calculator

    Revision history:

        Revised by Bjarne Stroustrup November 2013
        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally writeen by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.
    
    This program implements a basic expression calculator.
    Input from cin; output to cout.
    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Help
        Caclulation

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression
        "const" Name "=" Expression

    Print:
        ;

    Quit:
        quit

    Help:
        help

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
        Name
        Name "=" expression
        
    Number:
        floating-point literal
        roman numeral

    Input comes from cin through the Token_Stream called ts.
*/

#include "../../../std_lib_facilities.h"
//======================================================================================================================================================================
// Roman_int.cpp
class Roman_int {
public:
    Roman_int() {};
    Roman_int(string rn)
        : r{rn}
    {
    }
    string as_numeral() const {return r;}
    int as_int();

private:
    string r;

};

ostream& operator<<(ostream& os, Roman_int& rn);
istream& operator>>(istream& is, Roman_int& rn);

vector<char> numerals = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
vector<int> values = {1, 5, 10, 50, 100, 500, 1000};

int numeral_to_int(char n)
{
    for(int i = 0; i < numerals.size(); ++i)
    {
        if(n == numerals[i]) return values[i];
    }

    error("Bad Numeral");
}

int Roman_int::as_int()
{
    vector<char> char_numerals;

    for(char c:r)
        char_numerals.push_back(numeral_to_int(c));

    int sum = 0;
    int begin = char_numerals.size() - 1;  

    for(int i = begin; i >= 0; --i) // Parse the numeral from right to left
    {
        if(i == begin) sum += char_numerals[i];
        else
        {
            if(char_numerals[i] < char_numerals[i + 1]) sum -= char_numerals[i];
            else sum += char_numerals[i];
        }
        
    }

    return sum;
}

bool valid_numeral(char c) 
{
    for(char h:numerals)
    {
        if(c == h) return true;
    }
    return false;
            
}
ostream& operator<<(ostream& os, Roman_int& rn)
{
    return os<<rn.as_numeral()<<" is "<<rn.as_int();
}

istream& operator>>(istream& is, Roman_int& rn)
{
    string s;
    is>>s;
    for(char c:s)
        if(!valid_numeral(c)) error("Invalid numeral");
    
    rn = Roman_int{s};
    return is;
}

//=======================================================================================================================================================================
//Calculator.cpp
const char number = '8';
const char quit = 'q';
const string quitkey = "quit";
const char print = ';';
const string prompt = "> ";
const string result = "= "; //used to indicate what follows is a result
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const char cons = 'C';
const string constkey = "const";
const char help = 'H';


class Token {
    public:
        char kind;
        double value;
        string name;
        Token() : kind{0} {}                                  //default constructor
        Token(char ch) :kind{ch} {}                           //initialize kind
        Token(char ch, double val) : kind{ch}, value{val} {}  //initialize kind
                                                              // and value
        Token(char ch, string n) :kind{ch}, name{n} {}        //initialize kind
                                                            // and name
};

class Token_stream {
    public:
        Token get();              // get a token
        void putback(Token t);    // put a token back
        void ignore(char c);      // discard characters p to and including a c
    private:
        bool full{false};         // is there a Token in the buffer?
        Token buffer;             // here is where we keep a Token put back using putback()
};

void Token_stream::putback(Token t){
    if(full) error("putback() into a full buffer");
    buffer = t;      //copy t to buffer
    full = true;     // buffer is now full

}

Token Token_stream::get()
{
    if(full){
        full = false;
        return buffer;
    }
    char ch;
    cin.get(ch);    // note that cin.get() does NOT skip whitespace
    while (isspace(ch)) {
        if (ch == '\n') return Token(print); // if newline detected, return print Token
        cin.get(ch);
    }
    
    switch(ch){
    case print:      
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%':
    case '=':
        return Token{ch};    // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);        //put digit back into the input stream
        double val;
        cin>>val;
        int val2 = narrow_cast<int>(val);

        return Token{number, val2};
    }
    case 'I': case 'V': case 'X': case 'L': case 'C': case 'D': case 'M':
    {
        cin.putback(ch);
        Roman_int numeral;
        cin>>numeral;
        int numeral2 = numeral.as_int();

        return Token{number, numeral2};
    }
    default:
        if(isalpha(ch)){
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
            cin.putback(ch);
            if(s == declkey) return Token{let}; // declaration keyword
            if(s == constkey) return Token{cons};
            if(s == quitkey) return Token{quit};
            if(s == "help") return Token{help};
            return Token{name,s};
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
    // c represents the kind of Token
{
    //first look in buffer
    if(full && c == buffer.kind){
        full = false;
        return;
    }
    full = false;

    //now search input:
    char ch = 0;
    while(cin>>ch)
        if(ch == c) return;
}

Token_stream ts;

class Variable{
    public:
        string name;
        double value;
        bool constant = false;
};

class Symbol_table{
    public:
        vector<Variable> var_table;
        double get_value(string s);
        void set_value(string s, double d);
        bool is_declared(string var);
        double declare(string var, double val, bool b);
};

double Symbol_table::get_value(string s)
    //return the value of the Variable named s
{
    for(const Variable&v:var_table)
        if(v.name ==s) return v.value;
    error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, double d)
    //set the Variable named s to d
{
    for(Variable&v : var_table)
        if(v.name == s){
            if(v.constant == true) error("Cannot change the value of a constant");
            v.value = d;
            return;
        }
    error("set: undefind variable ", s);
}

bool Symbol_table::is_declared(string var)
// is var already in var_table
{
    for(const Variable& v:var_table)
        if(v.name == var) return true;
    return false;
}

double Symbol_table::declare(string var, double val, bool b)
    // add {var,val} to var_table
{
    if(is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable{var,val, b});
    return val;
}

Symbol_table st;

double expression();

//functions to match grammar rules
double primary(){                  // deal with numbers and parthenses
    Token t = ts.get();
    switch(t.kind){
    case '(':                     //handle '(' expression ')'
        { double d = expression();
          t = ts.get();
          if(t.kind != ')') error("')' expected");
          return d;
        }
    case number:
        return t.value;
    case '-':
        return -primary();
    case '+':
        return primary();
    case name:
    {
        Token t2 = ts.get();
        if(t2.kind == '=')
        {
            double d = expression();
            st.set_value(t.name, d);
            return d;
        }
        else
        {
            ts.putback(t2);
            return st.get_value(t.name);
        }   
    }
    default:
        error("primary expected");
    }
} 

double term(){                    // deal with *,/, and %
    double left = primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if(d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if(d == 0) error("%: divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression(){               // deal with + and -
    double left = term();                //read and evaluate a term
    Token t = ts.get();               //get the next token
    while(true){
        switch(t.kind){
        case '+':                        //evaluate term and add
            left += term();              
            t = ts.get();
            break;
        case '-':                        //evaluate term and subtract
            left -= term();  
            t = ts.get();
            break;
        default:                         //finally: no more + or -; return the answer
            ts.putback(t);
            return left;
        }
    }
}

double declaration(bool b)
    //assume we have seen "let"
    //handle: name = expression
    //declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if(t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    st.declare(var_name, d, b);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind){
        case let:
            return declaration(false);
        case cons:
            return declaration(true);
        default:
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void helpfunc()
{
    cout<<"Help: \n"
        <<"Acceptable operators: +, -, *, /, %\n"
        <<"The use of parenthesis is also allowed \n"
        <<"To print results end your expression with ';'\n"
        <<"To declare a constant use the const keyword: const x= 5; \n"
        <<"To declare a variable use the let keyword: let y = 7;\n";
}

void calculate()
{
    while(cin) 
    try{
        cout<<prompt; //print prompt
        Token t = ts.get();
        while(t.kind == print) t = ts.get();
        if(t.kind == quit) return;
        if(t.kind == help) helpfunc();
        ts.putback(t);
        cout<< result << statement() << '\n';
    }
    catch(exception& e){
        cerr<<e.what()<<'\n';
        clean_up_mess();
    }
}


int main()
try{
    // predefine names
    st.declare("pi",3.1415926535, true);
    st.declare("e", 2.7182818284, true);

    calculate();
    
    return 0;
}
catch(exception& e){
    cerr<<e.what()<<'\n';
    keep_window_open("~~");
    return 1;
}
catch(...){
    cerr<<"Oops unkown exception!";
    return 2;
}