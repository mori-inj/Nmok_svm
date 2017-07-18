#include <io.h>
#include "nmok_svm.h"

nmokSVM::nmokSVM(int class_num, int loop, int data_num, int test_num, int n, int kernel_mode, const wstring data_filepath) : multiSVM(class_num, loop, data_num, test_num, n, kernel_mode, data_filepath)
{
}

void nmokSVM::read_data()
{
	int training_num=0, testing_num=0;
	int game, turn, last_training_game[2];

	WCHAR txt_filename[1024];

	for(int i = 0; i < CLASS_NUM; i++)
	{
		training_num = 0;
		for(game = 0; training_num < DATA_NUM; game++)
		{
			for(turn = 1; training_num < DATA_NUM; turn++)
			{
				wsprintf(txt_filename,FILEPATH.c_str(), i, game, turn);
				if(_waccess(txt_filename, 6) == 0)
				{
					read_training_data(txt_filename, i*DATA_NUM + training_num++);
				}
				else
				{
					break;
				}
			}
			if(turn!=1)
			{
				printf("%d training game: %d\n",i,game);
				fflush(stdout);
			}
		}
		last_training_game[i] = game;
	}
	printf("input trainig done\n");
	fflush(stdout);



	for(int i = 0; i < CLASS_NUM; i++)
	{
		testing_num = 0;
		for(game = last_training_game[i]; testing_num < TEST_NUM; game++)
		{
			for(turn = 1; testing_num < TEST_NUM; turn++)
			{
				wsprintf(txt_filename,FILEPATH.c_str(), i, game, turn);
				if(_waccess(txt_filename, 6) == 0)
				{
					read_test_data(txt_filename, i*TEST_NUM + testing_num++);
				}
				else
				{
					break;
				}
			}
			if(turn!=1)
			{
				printf("%d testing game: %d\n",i,game);
				fflush(stdout);
			}
		}
	}

	printf("input test done\n");
	fflush(stdout);

	for(int i = 0; i < CLASS_NUM; i++)
	{
		svm[i].copy_training(X);
		svm[i].copy_test(T_X);
		svm[i].setY(i);
	}

}


void nmokSVM::read_training_data(WCHAR* filename, int ith)
{
	FILE* fp = _wfopen(filename, L"r");

	for(int i = 0; i < N; i++)
	{
		char temp;
		fscanf(fp, "%c", &temp);
		if(temp=='0')
			(*X)[ith].set(i, 0.0);
		else if(temp=='x')
			(*X)[ith].set(i, -1.0);
		else if(temp=='o')
			(*X)[ith].set(i, 1.0);
		else if(temp=='\n')
			i--;
	}
	fclose(fp);
}

void nmokSVM::read_test_data(WCHAR* filename, int ith)
{
	FILE* fp = _wfopen(filename,L"r");

	for(int i = 0; i < N; i++)
	{
		char temp;
		fscanf(fp, "%c", &temp);
		if(temp=='0')
			(*T_X)[ith].set(i, 0);
		else if(temp=='x')
			(*T_X)[ith].set(i, -1);
		else if(temp=='o')
			(*T_X)[ith].set(i, 1);
		else if(temp=='\n')
			i--;
	}

	fclose(fp);
}