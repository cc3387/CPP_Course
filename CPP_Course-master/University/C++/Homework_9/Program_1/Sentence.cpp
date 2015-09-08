#include <iostream>
#include <string>
using namespace std;

int main(){

char CapLetters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char Letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','y','v','w','x','y','z'};
char fullstop ='.';
char comma = ',';
int double_space = 0;


//Define string for the input
string Line;
//Define char array for the changes
char Line1[Line.length()];
cout << "Please enter the line that you want to evaluate: " <<endl;
getline(cin, Line);

for(int i = 0; i < Line.length(); i++){
Line1[i] = Line[i];
if(Line[i] == fullstop){
Line1[i] = fullstop;
}
}

for(int i = 0; i < Line.length(); i++){
   
   for(int j = 0; j < 26; j++){
   	//Defining scenarios when Capital letters replacement is needed
   if(i == 0 && Letters[j] == Line[0]){
   Line1[0] = CapLetters[j];
   }else if(i > 0 && Line[i] == CapLetters[j]){
   Line1[i] = Letters[j]; //Any capital letters in the middle of the sentence to be changed to normal letters.
   }else if(i > 0 && (Line[i]==fullstop && Line[i+1] == ' ') && Line[i+2] == Letters[j]){
   Line1[i+2] = CapLetters[j];
   }
   }

   //Calculating double space if occured
   if(Line[i] == ' ' && Line[i+1] == ' ' ){
   double_space += 1;
   }
}

//Moving double space to single space

int blank_space = 0;
char Line_final[Line.length() - double_space + 1];

for(int i = 0 ; i < Line.length() - double_space + 1; i++){
Line_final[i] = ' ';
}

for(int i=1; i < Line.length() + 1; i++){

if(Line1[i] ==' ' && Line1[i-1]==' '){
blank_space += 1;
}

if(Line1[i-1] != ' '){
Line_final[(i-1)-blank_space] = Line1[i-1];
}

}

//Showing the changes
cout<<"The transformed Line is: ";
for(int i=0; i < (Line.length() - double_space + 1);i++){
cout<<Line_final[i];
}

return 0;

}