#include<iostream>
#include<stack>
using namespace std;

// create a global stack 
stack <int> guessRecord;

//declare guess function
int guess(int low, int high);
    //PRECONDITION: low and high are valid integers
    //POSTCONDITION: returns a valid integer between low and high that the user guessed

//declaure printGuesses function
void printGuesses(stack <int> guessRecord);

int main(){
    int lowNumber;
    int highNumber;
    char playAgain;
    // ask the user for the low and high numbers and ensure they are valid
    do{
    cout << "Please input a positive integer: ";
    cin >> lowNumber;
    cout << "Please input another positive integer: ";
    cin >> highNumber;

    // ensure that the lowNumber is smaller than the highNumber
    if(highNumber < lowNumber){
        int temp = highNumber;
        highNumber = lowNumber;
        lowNumber = temp;
    }
    cout << "Pick a number in your head between " << lowNumber << " and " << highNumber << ": " << endl;
    cout << "I will now guess your number between " << lowNumber << " and " << highNumber << "." << endl;

    // call the guesser function
    int solution = guess(lowNumber, highNumber);
    cout << "I guessed your number! It was " << solution << "." << endl;
    cout << "Would you like to play again? (y/n)" << endl;
    cin >> playAgain;
    }
    while(playAgain == 'y');
    cout << "Thank you for playing!" << endl;
    return 0;






}

int guess(int low, int high){
    //PRECONDITION: low and high are valid integers
    //POSTCONDITION: returns a valid integer between low and high that the user guessed

    // use recursion to guess the number
    if(low == high){
        cout << "********************************************************" << endl;
        cout << "Here is the list of guesses I made: " << endl;
        printGuesses(guessRecord);
        cout << "********************************************************" << endl;
        return low;
    }
    char response;
    int midpoint = (low + high) / 2;
    // add the midpoint to the guessRecord  
    guessRecord.push(midpoint);
    cout << "Is your number " << midpoint << "? (y/n)" << endl;
    cin >> response;
    if(response == 'y'){
        //cout << "I guessed it!" << endl;
        // print the guessRecord
        cout << "********************************************************" << endl;
        cout << "Here is the list of guesses I made: " << endl;
        printGuesses(guessRecord);
        cout << "********************************************************" << endl;
        return midpoint;
    }
    else{
        cout << "Is your number larger then " << midpoint << "? (y/n)" << endl;
        cin >> response;
        if(response == 'y'){
            return guess(midpoint + 1, high);
        }
        else{
            return guess(low, midpoint - 1);
        }

    }


}

void printGuesses(stack <int> guessRecord){
    //PRECONDITION: guessRecord is a valid stack containing the guesses
    //POSTCONDITION: prints the guessRecord to the screen using recursion
    if(guessRecord.empty()){
        return;
    }
    else{
        cout << guessRecord.top() << endl;
        guessRecord.pop();
        printGuesses(guessRecord);
    }
}