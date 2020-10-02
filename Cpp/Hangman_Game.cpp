#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main(){
  string country_name[]={"China","India","United States","Indonesia","Pakistan","Brazil","Nigeria","Bangladesh","Russia","Mexico","Japan","Ethiopia","Philippines","Egypt","Vietnam","DR Congo","Turkey","Iran","Germany","Thailand","United Kingdom","France","Italy","Tanzania","South Africa","Myanmar","Kenya","South Korea","Colombia","Spain","Uganda","Argentina","Algeria","Sudan","Ukraine","Iraq","Afghanistan","Poland","Canada","Morocco","Saudi Arabia","Uzbekistan","Peru","Angola","Malaysia","Mozambique","Ghana","Yemen","Nepal","Venezuela","Madagascar","Cameroon","Côte d'Ivoire","North Korea","Australia","Niger","Sri Lanka","Burkina Faso","Mali","Romania","Malawi","Chile","Kazakhstan","Zambia","Guatemala","Ecuador","Syria","Netherlands","Senegal","Cambodia","Chad","Somalia","Zimbabwe","Guinea","Rwanda","Benin","Burundi","Tunisia","Bolivia","Belgium","Haiti","Cuba","South Sudan","Dominican Republic","Czech Republic (Czechia)","Greece","Jordan","Portugal","Azerbaijan","Sweden","Honduras","United Arab Emirates","Hungary","Tajikistan","Belarus","Austria","Papua New Guinea","Serbia","Israel","Switzerland","Togo","Sierra Leone","Laos","Paraguay","Bulgaria","Libya","Lebanon","Nicaragua","Kyrgyzstan","El Salvador","Turkmenistan","Singapore","Denmark","Finland","Congo","Slovakia","Norway","Oman","State of Palestine","Costa Rica","Liberia","Ireland","Central African Republic","New Zealand","Mauritania","Panama","Kuwait","Croatia","Moldova","Georgia","Eritrea","Uruguay","Bosnia and Herzegovina","Mongolia","Armenia","Jamaica","Qatar","Albania","Lithuania","Namibia","Gambia","Botswana","Gabon","Lesotho","North Macedonia","Slovenia","Guinea-Bissau","Latvia","Bahrain","Equatorial Guinea","Trinidad and Tobago","Estonia","Timor-Leste","Mauritius","Cyprus","Eswatini","Djibouti","Fiji","Comoros","Guyana","Bhutan","Solomon Islands","Montenegro","Luxembourg","Suriname","Cabo Verde","Maldives","Malta","Brunei","Belize","Bahamas","Iceland","Vanuatu","Barbados","Sao Tome & Principe","Samoa","Saint Lucia","Kiribati","Micronesia","Grenada","St. Vincent & Grenadines","Tonga","Seychelles","Antigua and Barbuda","Andorra","Dominica","Marshall Islands","Saint Kitts & Nevis","Monaco","Liechtenstein","San Marino","Palau","Tuvalu","Nauru","Holy See"};

  cout<<"Welcome to hangman..."<<"\n";
  cout<<"Guess the country name."<<"\n"<<"Each letter is represented by a star."<<"\n"<<"You have to type one letter in one try."<<"\n"<<"You have 5 tries to try and guess the name."<<"\n";
  while(1){
    char c;
    cout<<"\n Ready! Enter S to start and E to exit"<<"\n";
    cin>>c;
    if(c=='S' || c=='s'){
      int n;
      srand(time(NULL));
      n=rand()%(195);
      string s;
      s=country_name[n];
      int x=s.size(),guessed[x];
      cout<<"\n";
      for(int i=0;i<x;i++){
        if(isalpha(s[i])){
          cout<<"*";
          guessed[i]=0;
        }
        else{
          cout<<s[i];
          guessed[i]=1;
          x--;
        }
      }
      int tries=5;
      while(tries && x){
        char ch;
        bool correct=false;
        cout<<"\n"<<"Guess a letter"<<"\n";
        cin>>ch;
        cout<<"\n";
        for(int i=0;i<s.size();i++){
          if(tolower(s[i])==ch || toupper(s[i])==ch){
            cout<<s[i];
            correct=true;
            guessed[i]=1;
            x--;
          }
          else if(guessed[i]==1){
            cout<<s[i];
          }
          else{
            cout<<"*";
          }
        }
        cout<<"\n";
        if(correct==false){
          tries--;
          cout<<"Whopps! That letter isn't there"<<"\n"<<"You have "<<tries<<" guesses left."<<"\n";
        }
        else{
          tries++;
          cout<<"You have "<<tries<<" guesses left."<<"\n";
        }
      }
      if(x==0){
        cout<<"\n ****Yeah! You got it.****"<<"\n";
      }
      else if(tries==0){
        cout<<"\n ****Whopps! You lose.****"<<"\n"<<"It was "<<s;
      }
    }
    else{
      cout<<"\n Game ended"<<"\n";
      exit(0);
      }
    
  }

  return 0;
}