//edited by Sachen Sampath, cs32, 5/8/2020
#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  cout<<"dumpWordsSortedByWord Test"<<endl;

  WordCount I;
  I.addAllWords("Sentence is a sentence");
  ostringstream occurence0;
  I.dumpWordsSortedByWord(occurence0);
  std::string expectedSortedByOccurence = string("sentence,2") + "\n" 
  + string("is,1") + "\n" 
  + string("a,1");
  ASSERT_EQUALS(expectedSortedByOccurence,occurence0.str());

  WordCount I1;
  I1.addAllWords(" ????? %%%%% %?^#$#?# '-'-'-' ");
  ostringstream occurence1;
  I1.dumpWordsSortedByWord(occurence1);
  std::string expectedSortedByOccurence1 = "";
  ASSERT_EQUALS(expectedSortedByOccurence1,occurence1.str());

  WordCount I2;
  I2.addAllWords("Third Second SECONd FiRSt");
  ostringstream occurence2;
  I2.dumpWordsSortedByWord(occurence2);
  std::string expectedSortedByOccurence2 = string("third,1") + "\n" 
  + string("second,2") + "\n" 
  + string("first,1");
  ASSERT_EQUALS(expectedSortedByOccurence2,occurence2.str());

  WordCount I3;
  I3.addAllWords("");
  ostringstream occurence3;
  I3.dumpWordsSortedByWord(occurence3);
  std::string expectedSortedByOccurence3 = ""; 
  ASSERT_EQUALS(expectedSortedByOccurence3,occurence3.str());

  WordCount I4;
  I4.addAllWords(" a b c d e f g h i j k l ");
  ostringstream occurence4;
  I4.dumpWordsSortedByWord(occurence4);
  std::string expectedSortedByOccurence4 = string("l,1") + "\n" 
  + string("k,1") + "\n" 
  + string("j,1") + "\n"
  + string("i,1") + "\n"
  + string("h,1") + "\n"
  + string("g,1") + "\n"
  + string("f,1") + "\n"
  + string("e,1") + "\n"
  + string("d,1") + "\n"
  + string("c,1") + "\n"
  + string("b,1") + "\n"
  + string("a,1");
  ASSERT_EQUALS(expectedSortedByOccurence4,occurence4.str());


}
