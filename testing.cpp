#include <iostream>

using namespace std;

void addAllWords(std::string text) {
  int front = 0;
  //example first second
  for(int i = 0; i < text.size(); i++){
    if(text.at(i) == ' ' || text.at(i) == '\n' || text.at(i) == '\t'){
		std::string word = text.substr(front, i - front);
        cout<<"Word = "<<word<<endl;
		front = i + 1;
	}
    else if(i == text.size() - 1){
        std::string word = text.substr(front, (i + 1) - front);
        cout<<"Word = "<<word<<endl;
    }
  }
}

int main(){
    string word = "example frist second ";
    addAllWords(word);

    string word2 = size_t();
    cout<<word2<<endl;
}
