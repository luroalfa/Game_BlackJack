/*
    @author:        Luis A. Rodríguez F.
    Date:           Monday, November 21th, 2022.
    Last edit:      Monday, November 28th, 2022.
    Description:
        Create a game of BlackJack or 21.
*/
#include <iostream>
#include "Player.cpp"
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
/// @brief Arrays players
Player *players[3];
/// @brief Deck of cards
vector<Card> maso;
// TODO Verify the method print card 2 o more numbers
//  FUNCTIONS DECLARATION

/// @brief The function is used to print cards of each player
/// @param cards Vector type Card
void printCards(vector<Card> cards);
/// @brief The function is used to print cards of all players
void showAllCard();
/// @brief The main idea of this function is to ask the player if he wants one more card
/// @param _player Integer The player in turn
/// @return
bool questionToThePlayer(int _player);
/// @brief We fill the maso in an orderly way
/// @return The vector maso type Card
bool deliverCard(int _player);
vector<Card> fillCards();

// Main function
int main()
{
    fillCards();
    srand(time(NULL));
    random_shuffle(maso.begin(), maso.end());
    //  Variables declarationy
    string name;
    bool request;
    int player = 0, round = 1;
    // INTRO
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⢧⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡕⠂⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⡅⣻⡿⢿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠿⢿⣿⡇⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠘⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣿⣿⡿⠿⠛⠻⣿⣿⣿⣿⡿⠟⠁⠈⠀⠉⠻⡆⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣯⠄⠂⠀⠀⣿⡋⠀⢀⠀⠀⠀⠉⣿⣿⡀⠀⠀⠘⠓⣠⣶⣿⡀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣫⡆⠀⠀⢀⣿⣷⣶⣄⠀⢀⣤⣴⣿⣿⣿⣶⣄⠀⣴⣿⣿⣿⠁⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⡤⠙⢿⣿⣿⣷⣾⣿⡿⣿⣿⢿⠿⣿⣧⣿⣿⡿⢣⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣷⣌⠈⠀⠀⠀⠀⣆⠈⡉⢹⣿⣿⣆⡀⠀⠀⢠⣿⣿⣿⡿⢃⣼⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠙⢿⣿⣆⠈⠛⠛⠛⠀⠀⠈⠉⠁⠀⢠⣿⠇⠀⠀⠀⠹⢿⡇⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⡫⠀⠀⠁⠀⠀⠀⠈⠻⣿⢢⣄⠀⠀⠀⠀⠀⣀⣠⣾⡾⠋⠀⠀⠀⠀⢀⠴⠋⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣁⠄⠀⠀⠀⣀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⠿⡿⠋⠀⠀⠀⠀⠀⣀⠬⠆⢀⣿⣿⣿⣿⣿⣿\n";
    cout << "⣿⣿⣿⣿⣿⣿⣿⣧⣄⠀⠀⠉⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠠⠙⣿⣿⣿⣿⣿⣿\n";
    cout << "+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+\n";
    cout << "|W|e|l|c|o|m|e| |t|o| |B|l|a|c|k|J|a|c|k|\n";
    cout << "+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+\n";
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el nombre del " << i + 1 << "° jugador.\n";
        getline(cin, name);
        players[i] = new Player(name);
        players[i]->pushMyCards(maso.back());
        maso.pop_back();
        players[i]->pushMyCards(maso.back());
        maso.pop_back();
    }
    system("clear");
    //* We check if some of the players already have 21 points from the distribution of cards
    if (players[0]->getWinState() == true || players[1]->getWinState() == true || players[2]->getWinState() == true)
    {
        showAllCard();
        (players[0]->getWinState()) && cout << "El jugador " << players[0]->getName() << " ha ganado.";
        (players[1]->getWinState()) && cout << "El jugador " << players[1]->getName() << " ha ganado.";
        (players[2]->getWinState()) && cout << "El jugador " << players[2]->getName() << " ha ganado.";
    }
    else
    {
        do
        {
            if (player == 3)
            {
                player = 0;
            }
            cout << "RONDA #" << round << "\n\n";
            showAllCard();
            //* The player is asked whether or not he wants a card
            request = questionToThePlayer(player);
            players[player]->setRequestCard(request);
            //* If your answer is YES, a card is delivered and it's removed of the maso.
            (request) && deliverCard(player);
            // TODO Se debe comprobar si tiene 21 si los tiene ha ganado el juego y se modifica su estado WIN como true y salimos con un break.
            //* Check if the 21 points were exceeded if it was passed, check if it has a card A if it has a change value to one.
            (int(players[player]->getPoints()) > 21) && ((players[player]->doYouHaveCard_AS()) && players[player]->changeValueCard_AS());
            player++;
            request = questionToThePlayer(player);
            players[player]->setRequestCard(request);
            (request) && deliverCard(player);
            //* Check if the 21 points were exceeded if it was passed, check if it has a card A if it has a change value to one.
            (players[player]->getPoints() > 21) && (players[player]->doYouHaveCard_AS()) && players[player]->changeValueCard_AS();
            player++;
            request = questionToThePlayer(player);
            players[player]->setRequestCard(request);
            (request) && deliverCard(player);
            //* Check if the 21 points were exceeded if it was passed, check if it has a card A if it has a change value to one.
            (players[player]->getPoints() > 21) && (players[player]->doYouHaveCard_AS()) && players[player]->changeValueCard_AS();
            player++;
            round++;
            system("clear");
            //* In the while we verify if someone has won or if all players did not request a card
        } while ((players[0]->getRequestCard() == true || players[1]->getRequestCard() == true || players[2]->getRequestCard() == true) && (players[0]->getWinState() == false && players[1]->getWinState() == false && players[2]->getWinState() == false));

        //* Check if all players not request card
        if (players[0]->getRequestCard() == false && players[1]->getRequestCard() == false && players[2]->getRequestCard() == false)
        {
            cout << "Jugador 1: " << players[0]->getPoints() << "\n";
            cout << "Jugador 2: " << players[1]->getPoints() << "\n";
            cout << "Jugador 3: " << players[2]->getPoints() << "\n";
            // TODO Debo verificar si hay numero menores de 21 si es asi cuantos? y el mayor de ellos es el mas cercano.
            // TODO Sino hay numeros menores debo verificar cual numero de ellos es el menor.
            // Si todo pasaron el 21 quien gana?
            // Jugador 1 : 19-->GANO!
            // Jugador 2 : 18
            // Jugador 3 : 24

            /*
            30-25=5
            15-25=-10
            18-25=-7

            25


            */

            // Jugador 1 : 20-->GANO!
            // Jugador 2 : 18
            // Jugador 3 : 22-->GANO!

            // Jugador 1 : 19
            // Jugador 2 : 18
            // Jugador 3 : 22-->GANO!

            // Jugador 1 : 19-->GANO!
            // Jugador 2 : 19-->GANO!
            // Jugador 3 : 19-->GANO!
        }
        else
        {
            showAllCard();
            (players[0]->getWinState()) && cout << "El jugador " << players[0]->getName() << " ha ganado.";
            (players[1]->getWinState()) && cout << "El jugador " << players[1]->getName() << " ha ganado.";
            (players[2]->getWinState()) && cout << "El jugador " << players[2]->getName() << " ha ganado.";
        }
    }
    return 0;
}

