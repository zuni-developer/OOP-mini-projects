#include<iostream>
#include<fstream>
using namespace std;

class Strings{
    public:
    string value;
    Strings(string word){
        value=word;
    }
    string UpperCase(){
        for(int i=0;i<value.length();i++){
            value[i]=toupper(value[i]);
        }
        return value;
    }
    string LowerCase(){
        for(int i=0;i<value.length();i++){
            value[i]=tolower(value[i]);
        }
        return value;
    }
};

class Dog{
    public:
    string name, breed;
    int age;
    Strings barkSound, item;
    string favorite_foods[20];
    int foodCount;
    Dog(string nam, string bre, int ag, string bar):barkSound(bar),item(""),foodCount(0){
        name=nam;
        breed=bre;
        age=ag;
        loadFoods();
    }
    string bark(){
        return age<3 ? barkSound.LowerCase() : barkSound.UpperCase();
    }
    bool is_favorite_food(string food_item){
        item=food_item;
        food_item=item.LowerCase();
        for(int i=0; i<foodCount; i++){
            if(favorite_foods[i]==food_item){
                return true;
            }
        }
        return false;
    }
    void loadFoods(){
        ifstream file("foods.txt");
        string food;
        while(file>>food && foodCount<20){
            favorite_foods[foodCount++]=food;
        }
        file.close();
    }
    void addFavoriteFood(string new_food){
        if(foodCount<20){
            favorite_foods[foodCount++]=new_food;
            ofstream file("foods.txt", ios::app);
            file<<new_food<<endl;
            file.close();
            cout<<new_food<<" added to Smurffy's favorites!"<<endl;
        }
		else{
            cout<<"Food list is full!"<<endl;
        }
    }
    void play(){
        cout<<name<<" is playing happily!"<<endl;
    }
    void sleep(){
        cout<<name<<" is sleeping peacefully..."<<endl;
    }
};

int main(){
    string food;
    char choice;
    Dog obj1("Smurffy","Siberian Husky",5,"bark");
    cout<<" Dog Information "<<endl;
    cout<<"Name  : "<<obj1.name<<endl;
    cout<<"Breed : "<<obj1.breed<<endl;
    cout<<"Age   : "<<obj1.age<<" years old"<<endl;
    cout<<"Bark  : "<<obj1.bark()<<endl;
    cout<<"--------------------------"<<endl;
    do{
        cout<<"\nEnter a food to check if Smurffy likes it: ";
        cin>>food;
        if(obj1.is_favorite_food(food)){
            cout<<food<<" is one of Smurffy's favorite foods!"<<endl;
        } 
		else{
            cout<<food<<" is NOT one of Smurffy's favorite foods. Would you like to add it? (y/n): ";
            cin>>choice;
            if(choice=='y'||choice=='Y'){
                obj1.addFavoriteFood(food);
            }
        }
        cout<<"\nDo you want to check another food? (y/n): ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    cout<<"\nWant Smurffy to do something? (p=play, s=sleep, n=none): ";
    cin>>choice;
    if(choice=='p'||choice=='P'){
    	obj1.play();
	}
    else if(choice=='s'||choice=='S'){
    	obj1.sleep();
	}
    cout<<"\nThanks for playing! Have a great day!"<<endl;
    return 0;
}
