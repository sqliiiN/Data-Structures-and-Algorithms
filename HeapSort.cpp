//
//  main.cpp
//  Heapsort
//
//  Created on 2018/9/5.
//  Copyright © 2018年. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

void shiftdown(vector<int> &vec, int root, int num){
    
    int j, t;
    
    t = vec[root];
    
    // j值的改变
    while((j = 2*root + 1) < num){
        if(j+1 < num && vec[j+1] > vec[j]){
            j++;
        }
    
        if(vec[j] > t){
            vec[root] = vec[j];
            root = j;
        }
        else
            break;
    }
    // 在干吗？
    vec[root] = t;
}

void HeapSort(vector<int> &vec, int num){
    
    int i, t;
    
    for(i = (num-2)/2; i >= 0; i--){
        shiftdown(vec, i, num);
    }
    
    for(i = num-1; i > 0; i--){
        t = vec[i];
        vec[i] = vec[0];
        vec[0] = t;
        shiftdown(vec, 0, i);
    }
}

int main() {
    vector<int> vec;
    
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(0);
    
    HeapSort(vec, int(vec.size()));
    
    return 0;
}
