#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class WhackAMole{
public:
    int score;
    int molesLeft;
    int attemptsLeft;
    char moleGrid[10][10];
    WhackAMole(int numAttempts){
        score=0;
        molesLeft=0;
        attemptsLeft=numAttempts;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                moleGrid[i][j]='*';
            }
        }
        randomlyPlaceMoles(10);
    }
    bool place(int x, int y){
        if(moleGrid[x][y]!='M'){
            moleGrid[x][y]='M';
            molesLeft++;
            return true;
        }
        return false;
    }
    void randomlyPlaceMoles(int numMoles){
        srand(time(0));
        for(int i=0;i<numMoles;){
            int x=rand()%10;
            int y=rand()%10;
            if(place(x, y)){
                i++;  
            }
        }
    }
    void whack(int x, int y){
        if(x>=0 && x<10 && y>=0 && y<10){
            if(moleGrid[x][y]=='M'){
                score++;
                moleGrid[x][y]='W'; 
                molesLeft--;
            }
			else{
                cout<<"No mole found at ("<<x<<", "<<y<<")!"<<endl;
            }
            attemptsLeft--;
        } 
		else{
            cout<<"Invalid coordinates! Try again!"<<endl;
        }
    }
    void printGridToUser(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(moleGrid[i][j]=='W'){
                	cout<<'W';  
				}
                else{
                	cout<<'*';
				}  
            }
        cout<<endl;
        }
    }
    void printGrid(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<moleGrid[i][j];
            }
            cout<<endl;
        }
    }
};

int main(){
    WhackAMole obj1(50);
    string name;
    int x, y;
    cout<<"WELCOME TO WHACK A MOLE GAME!!" << endl;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<endl;
    obj1.printGridToUser();
    while(obj1.attemptsLeft>0 && obj1.molesLeft>0){
        cout<<"Enter x and y coordinates to whack (or -1 -1 to give up): ";
        cin>>x>>y;
        if(x==-1 && y==-1){
            cout<<"You gave up... :(	 Here's the full grid:"<<endl;
            obj1.printGrid();
            return 0;
        }
        obj1.whack(x, y);
        cout<<"Score: "<<obj1.score<<", Moles Left: "<<obj1.molesLeft<<", Attempts Left: "<<obj1.attemptsLeft<<endl;
        obj1.printGridToUser();
    }
    if(obj1.molesLeft==0){
    	cout<<"Congratulations, "<<name <<"! You've whacked all the moles!"<<endl;
    	cout<<"HAVE A NICE DAY, "<<name<<"!			(:"<<endl;
	}
    else{
    	cout<<"Out of attempts! Game over. Final grid:"<<endl;
    	cout<<"HAVE A NICE DAY, "<<name<<"!			(:"<<endl;
	}
    obj1.printGrid();
    return 0;
}
