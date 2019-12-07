//https://www.youtube.com/watch?v=wU6udHRIkcc

#include<bits/stdc++.h>
using namespace std;
void initialize(vector<int> &A){
    for(int i=0; i<A.size(); i++){
        A[i] = -1;//negative represents it's a parent and 1 is the value of nodes under this parent
    }
}
/*
bool find(vector<int> &A, int B, int C){//to check if 2 nodes belong to same tree or not
    if(A[B]==A[C]){
        return true;
    }
    return false;
}

void union(vector<int> &A, int B, int C){
    int new_parent = A[B];
    int old_parent = A[C];
    for(int i=0; i<A.size(); i++){
        if(A[i]==old_parent){
            A[i] = new_parent;
        }
    }

}
*/

/*int root(vector<int>&A, int i){
    while(A[i]>0){
        i = A[i];
    }
    return i;
}*/

bool find(vector<int> &A, int B, int C){//to check if 2 nodes belong to same tree or not
    if(root(B)==root(C)){
        return true;
    }
    return false;
}

int root(vector<int>&A, int i){
    while(A[i]>0){
        A[i] = A[A[i]];//to minimize the length by half
        i = A[i];
    }
    return i;
}

void union(vector<int> &A, int B, int C){
    int root_B = root(B);
    int root_C = root(C);
    if(abs(A[root_B])>abs(A[root_C])){
        A[root_B]+=A[C];
        A[C] = root_B;//update the parent of C
    }
    else{
        A[root_C]+=A[B];
        A[B] = root_C;
    }
}
int main(){

    return 0;
}