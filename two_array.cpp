#include <iostream>
#include <string.h>
struct Foo{
	char name[10][20];
};


int main(int argc,char* argv[]){
	Foo f;
	for(int i = 0;i<10;i++){
		//std::cout << strlen(f.name[i]) << std::endl;	
	}
}
