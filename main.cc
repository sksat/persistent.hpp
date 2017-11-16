#include <iostream>
#include "persistent.hpp"

int g_var = 0;

int main(int argc, char **argv){
	using namespace std;
	perpetuate(g_var); // 永続化
	persistent::load(); // 永続変数をロード

	cout<<"g_var = "<<g_var<<endl;
	g_var++;

	persistent::save(); // 永続変数の保存

	return 0;
}