vector<Card> fillCards()
{
    maso.push_back(Card("A", 11, "♦"));
    maso.push_back(Card("2", 2, "♦"));
    maso.push_back(Card("3", 3, "♦"));
    maso.push_back(Card("4", 4, "♦"));
    maso.push_back(Card("5", 5, "♦"));
    maso.push_back(Card("6", 6, "♦"));
    maso.push_back(Card("7", 7, "♦"));
    maso.push_back(Card("8", 8, "♦"));
    maso.push_back(Card("9", 9, "♦"));
    maso.push_back(Card("10", 10, "♦"));
    maso.push_back(Card("J", 10, "♦"));
    maso.push_back(Card("Q", 10, "♦"));
    maso.push_back(Card("K", 10, "♦"));
    maso.push_back(Card("A", 11, "♣"));
    maso.push_back(Card("2", 2, "♣"));
    maso.push_back(Card("3", 3, "♣"));
    maso.push_back(Card("4", 4, "♣"));
    maso.push_back(Card("5", 5, "♣"));
    maso.push_back(Card("6", 6, "♣"));
    maso.push_back(Card("7", 7, "♣"));
    maso.push_back(Card("8", 8, "♣"));
    maso.push_back(Card("9", 9, "♣"));
    maso.push_back(Card("10", 10, "♣"));
    maso.push_back(Card("J", 10, "♣"));
    maso.push_back(Card("Q", 10, "♣"));
    maso.push_back(Card("K", 10, "♣"));
    maso.push_back(Card("A", 11, "♥"));
    maso.push_back(Card("2", 2, "♥"));
    maso.push_back(Card("3", 3, "♥"));
    maso.push_back(Card("4", 4, "♥"));
    maso.push_back(Card("5", 5, "♥"));
    maso.push_back(Card("6", 6, "♥"));
    maso.push_back(Card("7", 7, "♥"));
    maso.push_back(Card("8", 8, "♥"));
    maso.push_back(Card("9", 9, "♥"));
    maso.push_back(Card("10", 10, "♥"));
    maso.push_back(Card("J", 10, "♥"));
    maso.push_back(Card("Q", 10, "♥"));
    maso.push_back(Card("K", 10, "♥"));
    maso.push_back(Card("A", 11, "♠"));
    maso.push_back(Card("2", 2, "♠"));
    maso.push_back(Card("3", 3, "♠"));
    maso.push_back(Card("4", 4, "♠"));
    maso.push_back(Card("5", 5, "♠"));
    maso.push_back(Card("6", 6, "♠"));
    maso.push_back(Card("7", 7, "♠"));
    maso.push_back(Card("8", 8, "♠"));
    maso.push_back(Card("9", 9, "♠"));
    maso.push_back(Card("10", 10, "♠"));
    maso.push_back(Card("J", 10, "♠"));
    maso.push_back(Card("Q", 10, "♠"));
    maso.push_back(Card("K", 10, "♠"));
    return maso;
}
void printCards(vector<Card> cards)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < cards.size(); c++)
        {
            switch (r)
            {
            case 0:
                if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                {
                    printf("\x1b[0;31;47m");
                    printf("╔═════╗\t");
                    printf("\x1b[0m");
                }
                else
                {
                    printf("\x1b[0;30;47m");
                    printf("╔═════╗\t");
                    printf("\x1b[0m");
                }
                break;
            case 1:
                if (cards.at(c).getName() == "10")
                {
                    if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                    {
                        printf("\x1b[0;31;47m");
                        printf("║%s%s", cards.at(c).getName().c_str(), "   ║\t");
                        printf("\x1b[0m");
                    }
                    else
                    {
                        printf("\x1b[0;30;47m");
                        printf("║%s%s", cards.at(c).getName().c_str(), "   ║\t");
                        printf("\x1b[0m");
                    }
                }
                else
                {
                    if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                    {
                        printf("\x1b[0;31;47m");
                        printf("║%s%s", cards.at(c).getName().c_str(), "    ║\t");
                        printf("\x1b[0m");
                    }
                    else
                    {
                        printf("\x1b[0;30;47m");
                        printf("║%s%s", cards.at(c).getName().c_str(), "    ║\t");
                        printf("\x1b[0m");
                    }
                }
                break;
            case 2:
                if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                {
                    printf("\x1b[0;31;47m");
                    printf("║  %s%s", cards.at(c).getSuite().c_str(), "  ║\t");
                    printf("\x1b[0m");
                }
                else
                {
                    printf("\x1b[0;30;47m");
                    printf("║  %s%s", cards.at(c).getSuite().c_str(), "  ║\t");
                    printf("\x1b[0m");
                }

                break;
            case 3:
                if (cards.at(c).getName() == "10")
                {
                    if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                    {
                        printf("\x1b[0;31;47m");
                        printf("║   %s%s", cards.at(c).getName().c_str(), "║\t");
                        printf("\x1b[0m");
                    }
                    else
                    {
                        printf("\x1b[0;30;47m");
                        printf("║   %s%s", cards.at(c).getName().c_str(), "║\t");
                        printf("\x1b[0m");
                    }
                }
                else
                {
                    if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                    {
                        printf("\x1b[0;31;47m");
                        printf("║    %s%s", cards.at(c).getName().c_str(), "║\t");
                        printf("\x1b[0m");
                    }
                    else
                    {
                        printf("\x1b[0;30;47m");
                        printf("║    %s%s", cards.at(c).getName().c_str(), "║\t");
                        printf("\x1b[0m");
                    }
                }
                break;
            case 4:
                if (cards.at(c).getSuite() == "♦" || cards.at(c).getSuite() == "♥")
                {
                    printf("\x1b[0;31;47m");
                    printf("╚═════╝\t");
                    printf("\x1b[0m");
                }
                else
                {
                    printf("\x1b[0;30;47m");
                    printf("╚═════╝\t");
                    printf("\x1b[0m");
                }
                break;
            }
        }
        cout << "\n";
    }
}
void showAllCard()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Nombre del " << i + 1 << "° jugador:\t" << players[i]->getName() << "\n";
        cout << "Su puntaje es de: " << players[i]->getPoints() << "\n";
        printCards(players[i]->getMyCards());
        cout << "\n";
    }
}
bool questionToThePlayer(int _player)
{
    string option;
    bool result;
    cout << "👽︎🗨:\n"
         << players[_player]->getName() << " desea una carta más?🃏(s/n)\n";
    cin >> option;
    if (option == "s")
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
bool deliverCard(int _player)
{
    players[_player]->pushMyCards(maso.back());
    maso.pop_back();
    return true;
}
