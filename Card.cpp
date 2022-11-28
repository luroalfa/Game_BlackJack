#include <iostream>
#include <string>
using namespace std;
class Card
{
private:
    string name;
    int value;
    string suit;

public:
    Card(string _name, int _value, string _suit);
    ~Card();
    string getName()
    {
        return this->name;
    }
    int getValue()
    {
        return this->value;
    }
    string getSuite()
    {
        return this->suit;
    }
    void setValue(int _value)
    {
        this->value = _value;
    }
};

Card::Card(string _name, int _value, string _suit)
{
    this->name = _name;
    this->value = _value;
    this->suit = _suit;
}

Card::~Card()
{
}
