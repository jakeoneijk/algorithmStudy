//
//  main.cpp
//  Line02
//
//  Created by Jakeone Im on 16/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <ctype.h>

using namespace std;
vector<string> chemicals;
vector<string> numbers;
int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    string chemical;
    chemical+= input[0];
    int i = 1;
    while (i <input.size()) {
        if(isdigit(input[i])){
            break;
        }
        if(isupper(input[i])){
            chemicals.push_back(chemical);
            chemical = "";
            chemical += input[i];
        }else{
            chemical+= input[i];
        }
        i++;
    }
    chemicals.push_back(chemical);
    string number;
    for(int j = i; j < input.size(); j++){
        if(input[j] == '0'){
            numbers[numbers.size()-1] = numbers[numbers.size()-1] + '0';
        }else{
            number = "";
            number += input[j];
            numbers.push_back(number);
        }
    }
    string result="";
    if(numbers.size() != chemicals.size()){
        cout<<"error"<<endl;
    }else{
        for(int k = 0; k < numbers.size(); k++){
            result += chemicals[k];
            if(numbers[k] != "1"){
                result += numbers[k];
            }
            
        }
        cout<<result<<endl;
    }
    
    return 0;
}
