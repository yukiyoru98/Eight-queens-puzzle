#include <iostream>
using namespace std;

int const queens = 7;//num of queens
int column[queens]={};//save which column is invalid
int diagonalLR[2*queens-1]={};//save which diagonal(left-up to right-down) is invalid
int diagonalRL[2*queens-1]={};//save which diagonal(right-up to left-down) is invalid
int map[queens]={};//save the positions used
int solutionCnt=1;//counter for all solutions
int solution[92][queens]={};//table of all solutions(40)

//recursive function
void putDwarf(int x){//put queen in row x
    
    if(x==queens){//all queens are placed
        //put the positions saved in map[] into solution table
        for(int i=0; i<queens; i++){
            solution[solutionCnt-1][i] = map[i];
        }
        solutionCnt++;
    }
    else{//not all queens are placed yet
        
        for(int j=0; j<queens; j++){
            if((column[j]==0)&&(diagonalLR[x-j+(queens-1)]==0)&&(diagonalRL[x+j]==0)){//this position is valid
                
                map[x] = j;//put the queen for row x in column j
                column[j] = 1;//invalidate column j
                diagonalLR[x-j+(queens-1)] = 1;//invalidate diagonalLR
                diagonalRL[x+j] = 1;//invalidate diagonalRL
                
                putDwarf(x+1);//place the queen for the next row
                
                //reach here if there is no solution for the particular method
                //undo the current step
                map[x] = 0;
                column[j] = 0;
                diagonalLR[x-j+(queens-1)] = 0;
                diagonalRL[x+j] = 0;
            }
            
        }
    }
}

int main(){
    int m;//user input row
    int n;//user input column
    
    putDwarf(0);//create solution table
    
    //prompt for input
    cout << "The first queen's position is [m][n],\nPlease enter m=";
    cin >> m;
    
    while((m<0)||(m>=queens)){
        cout << "Invalid input! Please try again:";
        cin >> m;
    }
    
    cout << "n=";
    cin >> n;
    while((n<0)||(n>=queens)){
        cout << "Invalid input! Please try again:";
        cin >> n;
    }
    
    int solCnt=1;//the no. for solutions
    
    //search for solutions from table and print it
    for(int i=0; i<40; i++){
        for(int j=0; j<queens; j++){
            if(j==m){
                if(solution[i][j]==n){
                    cout << "Solution" << solCnt << endl;
                    for(int k=0; k<queens; k++){
                        cout << solution[i][k] << ",";
                    }
                    cout << endl;
                    solCnt++;
                }
            }
        }
    }
    system("pause");
    return 0;
}


