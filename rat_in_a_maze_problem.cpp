#include <iostream>
#include <vector>
#include <string.h>

using namespace std; 

bool isSafe(int srcx, int srcy, int newx , int newy , int maze[][2] , int row, int col,vector<vector<bool>> &visited){
    if(
       (newx>=0 && newx<row) &&
       (newy>=0 && newy<col)&&
       (maze[newx][newy] == 1)&&
       (visited[newx][newy] == false)){
        return true;
        
    }
    else{
        return false;
    }

}

void printAllPath(int maze[][2],int col,int row, int srcx, int srcy,string&output , vector<vector<bool>> &visited){
    //base case 
    if(srcx==row-1 && srcy==col-1 ){
        //reached destination 
        cout<<output<<endl;
        return;
    }

    //1case solve karo baki recursion sambhal lega

    //up
    //path-closed ho
    //outofbound jane ki koshish kr rha hun
    //ek 2d array aur create karna hoga and check karo ki hum use already visit kr chuke hai??
    
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //mark visited
        //call recursion
         visited[newx][newy] = true;
         output.push_back('U');
        printAllPath(maze,row,col,newx,newy,output,visited);
        
        //backtracking
        //vapis aaoge to use not visited kr dena using backtracking
           output.pop_back();
           visited[newx][newy] = false;
    }


    //right
    newx = srcx;
    newy = srcy+1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //mark visited
        //call recursion
         visited[newx][newy] = true;
         output.push_back('R');
        printAllPath(maze,row,col,newx,newy,output,visited);
        //backtracking
        //vapis aaoge to use not visited kr dena using backtracking
           output.pop_back();
           visited[newx][newy] = false;
    }

    //down
    newx = srcx+1;
    newy = srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //mark visited
        //call recursion
         visited[newx][newy] = true;
         output.push_back('D');
        printAllPath(maze,row,col,newx,newy,output,visited);
        //backtracking
        //vapis aaoge to use not visited kr dena using backtracking
           output.pop_back();
           visited[newx][newy] = false;

    }

    //left
    newx = srcx;
    newy = srcy-1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //mark visited
        //call recursion
         visited[newx][newy] = true;
         output.push_back('L');
        printAllPath(maze,row,col,newx,newy,output,visited);
        //backtracking
        //vapis aaoge to use not visited kr dena using backtracking
           output.pop_back();
           visited[newx][newy] = false;
    }

}

int main(){

    int maze[2][2] = {
        {1,1},
        {1,1}
    };

    int row = 2;
    int col = 2;
    int srcx = 0;
    int srcy = 0;

    string output = "";

    //create a visited 2d array

    vector <vector <bool>> visited(row,vector<bool>(col,false));
    if(maze[0][0]==0){
        //means source ki posotion hi closed hai to 
        cout<<"NO path exist"<<endl;
    }
    else{
        visited[srcx][srcy] = true;
        printAllPath(maze,row,col,srcx,srcy,output,visited);


    }
}