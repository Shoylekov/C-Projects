#include <iostream>
#include <ctime>

char getUserChoice(){
    char player;
    std::cout << "Rock-Paper-Scissors Game!\n";
    do{
        std::cout << "*************************\n";
        std::cout << "Choose a valid choice!\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cout << "Enter choice: ";
        std::cin >> player;
        std::cout << "*************************\n";
    }while(player != 'r' && player != 'p' && player != 's');
    return player;
}
char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3 + 1;
    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}
void showChoice(char choice){
    switch(choice){
        case 'r': std::cout << "Rock\n";
            break;
        case 'p': std::cout << "Paper\n";
            break;
        case 's': std::cout << "Scissors\n";
            break;
    }
}
void chooseWinner(char player, char computer){
    switch(player){
        case 'r': if(computer == 'r'){
            std::cout << "DRAW!\n";
            }
            else if(computer == 'p'){
                std::cout << "You Lose!\n";
            }
            else{
                std::cout << "You Win!\n";
            }
            break;

        case 'p': if(computer == 'r'){
            std::cout << "You Win!\n";
            }
            else if(computer == 'p'){
                std::cout << "DRAW!\n";
            }
            else{
                std::cout << "You Lose!\n";
            }
            break;

        case 's': if(computer == 'r'){
            std::cout << "You Lose!\n";
            }
            else if(computer == 'p'){
                std::cout << "You Win!\n";
            }
            else{
                std::cout << "DRAW!\n";
            }
            break;
        }
}

int main(){
    char player;
    char computer;

    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer choice: ";
    showChoice(computer);

    chooseWinner(player, computer);


    return 0;
}