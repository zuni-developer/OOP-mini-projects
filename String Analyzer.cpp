#include<iostream>
using namespace std;

class MyString{
private:
    string mystring;

public:
    MyString(const string& str):mystring(str){}
    string getString()const{
        return mystring;
    }
    // Count vowels in the string
    int countVowels()const{
        int vowelCount=0;
        for(char ch:mystring){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                vowelCount++;
            }
        }
        return vowelCount;
    }
    // Count occurrences of a substring
    int countSubstring(const string& word)const{
        int count=0;
        size_t pos=mystring.find(word,0);
        while(pos!=string::npos){
            count++;
            pos=mystring.find(word,pos+1);
        }
        return count;
    }
    // Find the longest alphabetically ordered substring
    string longestAlphabeticalSubstring()const{
        string current,longest;
        for(size_t i=0;i<mystring.length();i++){
            if(i==0||mystring[i]>=mystring[i-1]){
                current+=mystring[i];
            }
			else{
                if(current.length()>longest.length()){
                    longest=current;
                }
                current=mystring[i];
            }
        }
        return(current.length()>longest.length())?current:longest;
    }
};

int main(){
    string input;
    cout<<"Enter a word: ";
    cin>>input;
    MyString userString(input);
    
    int choice;
    do{
        cout<<"\nChoose an option:"<<endl;
        cout<<"1. Count vowels"<<endl;
        cout<<"2. Find substring occurrences"<<endl;
        cout<<"3. Find longest alphabetical substring"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"Number of vowels: "<<userString.countVowels()<<endl;
                break;
            case 2:{
                string find;
                cout<<"Enter the word to find from the string: ";
                cin>>find;
                cout<<"The substring count is: "<<userString.countSubstring(find)<<endl;
                break;
            }
            case 3:
                cout<<"The longest alphabetically ordered substring is: "<<userString.longestAlphabeticalSubstring()<<endl;
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice, please try again."<<endl;
        }
    }while(choice!=4);
    
    return 0;
}

