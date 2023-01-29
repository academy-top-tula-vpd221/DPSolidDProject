// DPSolidDProject.cpp 
#include <iostream>

using namespace std;

class IPrinter
{
public:
    virtual void Print(string text) = 0;
};

class Book
{
    string text;
    IPrinter* printer;
    
public:
    Book(IPrinter* printer = nullptr) : printer{ printer } {}

    string& Text() { return text; }
    IPrinter*& Printer() { return printer; }

    void Print()
    {
        printer->Print(text);
    }
};

class ConsolePrinter : public IPrinter
{
public:
    void Print(string text) override
    {
        cout << "text: " << text << "\n";
    }
};

class HtmlPrinter : public IPrinter 
{
public:
    void Print(string text) override
    {
        cout << "<html>" << text << "</html>\n";
    }
};



int main()
{
    Book book(new HtmlPrinter());
    book.Text() = "Hello world";

    book.Print();
}
