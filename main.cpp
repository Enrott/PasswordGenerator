#include <iostream>
#include <random>

// #include <cstring>

int length;
int *pLength = &length;
char characters;
bool inputCorrect;
bool regenPassword;
char answer;
void passwordLength(int *pLength);
void passwordGenerator(int *pLength, char characters);
void redraw(bool regenPassword, char answer);


/*  Program to generate a random password.
    
    Google too sus. 
    I don't want to use their "randomly" generated passwords.
*/

int main() {
    srand(time(nullptr));
    passwordLength(pLength);
    passwordGenerator(pLength, characters);
    redraw(regenPassword, answer);
    int *pLength = nullptr;
    int *pRandomNumber = nullptr;
    char *pAnswer = nullptr;

    std::cout << "program finished" << std::endl;
    return 0;
};

void passwordLength(int *pLength) {

    do {
	    std::cout << "Enter password length: ";
        std::cin >> length;

        if(std::cin.fail()) {
            std::cerr << "Not a number.\n";
            inputCorrect = false;

        } else if(*pLength > 10000) {
            std::cerr << "Password must be less than 10000 characters long.\n";
            inputCorrect = false;

        } else if(*pLength < 1) {
            std::cerr << "Password must be at least 1 character long.\n";
            inputCorrect = false;

        } else {
            inputCorrect = true;
        }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while(!inputCorrect);

    return;
};

void passwordGenerator(int *pLength, char) {

    std::mt19937 mt(rand());

    char characters[95] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/";

    std::cout << "Generating you a " << *pLength << " character password!\n";

    std::cout << "--------------------------------\n";
    for(int i = 0; i < *pLength; i++){
        int randomNumber = mt() % 94;
        int *pRandomNumber = &randomNumber;
        std::cout << characters[*pRandomNumber];
    };
    std::cout << '\n' << "--------------------------------\n";

    return;
};

void redraw(bool regenPassword, char answer) { 

    std::cout << "Would you like to generate another password (y/n) ";
    std::cin >> answer;

    char *pAnswer = &answer;

    switch (*pAnswer) {
        case 'N' : case 'n' :
            regenPassword = false;
                break;
        case 'Y' : case 'y' :
            regenPassword = true;
                break;

    } if(regenPassword) {
        passwordGenerator(pLength, characters);
        redraw(regenPassword, answer);

    } else {
        return;
    }
}

//    Interesting unused outputs.
//    std::cout << "possible number of characters " << strlen(characters) << std::endl;   // Displays the number of characters. requires #include <cstring>
//    std::cout << characters << std::endl;   // Displays all the characters.