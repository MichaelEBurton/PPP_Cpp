#include "../../../std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
};

class Token_stream {
    public:
        Token get();              // get a token
        void putback(Token t);    // put a token back
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
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '{': case '}':
    case '+': case '-': case '*': case '/': case '!':
        return Token{ch};    // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);        //put digit back into the input stream
        double val;
        cin>>val;
        return Token{'8', val};
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;
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
    case '{':                     //handle '(' expression ')'
        { double d = expression();
          t = ts.get();
          if(t.kind != '}') error("'}' expected");
          return d;
        }
    case '8':
        return t.value;
    default:
        error("primary expected");
    }
} 

double factorial(){              // deal with !
    double left = primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '!':               // if a primary is followed by '!' compute the factorial
            if(left == 0)       // 0! = 1
                return 1;
            for(int i = left - 1; i > 0; --i)
                left *= i;
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term(){                    // deal with *,/, and %
    double left = factorial();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial();
            if(d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression(){               // deal with + and =
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
        default:                         //finally: no more + o r -; return the answer
            ts.putback(t);
            return left;
        }
    }
}



int main()
try{
    double val = 0;
    cout<<"Please enter an expression followed by ';' ex: (2+3)*5;\n";
    while(cin) {
        Token t = ts.get();

        if(t.kind == 'q') break;         //q for quit
        if(t.kind == ';')                // ; for print now
            cout<<"="<<val<<'\n';
        else
            ts.putback(t);
        val = expression();
    }
}
catch(exception& e){
    cerr<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops unkown exception!";
    return 2;
}