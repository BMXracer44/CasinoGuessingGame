#include <iostream>
#include <cstdlib>
using namespace std;

int generateCompMove(){
    srand(time(0));
    return rand() % 101;
}

char playAgain(string s){
    char p = 'n';
    cout << s << "Would you like to play again? (Y for yes, N for no): ";
    cin >> p;
    return p;
}

int main(){
    cout << "Welcome to the casino guessing game!\n";
    cout << "Every time you guess the same number as the computer, you will double your money!\n";

    char play = 'n';
    cout << "Would you like to play? (Y for yes, N for no): ";
    cin >> play;
    if(play == 'Y'){
        cout << "\nGreat choice!\n";
    }
    else{
        cout << "\nEnjoy the rest of your day!\n";
        return 0;
    }

    int comp_guess = 0;
    int user_guess = 0;
    int score = 0;
    while(play == 'Y'){
        comp_guess = generateCompMove();
        cout << "Guess a number between 0-100: ";
        cin >> user_guess;
        if(user_guess == comp_guess){
            if(score == 0){
                score = 1;
            }
            else{
                score *= 2;
            }
            cout << "Congragulations!\n";
            play = playAgain("Congragulations!");
        }
        else{
            score = 0;
            cout << "You failed! The computer guessed " << comp_guess << "\n";
            play = playAgain("");
        }
    }

    cout << "\nFinal score: " << score;
}