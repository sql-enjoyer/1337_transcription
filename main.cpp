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
	default:
		cout << "error: unknown command!"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	hello_page();
	string input, output;
	while(isRunning){
		cout<< endl <<"request: ";
		getline(cin, input);

		if(input[0]==':') {
			commands(input);
			continue;
		}

		try{
			output = input2leet(input);
			cout << "leet: " << output << endl;
		}
		catch(int code){
			cout << "error: unknown letter!"<<endl;
		}

	}
	return 0;
}