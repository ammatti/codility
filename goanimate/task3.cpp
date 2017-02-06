/*
Usage of Priority Queue

1. given a character string 
2. count the occurrance of each character
3. return the most frequent character and the frequency

*/

#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

class CharCount {
public:
  char word;
  int count;
  CharCount() {
    word = '0';
    count = 0;
  }
};

struct CharCountCompare {
  friend bool operator> (CharCount a, CharCount b) {
    if (a.count >= b.count) {
      return true;
    } else {
      return false;
    }
  }
};

int main(){
  string str = "How are you today baby hahaha?";
  int max_frequent = 0, current_frequent = 0;
  char max_char = '0', current_char ='0';
  map<char, int> word_table;
  map<char, int>::iterator iter;
  map<char, int>::reverse_iterator iter_r;

  for (int i = 0; i < str.size(); ++i) {
    iter = word_table.find(str[i]);
    if (iter != word_table.end()) {
      // update counter
      iter->second = iter->second + 1;
    } else {
      // insert new item
      word_table.insert(make_pair(str[i],1));
    }
  }
  //traversal table
  for (iter = word_table.begin(); iter != word_table.end(); iter++){
        current_char = iter->first;
	current_frequent = iter->second;
        if(current_frequent > max_frequent){
                max_char = current_char;
		max_frequent = current_frequent;
	}
  }
  cout<<"max= "<<max_char<<", "<<max_frequent<<endl;
}
