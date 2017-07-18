#include <stdio.h>
#include "nmok_svm.h"

#pragma warning(disable:4996)

#define BOARD_SIZE 19
using namespace std;


int main(void)
{
	const wstring filepath = L"//vmware-host/Shared Folders/Downloads/Nmok/%dwins/%05d_%04d.txt";
	static nmokSVM nmok_svm(2, 1000000, 5000, 2500, BOARD_SIZE*BOARD_SIZE, 1, filepath);
	nmok_svm.read_data();
	nmok_svm.init_kernel_matrix();
	nmok_svm.training((long double)1e-2);
	nmok_svm.testing();
	return 0;
}