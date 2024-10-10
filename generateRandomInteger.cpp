#include <bits/stdc++.h>
using namespace std;

int main(){
    default_random_engine e;
    uniform_int_distribution<int> u(1,1e9);
    e.seed(time(0));

    ofstream of("data.txt");
    // vector<int> data(2e5);
    for(int i=0; i<2e5; i++){
        // data[i] = u(e);
        of << u(e) << endl;
    }
    of.close();
}