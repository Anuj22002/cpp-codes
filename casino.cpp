#include <bits/stdc++.h>
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rulesofgames()
{
    system("cls");
    cout << "\t\t\t\tCASINO RULES!\n";
    cout << "\t1. Choose a number between 1 to 5\n";
    cout << "\t2. Winner gets 3 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main(){
    string Name;
    int balance; // stores player's balance
    int betamt;
    int guess;
    int select; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t**********WELCOME TO CASINO*********\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, Name);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("cls");
        rulesofgames();
        cout << "\n\nYour current balance is $ " << balance << "\n";  // Get player's betting balance

        do
        {
            cout << "Hey, " << Name<<", enter betting amount : $";
            cin >> betamt;
            if(betamt > balance)
                cout << "Betting amount should be less than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(betamt > balance); // Get player's numbers

        do
        {
            cout << "Guess any betting number between 1 & 5 :";
            cin >> guess;
            if(guess <= 0 || guess > 5)
                cout << "\nNumber should be between 1 to 5\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 5);
        select = rand()%5 + 1;
        if(select == guess)
        {
            cout << "\n\nYou are in luck!! You have won $." << betamt * 3;
            balance = balance + betamt * 3;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< betamt <<"\n";
            balance = balance - betamt;
        }
        cout << "\nThe winning number was : " << select <<"\n";
        cout << "\n"<<Name<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You are poor now and can't play ";
            break;
        }
        cout << "\n\n--> play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}