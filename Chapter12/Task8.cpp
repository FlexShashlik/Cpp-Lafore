#include <iostream>
#include <fstream>

using namespace std;

struct link
{
    int data;
    link* next;
};

class linklist
{
private:
    link* first;
public:
    linklist()
        { first = NULL; }
    void additem(int d);
    void add();
    void display();
    void write();
    void read();
};

void linklist::additem(int d)
{
    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

void linklist::add()
{
    cout << "\nEnter value: ";
    int data;
    cin >> data;
    additem(data);
}

void linklist::display()
{
    link* current = first;

    cout << "\n- - -" << endl;

    while(current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    cout << "- - -\n" << endl;
}

void linklist::write()
{
    ofstream outputFile("output.dat");
    
    if(!outputFile)
    {
        cout << "An error has occured :C\n";
        return;
    }

    link* current = first;

    while(current != NULL)
    {
        outputFile << current->data << endl;
        current = current->next;
    }
}

void linklist::read()
{
    ifstream inputFile("output.dat");
    
    if(!inputFile)
    {
        cout << "An error has occured :C\n";
        return;
    }

    first = NULL;
    int data;

    while(inputFile >> data)
        additem(data);
}

int main()
{
    char ch;
    linklist list;

    while(true)
    {
        cout << "'a' -- add data for an employee"
              "\n'd' -- display data for all employees"
              "\n'w' -- write all employee data to file"
              "\n'r' -- read all employee data from file"
              "\n'x' -- exit"
              "\nEnter selection: ";

        cin >> ch;

        switch(ch)
        {
            case 'a':
                list.add(); 
                break;
            case 'd':
                list.display(); 
                break;
            case 'w':
                list.write(); 
                break;
            case 'r':
                list.read(); 
                break;
            case 'x': 
                return 0;
            default: 
                cout << "\nUnknown command";
         }
    }
    return 0;
}