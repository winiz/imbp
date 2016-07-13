#include <iostream>
#include <assert.h>     /* assert */
#include "BpTree.h"
using namespace std;

int main(int argc, char** argv)
{
    cout<<"hi"<<endl;
    BTreeNode haha(3,1);
    BpTree(3);
	assert(haha.prints() == 3);     //basic check 
}