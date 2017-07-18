#ifndef __NMOK_SVM__
#define __NMOK_SVM__

#include "multi_svm.h"

using namespace std;

class nmokSVM : public multiSVM
{
public:
	nmokSVM() {};
	nmokSVM(int class_num, int loop, int data_num, int test_num, int n, int kernel_mode, const wstring data_filepath);
	void read_data();
	void read_training_data(WCHAR* filename, int ith);
	void read_test_data(WCHAR* filename, int ith);
};

#endif