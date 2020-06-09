
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
    
	Bugs caught by the compiler:
	  All bugs had to deal with the Token class
	  1. Token() was not defined
	  2. Token(char ch) value(0) was not necessary
	  3. Token(char ch, string n) undefined

	Not caught by compiler:
	  1. void ignore(char) should be void ignore(char c) (line 40)
	  2. quit and print not included in case-switch statement (line 56)
	  3. s = ch should be s += ch (line 89)

	Notes from "Student":
	  - I think I've found all the bugs
	  - When trying to prevent floating-point powers narrow_cast returns 'info_loss'
	  - Unsure if implementation of drill 11 is correct
	  - Let me know if you find any more bugs that I've missed!

Calculation:
        Statement
        Print
        Quit
        Caclulation

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression

    Print:
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
		sqrt Primary
		pow ( number , number )
    Number:
        floating-point literal
*/

#include "../../../std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token() : kind(0) { }                                 //default constructor
	Token(char ch) :kind(ch){ }                           //initialize kind
	Token(char ch, double val) :kind(ch), value(val) { }  //initialize kind and value
	Token(char ch, string n): kind(ch), name(n) { }       //initialize kind and name
};

class Token_stream {
	bool full;                                          //is there a Token in the buffer?
	Token buffer;                                       //Where we keep a Token that was putback using unget()
public:
	Token_stream() :full(0), buffer(0) { }              //default constructor

	Token get();                                        //get a token
	void unget(Token t) { buffer=t; full=true; }        //put a token back

	void ignore(char c);                                  //discard characters
};

const char let = '#';    //used to define variables
const char quit = 'Q';   //indicates quit
const char print = ';';  // print prompt
const char number = '8'; //indicates number
const char name = 'a';   //indicates name
const char srt = 's';    //indicates square root
const char pw  = 'p';    //indicates power function
const string declexit = "exit";

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;         //skips whitespaces
	switch (ch) {
	case quit:
	case let:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch); // let each character represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();                   //put digit back into the input stream
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();                                                //putback unused character
			if (s == "exit") return Token(quit);
			if(s == "sqrt") return Token(srt);
			if(s == "pow") return Token(pw);
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
	// c represents the kind of Token
{
	//first look in buffer
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	//now search input
	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	

double get_value(string s)
	//return the value of the Variable named s
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, double d)
	//set the Variable named s to d
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
	//is s alreadt in names?
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//functions to match grammar rules
double primary()                                        //deal with numbers, parentheses, negatives, and variables
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case srt:
	{
		double d = primary();
		if(d < 0) error("sqrt(x): negative x");
		return sqrt(d);
	}
	case pw:
	{
		t = ts.get();
		if(t.kind != '(') error("'(' expected");
		double d = primary();
		
		t = ts.get();
		if(t.kind != ',') error("',' expected");
        
		t=ts.get();
		int i1 = narrow_cast<int>(t.value);

		t = ts.get();
		if(t.kind != ')') error("'(' expected");

		return pow(d,i1);
	}
	default:
		error("primary expected");
	}
}

double term()                                       //deal with *, and /
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()                 //deal with + and -
{
	double left = term();            
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;           //return the answer
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");

	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);

	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
		//predefined names
		names.push_back(Variable("k", 1000));

		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
