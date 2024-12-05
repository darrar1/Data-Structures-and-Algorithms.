//Celestial Tower of Hanoi


#include <iostream>
#include <stack>
using namespace std;


void moveDisk(stack<int>& fromRod, stack<int>& toRod, string from, string to) {
    int disk = fromRod.top();
    fromRod.pop();
    toRod.push(disk);
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
}


void towerOfHanoi(int n, stack<int>& source, stack<int>& auxiliary, stack<int>& destination, string src, string aux, string dest) {
    if (n == 1) {
        moveDisk(source, destination, src, dest);
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary, src, dest, aux);
    
    moveDisk(source, destination, src, dest);
    
    towerOfHanoi(n - 1, auxiliary, source, destination, aux, src, dest);
}


int main() {
    int num_disks;
    
    cout << "Enter the number of disks: ";
    cin >> num_disks;
    
    stack<int> source, auxiliary, destination;


    for (int i = num_disks; i >= 1; i--) {
        source.push(i);
    }


    towerOfHanoi(num_disks, source, auxiliary, destination, "Source", "Auxiliary", "Destination");


    return 0;
}