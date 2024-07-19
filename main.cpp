#include <stdio.h>
#include <iostream>
#include <string.h>
#include <chrono>

//#include <>

int main() {

	std::string a(100000, 'a');
	//Object o;

	std::chrono::system_clock::time_point start1, end1;
	std::chrono::system_clock::time_point start2, end2;

	//計測スタート
	start1 = std::chrono::system_clock::now();
	//間に計算したい処理(コピー)
	std::string b = a;
	//計測ゴール
	end1 = std::chrono::system_clock::now();
	

	//計測スタート
	start2 = std::chrono::system_clock::now();
	//間に計算したい処理(移動)
	std::string c = std::move(a);
	//計測ゴール
	end2 = std::chrono::system_clock::now();


	//処理に使った時間を求める
	auto time1 = end1 - start1;
	auto time2 = end2 - start2;

	//時間をマイクロ秒に変換
	auto m1 = std::chrono::duration_cast<std::chrono::microseconds>(time1).count();
	auto m2 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();
	
	//出力
	std::cout << "100,000文字をコピーと移動で比較しました" << std::endl;
	std::cout <<"コピー " << m1 << "μs" << std::endl;
	std::cout <<"移動 " << m2 << "μs" << std::endl;

	//printf("コピー%d\n",a);
	//printf("移動%d\n", a);

	return 0;
}

