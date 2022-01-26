
#ifndef LIBRARY_OBJECTS_H_KNOWN
#define LIBRARY_OBJECTS_H_KNOWN
#include <iostream>
#include <string>

using namespace std;


class Company
{
private:

    string owner;
    string description;
    int foundation_year;
    double profits;

public:

    string getowner() {return owner;}
    string getDescription() {return description;}
    int getFoundation_year() { return foundation_year; }
    double getProfits() {return profits;}

    void setowner(string O) {owner = O;}
    void setDescription(string S) {description = S;}
    void setYear(int P) {foundation_year = P;}
    void setProfit(double P) {profits = P;}

    Company(string O="", string D="", int Year=0, double P=0)
    {
        owner = O; description = D; foundation_year = Year; profits = P;
    }

    void display();
    friend ostream& operator<<(ostream &stream, const Company &o);
    bool operator< (const Company &o);
    bool operator> (const Company &o);
};

void Company::display()
{
    cout << "\nOwner:\t" << owner;
    cout << "\nDescription:\t" << description;
    cout << "\nFoundation year:\t" << foundation_year;
    cout << "\nProfits:\t" << profits;
}

ostream& operator<< (ostream &stream, const Company &o)
{
    stream << "\nOwner:\t  " << o.owner << "\nDescription: " << o.description << "\nFoundation Year: " << o.foundation_year << "\nProfits:" << o.profits;
    return stream;
}

bool Company::operator< (const Company &o)
{
    if (this->profits < o.profits)
        return true;
    return false;
}

bool Company::operator> (const Company &o)
{
    if (this->profits > o.profits)
        return true;
    return false;
}


#endif // LIBRARY_OBJECTS_H_KNOWN
