#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

int minval(int arr[], int n) {
	int minval = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < minval) {
			minval = arr[i];
		}
	}
	return minval;
}

int minvalp(int arr[], int n) {
	int minval = arr[0];
#pragma omp parallel for reduction(min : minval)
	for (int i = 1; i < n; i++) {
		if (arr[i] < minval) {
			minval = arr[i];
		}
	}
	return minval;
}

int maxval(int arr[], int n) {
	int maxval = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxval) {
			maxval = arr[i];
		}
	}
	return maxval;
}

int maxvalp(int arr[], int n) {
	int maxval = arr[0];
#pragma omp parallel for reduction(max : maxval)
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxval) {
			maxval = arr[i];
		}
	}
	return maxval;
}

int sum(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int sump(int arr[], int n) {
	int sum = 0;
#pragma omp parallel for reduction(+ : sum)
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int average(int arr[], int n) {
	return static_cast<double>(sum(arr, n)) / n;
}
int averagep(int arr[], int n) {
	return static_cast<double>(sump(arr, n)) / n;
}

int main()

{
	int n;
	cout << "\n Enter the total number :";
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cout << "\n Enter the value " << i + 1 << endl;
		cin >> arr[i];
	}

	double stime, etime;
	stime = omp_get_wtime();
	cout << "The minimum value is: " << minvalp(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The minimum value is using Sequential: " << minval(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The maximum value is: " << maxvalp(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The maximum value is using Sequential: " << maxval(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The sum is: " << sump(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The sum is using Sequential: " << sum(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The average is: " << averagep(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	stime = omp_get_wtime();
	cout << "The average is using Sequential: " << average(arr, n) << '\n';
	etime = omp_get_wtime();
	cout << etime - stime << " seconds.\n";

	return 0;
}