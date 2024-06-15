// 1337 transcript to russia
// 15.06.2024

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isRunning = true;
map<char, string> alphavet {{'a',"4"},{'b',"13"},{'c',"("},{'d',"[)"},
	{'e',"3"},{'f',"|="},{'g',"6"},{'h',"|-|"},{'i',"|"},{'j',"]"},{'k',"|<"},
	{'l',"1"},{'m',"|Y|"},{'n',"|/|"},{'o',"0"},{'p',"|>"},{'q',"0,"},{'r',"|2"},
	{'s',"5"},{'t',"7"},{'u',"[_]"},{'v',"√"},{'W',"vv"},{'x',"}{"}, {'y',"`/"},
	{'z',"2"},{' '," "}};

void hello_page(){
	cout << "----------------------------------------------------"<<endl;
	cout << "            Welcome to the 1337 transcript"<<endl;
	cout << "                 enter your message"<<endl;
	cout << "              autor: @812secondsToOff"<<endl;
	cout << "----------------------------------------------------"<<endl;			
}

string input2leet(string input){
	string output="";
	for(char ch : input){
		if(alphavet.count(ch)!=0)
			output+=alphavet[ch];
		else 
			throw 1;
	}
	return output;
}

int main(int argc, char const *argv[])
{
	hello_page();
	string input, output;
	while(isRunning){
		cout<<"request: ";
		cin>>input;
		try{
			output = input2leet(input);
		}
		catch(int code){
			cout << "error: unknown letter!"<<endl;
		}
		cout << output <<endl;;

	}
	return 0;
}