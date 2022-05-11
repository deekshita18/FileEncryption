#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main(){

    fstream inputFile,outputFile;

    inputFile.open("data.txt",ios::in | ios::out);

    outputFile.open("encoded.txt",ios::in | ios::out);

    if(inputFile.is_open()){
        string line;
        char ch;
         while(inputFile.good()){  //good bit , eos set or not 
        
        getline(inputFile,line);

        for(int i=0 ; i<line.length() ; i++){
                ch=line[i];
                outputFile<<int(ch);
        }
        outputFile<<endl;
        
        }
    inputFile.close(); 
    outputFile.close();

    }       

    return 0;
}