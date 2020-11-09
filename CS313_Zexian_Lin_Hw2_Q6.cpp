// CS313_Zexian_Lin_Hw2_Q6.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

//6. Use a stack to pass in a string and reverse each word in the string.For instance, if you
//have the string “When Chuck Norris falls in water, Chuck Norris doesn't get wet. Water
//gets Chuck Norris.” It should now say, “nehW kcuhC sirroN sllaf ni retaw, …” That is, it
//should take in one stringand be a function(or multiple functions) that use a stack(or
//multiple stacks) to reverse each word in the sentence.Create a text file that you input of
//Chuck Norris jokesand have the program reverse each of the jokes.

//Algorithm:
//reverse_word() will reverse the take in string, we assume it is a word instead of a senntence.
//reverse_word() will use a char stack to stock every character in the string, and then use another empty
//string res to store every character that is on the top of the stack, then pop the character we have stored.
//Since stack is FILO, the res string we get is the reverse of the original string.
//
//reverse() will take two strings that represents the input and output filename we are going to read and write.
//Instead of reading the file word by word, we read the file line by line. 
//We split the line by space, then use the reverse_word() to reverse every word we split and write it to the
//output file. 

string reverse_word(string s);
string reverse(string input, string output);


int main()
{
    string input_file = "Chuck_Norris_jokes.txt";
    string output_file = "Q6_output.txt";

    cout << "The text in the input file are: " << endl;
    string s = reverse(input_file, output_file);
    cout << endl;
    cout << "Open output file to see Reverse sentences! " << endl;
    cout << s;
    
}

string reverse_word(string s) {
    stack <char> chars;
    string res = "";
    string symbol = "";
    for (int i = 0; i < s.size(); i++) {
        //if the end of the word has a symbol, we should add it to the end of the result even we 
        //reverse other characters.
        if (i == s.size() - 1 && (s.at(i) == '.' || s.at(i) == ','
            || s.at(i) == '?' || s.at(i) == '!' || s.at(i) == ';')) {

            symbol += s.at(i);

        }
        else {
            chars.push(s.at(i));
        }

    }

    while (!chars.empty()) {
        res += chars.top();
        chars.pop();
    }
    return res + symbol;
}

string reverse(string input, string output) {
    ifstream ifs(input);
    //check if the input file exists.
    if (!ifs.is_open()) {
        return "No such a file!";
    }

    ofstream out(output);

    string line;
    string res = "";

    while (true) {
        //get the whole line of and print the original message.
        getline(ifs, line);
        cout << line << endl;

        string word = "";
        //split a sentence by space.
        for (auto x : line) {
            if (x == ' ')
            {
                out << reverse_word(word) << " ";
                // set word to an empty string in order to store new word.
                word = "";
            }
            else
            {   
                //store characters into word as long as it is not a space
                word = word + x;
            }

        }
        // The last word in the sentence should add to result.
        out << reverse_word(word) << endl;
        //reach end of the file, stop the while loop
        if (ifs.eof() == true) {
            break;
        }
    }

    ifs.close();
    out.close();
    return res;

}

//Read the input file and output a string.
//string reverse(string filename) {
//    ifstream ifs(filename);
//    if (!ifs.is_open()) {
//        return "No such a file!";
//    }
//
//    string line;
//    string res = "";
//
//    while (true) {
//        //get the whole line of and print the original message.
//        getline(ifs, line);
//        cout << line << endl;
//
//        string word = "";
//        //split a sentence by space.
//        for (auto x : line) {
//            if (x == ' ')
//            {
//                res += reverse_word(word);
//                res += " ";
//                // set word to an empty string in order to store new word.
//                word = "";
//            }
//            else
//            {
//                word = word + x;
//            }
//
//        }
//        // The last word in the sentence should add to result.
//        res += reverse_word(word);
//        // view result line by line.
//        res += "\n";
//        //reach end of the file, stop the while loop
//        if (ifs.eof() == true) {
//            break;
//        }
//    }
//
//    ifs.close();
//    return res;
//}

