.PHONY:clean all clean_a
src = $(wildcard ./*.c) #��ȡ��ǰĿ¼�µ�����CԴ�ļ�
targetsc = $(patsubst %.c, %, $(src)) #����ģʽƥ�佫����������ضϳ�ָ����ʽ 
objc = $(patsubst %.c, %.o, $(src)) #���е������ļ��б�, ʹ�ÿո�ָ�
 
srcpp = $(wildcard ./*.cpp) #��ȡ��ǰĿ¼�µ�C++Դ�ļ�
targetscpp = $(patsubst %.cpp, %, $(srcpp)) #����ģʽƥ�佫����������ضϳ�ָ����ʽ 
objcpp = $(patsubst %.cpp, %.o, $(srcpp)) #���е������ļ��б�, ʹ�ÿո�ָ�
 
pp = g++
cc = g++
 
CPPFLAGS = -std=c++17 -g -O0 -DDBG -I./
CFLAGS = -lpthread #��Ҫһ���԰ѵ�ǰĿ¼������.cpp/.c�ļ������ɿ�ִ���ļ� ����Ҫ��������Ҫ���ӵĿ��ļ�����ӽ���
#Ҳ��ʹ�ö������,ʹ��������������Щ�⣡
 
#$(targetsc):%:%.o ��ʾ��Ҫ����make����Ҫʹ��gcc��������Ӳ���
 
ifeq ($(findstring .c, $(src)), .c)  
all:$(targetsc)
$(targetsc):%:%.o  
	$(cc)  $(CFLAGS) $< -o $@ 
$(objc):%.o:%.c
	$(cc) $(CPPFLAGS) -c $<
endif
 
#$(targetscpp):%:%.o ��ʾ��Ҫ����make����Ҫʹ��g++��������Ӳ���
ifeq ($(findstring .cpp, $(srcpp)), .cpp)
all:$(targetscpp)
$(targetscpp):%:%.o
	$(pp) $(CFLAGS) $< -o $@
$(objcpp):%.o:%.cpp
	$(pp) $(CPPFLAGS) -c $<
endif
 
clean:
	rm -rf $(objc) $(objcpp)
	rm -rf $(targetsc) $(targetscpp)
