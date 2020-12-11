#include <iostream>
#include <string>

using namespace std;

void MoveSingleDisk(int src, int dst) {
    cout << "move from " << src << " to " << dst << endl;
}

void MoveTower(int n, int src, int dst, int tmp) {
    if (n > 0) {
        MoveTower(n-1, src, tmp, dst);  // move from src to tmp, use dst as tmp
        MoveSingleDisk(src, dst);
        MoveTower(n-1, tmp, dst, src);  // move from tmp to dst, use src as tmp
    }
}

int main() {
    MoveTower(4, 1, 2, 3);
	
	return 0;

}