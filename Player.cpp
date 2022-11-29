#include <iostream>
#include <string>
#include <vector>
#include "Card.cpp"
using namespace std;

class Player
{
private:
    /// @brief Variable contains the name of the player
    string name;
    /// @brief
    bool win, requestCard, ranking;
    /// @brief The player class has a some cards for play
    vector<Card> myCards;

public:
    /// @brief This constructor is used to instantiate the object.
    /// @param First param is a string
    Player(string);
    ~Player(); // Destroyer
    string getName()
    {
        return this->name;
    }
    void setName(string _name)
    {
        this->name = _name;
    }

    void setWinState(bool _win)
    {
        this->win = _win;
    }
    bool getWinState()
    {
        this->getPoints();
        return this->win;
    }
    bool getBoolRanking()
    {
        if (this->getPoints() < 21)
        {
            this->ranking = true;
        }
        return this->ranking;
    }

    bool changeValueCard_AS()
    {
        bool result = false;
        for (int i = 0; i < this->myCards.size(); i++)
        {
            if (this->myCards.at(i).getName() == "A")
            {
                this->myCards.at(i).setValue(1);
                result = true;
            }
        }
        return result;
    }
    bool doYouHaveCard_AS()
    {
        bool result = false;
        for (int i = 0; i < this->myCards.size(); i++)
        {
            if (this->myCards.at(i).getName() == "A")
            {
                result = true;
            }
        }
        return result;
    }
    int howManyCards_AS()
    {
        int counter = 0;
        for (int i = 0; i < this->myCards.size(); i++)
        {
            if (this->myCards.at(i).getName() == "A")
            {
                counter++;
            }
        }
        return counter;
    }

    bool getRequestCard()
    {
        return this->requestCard;
    }
    void setRequestCard(bool _request)
    {
        this->requestCard = _request;
    }

    vector<Card> getMyCards()
    {
        return this->myCards;
    }
    void pushMyCards(Card _card)
    {
        myCards.push_back(_card);
    }

    int getPoints()
    {
        int sum = 0;
        for (int i = 0; i < this->myCards.size(); i++)
        {
            sum = sum + this->myCards.at(i).getValue();
        }
        if (sum == 21)
        {
            this->win = true;
        }
        return sum;
    }

    int getHowManyCardsDoYouHave()
    {
        return this->myCards.size();
    }
};
// CONSTRUCTORS OVERLOAD
/// @brief Second constructor, only the name is initialized
/// @param _name
Player::Player(string _name)
{
    this->name = _name;
    this->win = false;
    this->requestCard = false;
    this->ranking = false;
}
/// @brief Destroyer
Player::~Player()
{
}