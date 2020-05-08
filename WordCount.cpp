// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {
	for (size_t i = 0; i < CAPACITY; i++) {
    	table[i] = vector<pair<string, int>>();
  	}
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int count = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			count += table[i].at(j).second;
		}
	}
	return count;
}

int WordCount::getNumUniqueWords() const {
	int count = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			count++;
		}
	}
	return count;
}

int WordCount::getWordCount(std::string word) const {
	std::string validWord = makeValidWord(word);
	size_t index = hash(validWord);
	int count = 0;
	for(size_t i = 0; i < table[index].size(); i++){
		if(validWord == table[index].at(i).first){
			count = table[index].at(i).second;
		}
	} 
	return count;
}
	
int WordCount::incrWordCount(std::string word) {
	std::string insertWord = makeValidWord(word);
	//empty string
	if(insertWord == ""){
		return 0;
	}
	//checking if word exists
	size_t index = hash(insertWord);
	for(size_t i = 0; i < table[index].size(); i++){
		//if exists then increment
		if(insertWord == table[index].at(i).first){
			table[index].at(i).second++;
			return table[index].at(i).second;
		}
	} 
	//word doesnt exist so creating new word
	pair<string, int> item(insertWord, 1); 
	table[index].push_back(item);
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	std::string insertWord = makeValidWord(word);
	//empty string
	if(insertWord == ""){
		return -1;
	}

	//checking if word exists
	size_t index = hash(insertWord);
	for(size_t i = 0; i < table[index].size(); i++){
		//if exists check cases
		if(insertWord == table[index].at(i).first){
			if(table[index].at(i).second > 1){
				table[index].at(i).second--;
				return table[index].at(i).second;
			}
			else if(table[index].at(i).second == 1){
				table[index].erase(table[index].begin()+i);
				return 0;
			}
		}
	} 
	//word doesnt exist
	return -1;
}


bool WordCount::isWordChar(char c) {
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
		return true;
	}
	return false;
}

std::string WordCount::makeValidWord(std::string word) {
	std::string validWord = "";
	for(size_t i = 0; i < word.size(); i++){
		char c = word.at(i);
		if(isWordChar(c)){
			if (c >= 'A' && c <= 'Z'){
                c += 32;
            }
			validWord += c;
		}
		else{
			if(c == '-' || c == 39){
				if(validWord.size() > 0){
					bool exists = false;
                    for(size_t j = i; j < word.size(); j++){
                        if(isWordChar(word.at(j))){
                            exists = true;
                        }
                    }
                    if(exists){
                        validWord += c;
                    }
				}
			}
		}
	}
	return validWord;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<std::pair<std::string, int>> occurance;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			occurance.push_back(table[i].at(j));
		}
	}
	if(occurance.size() > 0)
	{
		while(occurance.size() != 0){
			size_t index = 0;
			int occur = occurance.at(0).second;
			string word = occurance.at(0).first;
			for(size_t i = 0; i < occurance.size(); i++){
				if(word < occurance.at(i).first){
					index = i;
					occur = occurance.at(i).second;
					word = occurance.at(i).first;
				}
			}
			occurance.erase(occurance.begin() + index);
			out << word << "," << occur;
			if(occurance.size() != 0){
				out<<"\n";
			}
		}
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const{
	std::vector<std::pair<std::string, int>> occurance;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			occurance.push_back(table[i].at(j));
		}
	}
	if(occurance.size() > 0)
	{
		while(occurance.size() != 0){
			size_t index = 0;
			int maxOccurance = occurance.at(0).second;
			string word = occurance.at(0).first;
			for(size_t i = 0; i < occurance.size(); i++){
				if(maxOccurance > occurance.at(i).second){
					index = i;
					maxOccurance = occurance.at(i).second;
					word = occurance.at(i).first;
				}
				else if(maxOccurance == occurance.at(i).second){
					if(word > occurance.at(i).first){
						index = i;
						maxOccurance = occurance.at(i).second;
						word = occurance.at(i).first;
					}
				}
			}
			occurance.erase(occurance.begin() + index);
			out << word << "," << maxOccurance;
			if(occurance.size() != 0){
				out<<"\n";
			}
		}
	}
}

void WordCount::addAllWords(std::string text) {
  int front = 0;
  for(size_t i = 0; i < text.size(); i++){
    if(text.at(i) == ' ' || text.at(i) == '\n' || text.at(i) == '\t'){
		std::string word = text.substr(front, i - front);
		std::string validWord = makeValidWord(word);
		incrWordCount(validWord);
		front = i + 1;
	}
	else if(i == text.size() - 1){
		std::string word = text.substr(front, (i + 1) - front);
		std::string validWord = makeValidWord(word);
		incrWordCount(validWord);
	}
  }
}
