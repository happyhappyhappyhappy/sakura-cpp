#include<iostream>
#include<map>
#include<string>
#include<iterator>

using namespace std;

int main(void){
    map<string,int> mapOfWords;
    mapOfWords.insert(make_pair("earth",1));
    mapOfWords.insert(make_pair("moon",2));
    mapOfWords["sun"] = 3;
    mapOfWords["earth"]=4;
    map<string,int>::iterator it=mapOfWords.begin();
    while(it != mapOfWords.end()){
        cout<< it->first << " :: " << it->second << "\n";
        it++;
    }
/**    
       if(mapOfWords.insert(make_pair("earth", 1)).second == false){
        cout << "'earth'はすでに存在しています" << "\n";
       }
**/
    if(mapOfWords.insert(make_pair("earth",1)).second == false){
        cout << "'earth'はすでに存在しています\n";
    }
    cout << "sunを消す前の個数 :: " <<  mapOfWords.size() << "\n";
    if(mapOfWords.find("sun") != mapOfWords.end()){
        cout << "'sun'はmapOfWordに存在しています\n";
        mapOfWords.erase("sun");
    }
    if(mapOfWords.find("mars") == mapOfWords.end()){
        cout << "'mars'は存在していません\n";
    }
    cout << "sunを消したあとの個数 :: " <<  mapOfWords.size() << "\n";
    return 0;
}