//Compute the 2-fold integral f (x, y) = x * x + y * y by the Monte Carlo method 
//Integration range: 0.5 <= x <= 1, 0 <= y <= 2x-1

#include <iostream>
#include <ctime>

using namespace std;

double f(double x, double y)
{
	return x*x + y*y;
}

double Integral(double(*f)(double, double))
{
	double a_x = 0.5, b_x = 1;
	double a_y = 0;
	int N;
	cout << "Enter N (num of points): ";
	cin >> N;
	double **points = new double*[N];
	for (int i = 0; i < N; i++)
	{
		points[i] = new double[2];
		points[i][0] = a_x + (double)rand() / RAND_MAX *(b_x - a_x);
		points[i][1] = a_y + (double)rand() / (RAND_MAX) * (2 * points[i][0] - 1 - a_y);
	}
	double I = 0;
	for (int i = 0; i < N; i++)
	{
		I += f(points[i][0], points[i][1]) / N * (b_x - a_x) * (2 * points[i][0] - 1 - a_y);
	}
	delete[]points;
	return I;
}

int main()
{
	srand(time(NULL));
	cout << Integral(f) << endl;
	system("pause");
	return 0;
}