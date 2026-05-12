#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main(){
    int count = 0; //used for exiting while loop
    ifstream inputlhs,inputrhs,inputres;
    string filenamelhs,filenamerhs,filenameres,outFile;
    ofstream output;
    while(true){ //loop for reading files and check with count if everything is fine after break
        cout<<"Enter LHS matrix filename: ";cin>>filenamelhs;
        cout<<"Enter RHS matrix filename: ";cin>>filenamerhs;
        cout<<"Enter RES matrix filename: ";cin>>filenameres;
        inputlhs.open(filenamelhs.c_str());inputrhs.open(filenamerhs.c_str());inputres.open(filenameres.c_str());
        if(!inputlhs.fail()){count++;}
        if(!inputrhs.fail()){count++;}
        if(!inputres.fail()){count++;}break;}
    cout<<"Enter output filename: ";cin>>outFile;
    output.open(outFile.c_str());
    if(count != 3){cout<<"Error!"<<endl;output<<"Error"<<endl;}
    else{ //also check here if the rows columns are okay then print error
        int num;
        while(inputlhs>>num){
            cout<<num<<endl;
        }
        
        
        
    }
    
    
    
    return 0;
}

/*
 ifstream input;
 string filename;
 cout<<"Enter the LHS matrix filename: ";
 cin>>filename;
 
 input.open(filename.c_str());
 
 int sentinel = 0;
 
 
 
 if(!input.fail()){
     cout<<"All good!"<<endl;
     
 }
 else{
     cout<<"Error!"<<endl;
 }
 
 
 ofstream output;
 string outFile;
 cout<<"Enter output filename: ";
 cin>>outFile;
 
 output.open(outFile.c_str());
 
 if(output.fail()){
     cout<<"Error"<<endl;
     
 }
 else{
     output<<1<<2<<3<<endl;
     output<<4<<5<<6<<endl;
 }

 */
