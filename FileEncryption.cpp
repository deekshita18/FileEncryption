#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;


int main(){

    system("CLS");
    fstream inputFile,encodedFile;

    inputFile.open("data.txt",ios::in);

    encodedFile.open("encoded.txt",ios::in | ios::out);

    int p = 47 , q = 53;
    int n = p*q;
    int t = (p-1)*(q-1);

    int e =0 , d=0;

    for(int i=2; i<t; i++){
        if ( __gcd(i,t) == 1 && __gcd(i,n)==1){
            e = i;            
        }
        if(e>100){
            break;
        }
        
    }

    // File encryption 
    if(inputFile.is_open()){
        string line;
         char ch;
         
         while(inputFile.good()){  //good bit , eos set or not 
        
        getline(inputFile,line);
    
        for(int i=0 ; i<line.length() ; i++){
                ch= line[i];
                long double x = pow(int(ch),e);
                long double enc = fmod(x,n);
                encodedFile<<enc;
        }
        encodedFile<<endl;
        }
    inputFile.close(); 
    encodedFile.close();

    }       

    return 0;
}