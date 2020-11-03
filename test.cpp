#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <time.h>
#include "tc_thread_queue.h"
#include <unistd.h>
//class A{
//public:
//        virtual void foo();
//        void bar(){this->foo();}
//};      
//
//void A::foo(){
//	printf("a");
//}
//
//
//class B:public A{
//        void foo() { printf("b");}
//};

class A{
public:
	virtual void foo(){ printf("a\n");}
	void bar(){foo();}
	void operator()()
	{
		while(true){
			std::cout<<"1" << std::endl;
			//sleep(2);
		}
	}	
};

class B:public A{
public:
	virtual void foo(){printf("b\n");}	
};


class Foo
{
public:
    Foo(){printf("Foo\n");}
    ~Foo(){printf("~Foo\n");}
};


union id53
{
	struct
	{
		unsigned int ts:32;
		unsigned int inc:16;
		unsigned int mid:5;
	};
	unsigned long long genid;
};	


int main(int argc,char* argv[]){
	//A b;
	//b.bar();
	//float f = atof("0");
	//printf("%d\n",0%3);
	//printf("%f\n",f);
	//B b;
	//b.bar();
	//A a;
	//a.detach();
	//try{
	//std::thread t(a);
	//t.detach();
	//}catch(std::exception& ex){
	//	std::cout << ex.what()<<std::endl;
	//}
	//while(true){
	//	sleep(2);
	//}
	//std::string strLine;
	//std::stringstream ssContent;	
    //std::ifstream in;
//    in.open("test.cpp", std::ios::in);
//
//        while (getline(in, strLine))
//        {
//            ssContent << strLine<<"#" << std::endl;
//        }

	//std::cout << ssContent.str()<<std::endl;
	//id53 id = {(unsigned int)time(NULL),1,1};
	//std::cout <<sizeof(id)<<" " <<id.genid << std::endl;
	//unsigned int a = 0;
	//unsigned int b = ~0;
	//std::cout << a << b << std::endl;
	//time_t tnow = time(NULL);
    //struct tm tm;
    //localtime_r(&tnow,&tm);
    //std::cout <<mktime(&tm) << std::endl;
    //tm.tm_hour = 0;
    //tm.tm_min = 0;
    //std::cout <<mktime(&tm) << std::endl;
    //tm.tm_mday = -1;
    //std::cout <<mktime(&tm) << std::endl;
	//struct timeval tv;
    //struct timezone tz;
    //gettimeofday(&tv,&tz);    
    //printf("%d\n",tz.tz_dsttime);
    //printf("%d\n",timezone);
    //printf("%s\n",getenv ("TZ"));
	//int x = 0;
	//int y = 0;
	printf("%hhu\n",(unsigned char)(-1));

	time_t t = 1597929478;
	double d = (double)t;
	std::cout.precision(9);
	std::cout << d << std::endl;
	tars::TC_ThreadQueue<int> que;
	que.push_back(1,true);

	std::thread th([&]{
		for(int i= 0;i<10000000;i++)
			que.push_back(i,true);
			
	});
	std::thread th1([&]{
		usleep(10*1000);
		int i = 0;
		while(que.pop_front(i,10))
			std::cout << i << std::endl;
			
	});
	//const Foo& f = getfoo();
	th.join();
	th1.join();
	return 0;
}
//
//
//
//sss
