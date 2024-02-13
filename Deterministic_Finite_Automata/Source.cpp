#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
set<char>Alphabets;
set<int>FinalStates;
vector<vector<int>>Transitions;
map<char, int>AlphabetsMapping;
int InitialState;

bool IsValid(string input) {
	for (int i = 0; i < input.size(); i++) {
		if (Alphabets.find(input[i]) == Alphabets.end())
			return false;
	}
	return true;
}
int StatePath(string input) {
	int CurrentState = InitialState;
	for (auto it : input) {
		CurrentState = Transitions[CurrentState][AlphabetsMapping[it]];
	}
	return CurrentState;
}
bool IsAccept(string input) {
	int FinalState = StatePath(input);
	if (FinalStates.find(FinalState) != FinalStates.end()) {
		return true;
	}
	return false;
}
string Suffix(int number) {
	if (number % 10 == 1 && number != 11)
		return "st";
	else if (number % 10 == 2 && number != 12)
		return "nd";
	else if (number % 10 == 3 && number != 13)
		return "rd";
	else
		return"th";
}
int main() {
	int StatesNumber;
	cout << "Please Enter Number Of States :\n";
	cin >> StatesNumber;
	cout << "The States Are Numbered From 1 To " << StatesNumber << ".\n\n";

	int AlphabetsNumber;
	cout << "Please Enter Number Of Alphabet :\n";
	cin >> AlphabetsNumber;
	cout << "Please Enter The Alphabets As Characters\n";
	for (int i = 0; i < AlphabetsNumber; i++) {
		char Alphabet;
		cout << "Please Enter The " << i + 1 << Suffix(i + 1) << " Alphabet : " << "\n";
		cin >> Alphabet;
		AlphabetsMapping[Alphabet] = i + 1;
		Alphabets.insert(Alphabet);
	}

	Transitions = vector<vector<int>>(StatesNumber + 1, vector<int>(AlphabetsNumber + 1));
	cout << "\nPlease Enter The Transitions For Each State : \n";
	for (int i = 1; i <= StatesNumber; i++) {
		for (auto it : Alphabets) {
			int State;
			cout << "State " << i << " At Alphabet " << it << " = ";
			cin >> State;
			Transitions[i][AlphabetsMapping[it]] = State;
		}
	}

	cout << "\nPlease Enter The Initial State :\n";
	cin >> InitialState;

	int finalStatesNumber;
	cout << "\nPlease Enter The Number Of Final States :\n";
	cin >> finalStatesNumber;
	for (int i = 0; i < finalStatesNumber; i++) {
		cout << "Please Enter The " << i + 1 << Suffix(i + 1) << " Final State : " << endl;
		int finalState; cin >> finalState;
		FinalStates.insert(finalState);
	}
	cout << "\nYour Machine Is Built Successfully\n\nPlease Enter Your String :\n\n";

	cin.ignore();
	string input;
	getline(cin, input);
	cout << "\n";
	if (IsValid(input)) {

		if (IsAccept(input))
			cout << "The String " << input << " Is Accepted By The Machine.\n";
		else
			cout << "The String " << input << " Is Rejected By The Machine.\n";
	}
	else {
		cout << "The String That You Entered Is Not Valid.\n";
	}
	return 0;
}