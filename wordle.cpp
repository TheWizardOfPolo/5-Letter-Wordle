#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include "wordle.hpp"
using namespace std;

int main(){
    /*
    1. Make a txt file of 5 letter words
    2. Read the txt file and store the words in a vector
    3. Randomly select a word from the vector
    4. Ask the user to input a 5 letter word 
    5. Check if the word is in the list
    6. If not then show the user green, yellow, and gray boxes on each letter
        Green = correct letter in correct position
        Yellow = correct letter in wrong position
        Gray = letter not in word
    7. Dont have words with repeated letters 
    Green: show letters that are green
    Yellow: show letters that are yellow
    Gray: show letters that are gray
    8. User only has 6 tries to guess the word
    9. if the user didnt guess correctly in 6 tries then show the correct word
    10. Ask if the user wants to play again
    11. If yes then repeat from step 3
    12. If no then exit the program
    *
    */
    ifstream FS;
    FS.open("5LetterWords.txt");
    
    if(FS.fail()){
        cout << "Invalid file" << endl;
        return 0;
    }

    string word;
    int totalWordNum = 0;
    vector<string> list;

    while(FS >> word){
        list.push_back(word);
        totalWordNum++;
    }

    srand(time(0));
    int totalTries = 6;
    string response;
    int randomWord = rand() % totalWordNum;
    word = list.at(randomWord);
    
    cout << "Welcome to 5 letter Wordle!" << endl;
    while(totalTries > 0){
        cout << "Input a 5 letter word (only lowercase): ";
        cin >> response;
        wordle word;
        word.guessingWord(response, list);
    }

    FS.close();
    
    return 0;
}