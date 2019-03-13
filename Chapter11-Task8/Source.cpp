#include <iostream>
#include <cstring>

using namespace std;
const int LEN = 80;    //length of expressions, in characters
const int MAX = 40;    //size of stack
const int TOP = 0;

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
        { top = TOP; }

	void push(Token* t)
	{
		token[++top] = t;
	}

	Token* pop() 
	{
		return token[top--];
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
			if (s.gettop() == TOP + 1) //if it's first operator
			{			
				s.push(new Operator(*ch));
			}
			else								//not first operator
			{
				lastval = s.pop()->getNumber();		//get previous digit
				lastop = s.pop()->getOperator();		//get previous operator
				//if this is * or / AND last operator was + or -
				if( (*ch=='*' || *ch=='/') &&
					(lastop=='+' || lastop=='-') )
					{
						s.push(new Operator(lastop));	//restore last two pops
						s.push(new Number(lastval));
					}
				else							//in all other cases
				{
					switch(lastop)				//do last operation
					{							//push result on stack
						case '+':
							s.push(new Number(s.pop()->getNumber() + lastval));
							break;
						case '-':
							s.push(new Number(s.pop()->getNumber() - lastval));
							break;
						case '*':
							s.push(new Number(s.pop()->getNumber() * lastval));
							break;
						case '/':
							s.push(new Number(s.pop()->getNumber() / lastval));
							break;
						default:
							cout << "\nUnknown oper";
							exit(1);
					}
				}
				s.push(new Operator(*ch));			//put current op on stack
			}
		}
		else
		{
			s.push(new Number(atof(ch)));
		}

		ch = strtok_s(NULL, " ", &next_token);
   }
}

float express::solve()
{
   float lastval;

   while(s.gettop() > TOP + 1)
   {
      lastval = s.pop()->getNumber();
      switch(s.pop()->getOperator())
      {
         case '+': 
			 s.push(new Number(s.pop()->getNumber() + lastval));
			 break;
         case '-':
			 s.push(new Number(s.pop()->getNumber() - lastval));
			 break;
         case '*':
			 s.push(new Number(s.pop()->getNumber() * lastval));
			 break;
         case '/':
			 s.push(new Number(s.pop()->getNumber() / lastval));
			 break;
         default:
			 cout << "\nUnknown operator";
			 exit(1);
      }
   }
   return s.pop()->getNumber();
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
