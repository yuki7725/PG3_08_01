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

	//�v���X�^�[�g
	start1 = std::chrono::system_clock::now();
	//�ԂɌv�Z����������(�R�s�[)
	std::string b = a;
	//�v���S�[��
	end1 = std::chrono::system_clock::now();
	

	//�v���X�^�[�g
	start2 = std::chrono::system_clock::now();
	//�ԂɌv�Z����������(�ړ�)
	std::string c = std::move(a);
	//�v���S�[��
	end2 = std::chrono::system_clock::now();


	//�����Ɏg�������Ԃ����߂�
	auto time1 = end1 - start1;
	auto time2 = end2 - start2;

	//���Ԃ��}�C�N���b�ɕϊ�
	auto m1 = std::chrono::duration_cast<std::chrono::microseconds>(time1).count();
	auto m2 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();
	
	//�o��
	std::cout << "100,000�������R�s�[�ƈړ��Ŕ�r���܂���" << std::endl;
	std::cout <<"�R�s�[ " << m1 << "��s" << std::endl;
	std::cout <<"�ړ� " << m2 << "��s" << std::endl;

	//printf("�R�s�[%d\n",a);
	//printf("�ړ�%d\n", a);

	return 0;
}

