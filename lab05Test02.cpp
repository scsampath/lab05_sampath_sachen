//edited by Sachen Sampath, cs32, 5/8/2020
#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  cout<<"dumpWordsSortedByOccurence Test"<<endl;

  WordCount I;
  I.addAllWords("Sentence is a fun fun sentence");
  ostringstream occurence0;
  I.dumpWordsSortedByOccurence(occurence0);
  std::string expectedSortedByOccurence = string("a,1") + "\n" 
  + string("is,1") + "\n" 
  + string("fun,2") + "\n"
  + string("sentence,2");
  ASSERT_EQUALS(expectedSortedByOccurence,occurence0.str());

  WordCount I1;
  I1.addAllWords(" ????? %%%%% %?^#$#?# '-'-'-' ");
  ostringstream occurence1;
  I1.dumpWordsSortedByOccurence(occurence1);
  std::string expectedSortedByOccurence1 = "";
  ASSERT_EQUALS(expectedSortedByOccurence1,occurence1.str());

  WordCount I2;
  I2.addAllWords("Third third THird Second SECONd FiRSt");
  ostringstream occurence2;
  I2.dumpWordsSortedByOccurence(occurence2);
  std::string expectedSortedByOccurence2 = string("first,1") + "\n" 
  + string("second,2") + "\n" 
  + string("third,3");
  ASSERT_EQUALS(expectedSortedByOccurence2,occurence2.str());

  WordCount I3;
  I3.addAllWords("");
  ostringstream occurence3;
  I3.dumpWordsSortedByOccurence(occurence3);
  std::string expectedSortedByOccurence3 = ""; 
  ASSERT_EQUALS(expectedSortedByOccurence3,occurence3.str());

  WordCount I4;
  I4.addAllWords(" a b c d e f g h i j k l ");
  ostringstream occurence4;
  I4.dumpWordsSortedByOccurence(occurence4);
  std::string expectedSortedByOccurence4 = string("a,1") + "\n" 
  + string("b,1") + "\n" 
  + string("c,1") + "\n"
  + string("d,1") + "\n"
  + string("e,1") + "\n"
  + string("f,1") + "\n"
  + string("g,1") + "\n"
  + string("h,1") + "\n"
  + string("i,1") + "\n"
  + string("j,1") + "\n"
  + string("k,1") + "\n"
  + string("l,1");
  ASSERT_EQUALS(expectedSortedByOccurence4,occurence4.str());


}
