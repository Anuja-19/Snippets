#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter any character: ";
    cin>>ch;
    if(ch=='A'||ch=='a'||ch=='E'||ch=='e'||ch=='I'||ch=='i'||ch=='O'||ch=='o'||ch=='U'||ch=='u')
        cout<<"You entered a vowel: "<<ch;
    else
        cout<<"You did not enter a vowel: "<<ch;
    return 0;
}
