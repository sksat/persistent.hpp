#include <iostream>
#include "persistent.hpp"

int g_var = 0;

int main(int argc, char **argv){
	using namespace std;

	char str[] = "hello"; // ポインタはダメ

	perpetuate(g_var); // 永続化
	perpetuate(str);

	persistent::load(); // 永続変数をロード

	cout<<"g_var = "<<g_var<<endl;
	cout<<"str = "<<str<<endl;
	g_var++;
	if(str[0] == ' ')
		str[0] = 'h';
	else
		str[0] = ' ';

	persistent::save(); // 永続変数の保存

	return 0;
}
