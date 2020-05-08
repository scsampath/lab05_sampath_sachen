//edited by Sachen Sampath, cs32, 5/8/2020
#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

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

  WordCount I1;
  I1.addAllWords("");
  //getTotalWords
  ASSERT_EQUALS(0, I1.getTotalWords());
  //getNumUniqueWords
  ASSERT_EQUALS(0, I1.getNumUniqueWords());
  //getWordCount
  ASSERT_EQUALS(0, I1.getWordCount("first"));
  I1.addAllWords(" hey this is a completely good sentence");
  //getTotalWords
  ASSERT_EQUALS(7, I1.getTotalWords());
  //getNumUniqueWords
  ASSERT_EQUALS(7, I1.getNumUniqueWords());
  //getWordCount
  ASSERT_EQUALS(1, I1.getWordCount("hey"));
  I1.addAllWords("hey this is not a completely good sentence ??? ");
  //getTotalWords
  ASSERT_EQUALS(15, I1.getTotalWords());
  //getNumUniqueWords
  ASSERT_EQUALS(8, I1.getNumUniqueWords());
  //getWordCount
  ASSERT_EQUALS(2, I1.getWordCount("hey"));

}
