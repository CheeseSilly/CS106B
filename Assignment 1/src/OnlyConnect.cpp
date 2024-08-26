/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

string helper(string phrase,int index){
    if(index>=phrase.length()){
        return "";
    }
    string answer;
    if(phrase[index]>=97&&phrase[index]<=122){
        if(phrase[index]!=97&&phrase[index]!=101&&phrase[index]!=105&&phrase[index]!=111&&phrase[index]!=117){
            answer+=toUpperCase(phrase[index]);
        }
    }
    else if(phrase[index]>=65&&phrase[index]<=90){
        if(phrase[index]!=65&&phrase[index]!=69&&phrase[index]!=73&&phrase[index]!=79&&phrase[index]!=85){
            answer+=phrase[index];
        }
    }
    return answer+helper(phrase,index+1);
}


string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    int index=0;
    return helper(phrase,index);
}







/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

STUDENT_TEST("description of the test") {
    /* Put your testing code here. */
    EXPECT_EQUAL(onlyConnectize("low@e3rc42!a#se"), "LWRCS");
}






