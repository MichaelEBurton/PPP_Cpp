/*
    Modify the calculator program from chapter 7 to make the input stream an explicit parameter. Also give the Token_stream() construct an istream& parameter so when we figure out how to make
      an istream we can use the calculator for those.

      Unsure if I completed the second portion of this exercise.
*/

#include "../../../std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= "; //used to indicate what follows is a result
const char name = 'a';
const char let = 'L';
const string declkey = "let";

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
        Token_stream();
        Token_stream(istream&);
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
    cin>>ch;    //note >> skips whitespace(space, newline, tab,etc.)
    
    switch(ch){
    case print:    
    case quit:    
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
        return Token{number, val};
    }
    default:
        if(isalpha(ch)){
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if(s == declkey) return Token{let}; // declaration keyword
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
};

vector<Variable> var_table;

double get_value(string s)
    //return the value of the Variable named s
{
    for(const Variable&v:var_table)
        if(v.name ==s) return v.value;
    error("get: undefined variable ", s);
}

void set_value(string s, double d)
    //set the Variable named s to d
{
    for(Variable&v : var_table)
        if(v.name == s){
            v.value = d;
            return;
        }
    error("set: undefind variable ", s);
}

bool is_declared(string var)
// is var already in var_table
{
    for(const Variable& v:var_table)
        if(v.name == var) return true;
    return false;
}

double define_name(string var, double val)
    // add {var,val} to var_table
{
    if(is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable{var,val});
    return val;
}

double expression(Token_stream& ts);

//functions to match grammar rules
double primary(Token_stream& ts){                  // deal with numbers and parthenses
    Token t = ts.get();
    switch(t.kind){
    case '(':                     //handle '(' expression ')'
        { double d = expression(ts);
          t = ts.get();
          if(t.kind != ')') error("')' expected");
          return d;
        }
    case number:
        return t.value;
    case '-':
        return -primary(ts);
    case '+':
        return primary(ts);
    case name:
        return get_value(t.name);
    default:
        error("primary expected");
    }
} 

double term(Token_stream& ts){                    // deal with *,/, and %
    double left = primary(ts);
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= primary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = primary(ts);
            if(d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary(ts);
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

double expression(Token_stream& ts){               // deal with + and -
    double left = term(ts);                //read and evaluate a term
    Token t = ts.get();               //get the next token
    while(true){
        switch(t.kind){
        case '+':                        //evaluate term and add
            left += term(ts);              
            t = ts.get();
            break;
        case '-':                        //evaluate term and subtract
            left -= term(ts);  
            t = ts.get();
            break;
        default:                         //finally: no more + or -; return the answer
            ts.putback(t);
            return left;
        }
    }
}

double declaration(Token_stream& ts)
    //assume we have seen "let"
    //handle: name = expression
    //declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if(t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression(ts);
    define_name(var_name, d);
    return d;
}

double statement(Token_stream& ts)
{
    Token t = ts.get();
    switch(t.kind){
        case let:
            return declaration(ts);
        default:
            ts.putback(t);
            return expression(ts);
    }
}

void clean_up_mess(Token_stream& ts)
{
    ts.ignore(print);
}

void calculate()
{
    while(cin) 
    try{
        cout<<prompt; //print prompt
        Token t = ts.get();
        while(t.kind == print) t = ts.get();
        if(t.kind == quit) return;
        ts.putback(t);
        cout<< result << statement(ts) << '\n';
    }
    catch(exception& e){
        cerr<<e.what()<<'\n';
        clean_up_mess(ts);
    }
}


int main()
try{
    // predefine names
    define_name("pi",3.1415926535);
    define_name("e", 2.7182818284);

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