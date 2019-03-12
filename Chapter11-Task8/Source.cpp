#include <iostream>
#include <cstring>

using namespace std;
const int LEN = 80;    //length of expressions, in characters
const int MAX = 40;    //size of stack

class Token
{
public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};

class Operator : public Token
{
private:
	char oper;
public:
	Operator(char c) : oper(c) {}

	char getOperator()
	{
		return oper;
	}

	float getNumber() 
	{
		return 0;
	}
};

class Number : public Token
{
private:
	float fnum;
public:
	Number(float n) : fnum(n) {}

	float getNumber()
	{
		return fnum;
	}

	char getOperator() 
	{
		return 0;
	}
};

class Stack
{
private:
	Token* token[MAX];
    int top;
public:
    Stack()
        { top = -1; }

    void push(char var)
    { 
		token[++top] = new Operator(var); 
	}

	void push(float var)
	{
		token[++top] = new Number(var);
	}

    char popOperator()
    {
		return token[top--]->getOperator();
	}

	float popNumber()
	{
		return token[top--]->getNumber();
	}

    int gettop()
        { return top; }
};

class express
{
private:
	Stack s;
	char* pStr;
	int len;
public:
    express(char* ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}
    void parse();
    float solve();
};

void express::parse()
{
   char* ch;
   float lastval;
   char lastop;
   char* next_token = NULL;

   ch = strtok_s(pStr, " ", &next_token);

   while(ch != NULL)
   {
		if(*ch=='+' || *ch=='-' || *ch=='*' || *ch=='/')
		{
			if (s.gettop() == 0) {			//if it's first operator
				//s.pushOperator(*ch);            //put on stack
				s.push(*ch);
			}
			else								//not first operator
			{
				lastval = s.popNumber();		//get previous digit
				lastop = s.popOperator();		//get previous operator
				//if this is * or / AND last operator was + or -
				if( (*ch=='*' || *ch=='/') &&
					(lastop=='+' || lastop=='-') )
					{
						s.push(lastop);	//restore last two pops
						s.push(lastval);
					}
				else							//in all other cases
				{
					switch(lastop)				//do last operation
					{							//push result on stack
						case '+':
							s.push(s.popNumber() + lastval);
							break;
						case '-':
							s.push(s.popNumber() - lastval);
							break;
						case '*':
							s.push(s.popNumber() * lastval);
							break;
						case '/':
							s.push(s.popNumber() / lastval);
							break;
						default:
							cout << "\nUnknown oper";
							exit(1);
					}
				}
				s.push(*ch);			//put current op on stack
			}
		}
		else
		{
			s.push((float)atof(ch));
		}

		ch = strtok_s(NULL, " ", &next_token);
   }
}

float express::solve()
{
   float lastval;

   while(s.gettop() > 0)
   {
      lastval = s.popNumber();
      switch(s.popOperator())
      {
         case '+': 
			 s.push(s.popNumber() + lastval); 
			 break;
         case '-':
			 s.push(s.popNumber() - lastval);
			 break;
         case '*':
			 s.push(s.popNumber() * lastval);
			 break;
         case '/':
			 s.push(s.popNumber() / lastval);
			 break;
         default:
			 cout << "\nUnknown operator";
			 exit(1);
      }
   }
   return s.popNumber();
}

int main()
{
	char ans[2];
	char string[LEN];
   
	cout << "\nEnter an arithmetic expression"
			"\nof the form 2 + 3.5 * 4.24 / 3.2425 - 2"
			"\nUse spaces!\n";
	do 
	{
		cout << "\nEnter expresssion: ";
		cin.getline(string, MAX);
		express* eptr = new express(string);
		eptr->parse();
		cout << "\nThe numerical value is: " 
			<< eptr->solve();
		delete eptr;
		cout << "\nDo another (Enter y or n)? ";
		cin.getline(ans, 2);
	} while(*ans == 'y');
}
