// 1337 translate to russia
// 15.06.2024

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isRunning = true;
char state = 'l';
int length;
map<char, string> alphavet {{'a',"4"},{'b',"|3"},{'c',"("},{'d',"[)"},
	{'e',"3"},{'f',"|="},{'g',"6"},{'h',"|-|"},{'i',";"},{'j',"]"},{'k',"|<"},
	{'l',"1"},{'m',"|Y|"},{'n',"|/|"},{'o',"0"},{'p',"|>"},{'q',"0,"},{'r',"|2"},
	{'s',"5"},{'t',"7"},{'u',"[_]"},{'v',"^"},{'w',"vv"},{'x',"}{"}, {'y',"`/"},
	{'z',"2"},{' '," "}};

void hello_page(){
	cout << "----------------------------------------------------"<<endl;
	cout << "            Welcome to the 1337 translator"<<endl;
	cout << "                 enter your message"<<endl;
	cout << "              autor: @812secondsToOff"<<endl;
	cout << "                   use :h for help"<<endl;
	cout << "----------------------------------------------------"<<endl;			
}

void help_page(){
	cout << endl;
	cout << "----------------------------------------------------"<<endl;
	cout << "               Before each command put - ':'" << endl;
	cout << "           COMMAND                MEANING" << endl << endl;
	cout << "             :a                   alphavet" << endl;
	cout << "             :b                   hello page" << endl;	
	cout << "             :h                   help page" << endl;
	cout << "             :q                     quit" << endl;
	cout << "             ???                     ???" << endl;
	cout << "----------------------------------------------------"<<endl;
}

void alphavet_print(){
	cout << endl << "----------------------------------------------------"<<endl;
	cout << "                    1337 ALPHAVET" << endl;
	int count = 0;
	cout<<endl<<"        ";
	for (auto pair : alphavet){
		cout << pair.first << " : " << pair.second;
		for(int space=0; space<7-pair.second.length(); ++space) cout<<' ';
		++count;
		if(count!=4) continue;
		count = 0;
		cout<<endl<<"        ";
	}
	cout << endl << "----------------------------------------------------"<<endl;
}

void commands(string input){
	switch(input[1]){
	case 'q': 
		isRunning=false;
		break;
	case 'h':
		help_page();
		break;
	case 'a':
		alphavet_print();
		break;
	case 'b':
		hello_page();
		break;
	case 's':{
		cout << "system: state changed to string"<<endl;
		state = 's';
		break;
	}
	case 'l':{
		cout << "system: state changed to leet"<<endl;
		state = 'l';
		break; 
	}
	case '8':
		cout<<endl<<"https://www.youtube.com/watch?v=fKxZtiU6NHI"<<endl;
		break;
	default:
		throw 3;
	}
}

char find(char ch, int x){
	for (auto pair : alphavet){
		if(pair.second[x] == ch) {
			length = pair.second.length();
			return pair.first;
		}
	}
	throw 2;
}

// map<char, string> alphavet {{'a',"4"},{'b',"|3"},{'c',"("},{'d',"[)"},
// 	{'e',"3"},{'f',"|="},{'g',"6"},{'h',"|-|"},{'i',";"},{'j',"]"},{'k',"|<"},
// 	{'l',"1"},{'m',"|Y|"},{'n',"|/|"},{'o',"0"},{'p',"|>"},{'q',"0,"},{'r',"|2"},
// 	{'s',"5"},{'t',"7"},{'u',"[_]"},{'v',"^"},{'w',"vv"},{'x',"}{"}, {'y',"`/"},
// 	{'z',"2"},{' '," "}};

//[ | 1 0
string leet2string(string input){
	string output="";
	for(int i=0; i<input.size(); ++i){
		switch(input[i]){
		case '4': case '(': case '3': case '6': case ';': case ']': case '5': case '1':
		case '7': case '^': case 'v': case '}': case '`': case '2': case ' ':{
			output += find(input[i], 0);
			i += length-1;
			break;
			}
		case '[': case '|': case '0':{
			output += find(input[i+1], 1);
			i +=length-1;
			break;
			}
		default: throw 2;
		}
	}
	return output;
}

string string2leet(string input){
	string output="";
	for(char ch : input){
		if(alphavet.count(ch)!=0) output+=alphavet[ch];
		else throw 1;
	}
	return output;
}

int main(int argc, char const *argv[])
{
	hello_page();
	string input, output;
	while(isRunning){
		try{
			switch(state){
			case 's': {
				cout<< endl <<"string: ";
				getline(cin, input);
				if(input[0]==':') {
					commands(input);
					continue;
				}
				output = string2leet(input);
				cout << "leet: " << output << endl;
				break;			
				}
			case 'l': {
				cout<< endl <<"leet: ";
				getline(cin, input);
				if(input[0]==':') {
					commands(input);
					continue;
				}
				output = leet2string(input);
				cout<< "string: "<<output<<endl;
				break;
				}
			}
		}catch(int code){
			switch(code){
			case 1: 
				cout << "error: unknown letter!"<<endl;
				break;
			case 2:
				cout << "error: unknown symbol!"<<endl;
				break;
			case 3:
				cout << "error: unknown command!"<<endl;
				break;
			}
		}
	}
	return 0;
}