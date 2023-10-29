#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
void OutputArray(double* arr, const int size);
void FillArrayRandomVal(double* arr, const int size, double start, double end);
int quantityOfPosElem(double* arr, const int size);
double Sum_after_zero(double* arr, const int size);
void RewritingArray(double*& array, int size);
int main()
{
	srand(unsigned (time(0)));
	double start_random, end_random;
	int sum = 0, quantity = 0, n;
	cout << "n: "; cin >> n;
	cout << "start of random : "; cin >> start_random;
	cout << "end of random : "; cin >> end_random;

	double* a = new double[n];
	FillArrayRandomVal(a, n, start_random, end_random);
	OutputArray(a, n);
	cout << "quantity of positive values: " << quantityOfPosElem(a, n)
		<< "\nsum after zero: " << Sum_after_zero(a, n) << endl;
	RewritingArray(a, n);
	OutputArray(a, n);
	delete[]a;
	return 0;
}
void FillArrayRandomVal(double* arr, const int size, double start, double end)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = start + (end - start) * ((double)rand()) / RAND_MAX;
	}
}
void OutputArray(double* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(12) << arr[i];
	}
	cout << endl;
}
int quantityOfPosElem(double* arr, const int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			counter++;
		}
	}
	return counter;
}
double Sum_after_zero(double* arr, const int size)
{
	int index;
	double sum = 0.;
	bool is_sum = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0.)
		{
			is_sum = true;
			index = i;
		}
		if (is_sum)
		{
			sum += arr[i];
		}
	}
	return sum;
}
void RewritingArray(double*& array, int size)
{
	double* array_result = new double [size];
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (int(array[i]) == 0)
		{
			array_result[counter++] = array[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (int(array[i]) != 0) 
		{
			array_result[counter++] = array[i];
		}
	}
	array = array_result;
}