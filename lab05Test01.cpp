//edited by Sachen Sampath, cs32, 5/3/2020
#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  // A sample test.
  cout<<"addAllWords Test"<<endl;

  WordCount I;
  I.addAllWords("First Second Third ISTHIS-ANUMBER? it isn't ????");

  //getTotalWords
  ASSERT_EQUALS(6, I.getTotalWords());
  //getNumUniqueWords
  ASSERT_EQUALS(6, I.getNumUniqueWords());
  //getWordCount
  ASSERT_EQUALS(1, I.getWordCount("first"));

  I.addAllWords("First Second Third ");

  //getTotalWords
  ASSERT_EQUALS(9, I.getTotalWords());
  //getNumUniqueWords
  ASSERT_EQUALS(6, I.getNumUniqueWords());
  //getWordCount
  ASSERT_EQUALS(2, I.getWordCount("first"));

}
