#include "unscramble.h"

using std::vector;      using std::string;
using std::cout;

string unscramble(const vector<string> words, string scram)
{
    /* ****GAME PLAN****
     * Identify size of every word in words *
     * Identify size of scram
     * Compare scram only to words of same size
     * Identify letters in scram
     * Eliminate words from words that have letters not in scram
     * Set scram to the found match */

    vector<string> rightLength;

    // makes a vector consisting of only the words that match scram in length
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter) {
        if (iter->length() == scram.length()) {
            rightLength.push_back(*iter);
        }
    }

    vector<string>::const_iterator iter = rightLength.begin();
    // eliminates words with different letters than scram.
    // necessary to do a while loop because we will be erasing iterators
    while(iter != rightLength.end()) {

        /*GAME PLAN: take first letter of scram, compare to each letter of iter
                   if matches go to next letter of scram, repeat for all of scram letters
                   if not a match is found erase word from rightLength and go to next word */


        // authorization vector, all chars must be y or rightLength gets erased more on this later
        vector<char> auth(iter->size(), ' ');

        // cycle through letters of scram word
        for (int iter2 = 0; iter2 != scram.size(); ++iter2) {

            // cycle through letters of rightLength word
            for(string::const_iterator rightChar = iter->begin(); rightChar != iter->end()
                                                               && auth[iter2] != 'y'; ++rightChar) {
                // if the current letter of scram is equal to any letter within rightLength
                // then the auth corresponding to scram's letter position will be set to y
                // later, if all of auth is not made up of solely y's rightLength will be erased
                if (scram[iter2] == *rightChar)
                    auth[iter2] = 'y';
            }
        }

        // kill switch, tells us if we erase a word or not
        char kill = ' ';

        // check if all elements of auth are equal to y, if they are then this word has all
        // of the letters contained within scram
        for (vector<char>::const_iterator itAuth = auth.begin(); itAuth != auth.end(); ++itAuth) {

            if (*itAuth != 'y') {
                kill = 'y';
            }
        }

        // check to see what kill switch says
        if (kill == 'y')
            iter = rightLength.erase(iter);
        else
            ++iter;
    }

    /* Now we have isolated all of the words which possess all of the letters that the current scram word
     * has. But what about the words that have all of the letters the current scram word has in addition
     * to different letters the scram word doesn't have? We must check to see that the words left in rightLength
     * do not have any letters not in the scram word. */

    iter = rightLength.begin();

    while(iter != rightLength.end()) {

        // authorization vector, all chars must be y or rightLength gets erased more on this later
        vector<char> auth(iter->size(), ' ');

        int counter = 0;

        // cycle through letters of rightLength word
        for(string::const_iterator rightChar = iter->begin(); rightChar != iter->end(); ++rightChar) {


            // cycle through letters of scram word
            for (int iter2 = 0; iter2 != scram.size(); ++iter2) {

                // if the current letter of rightLength is equal to any letter within rightLength
                // then the auth corresponding to rightLength's letter position will be set to y
                // later, if all of auth is not made up of solely y's rightLength will be erased
                if (*rightChar == scram[iter2])
                    auth[counter] = 'y';
            }
            counter++;
        }

        // kill switch, tells us if we erase a word or not
        char kill = ' ';

        // check if all elements of auth are equal to y, if they are then this word has all
        // of the letters contained within scram
        for (vector<char>::const_iterator itAuth = auth.begin(); itAuth != auth.end(); ++itAuth) {

            if (*itAuth != 'y') {
                kill = 'y';
            }
        }

        // check to see what kill switch says
        if (kill == 'y')
            iter = rightLength.erase(iter);
        else
            ++iter;
    }

    return rightLength[0];
}
