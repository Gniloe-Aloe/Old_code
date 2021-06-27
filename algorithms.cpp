#include<iostream>
#include<ctime>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

void Print_Array(int Array[], const int size) {
	for (int i = 0; i < size; ++i) {
		cout << Array[i] << '\t';
	}
	cout << endl;
}

class Coordinates
{
	int m_X;
	int m_Y;
public:
	void Set_Coordinates(int X, int Y) {
		m_X = X;
		m_Y = Y;
	}
	int Get_X() {
		return m_X;
	}
	int Get_Y() {
		return m_Y;
	}
	void Print_Coordinates() {
		cout << m_X << '\t' << m_Y << endl;
	}
	//копироване элементов из другого объекта этого класса
	void CopyFrom(Coordinates b) {
		m_X = b.m_X;
		m_Y = b.m_Y;
	}
};

int line_search(int A[], const int N, int x) {
	for (int i = 0; i < N; ++i) {
		if (A[i] == x)
			return i;
	}
	return -1;
}




int left_bound(int A[], int N, int x) {
	int left = -1;
	int right = N;
	while (right - left > 1) {
		int middle = (left + right) / 2;
		if (A[middle] > x) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	return left;
}
int find(int A[], int N, int x)
{
	if(A[left_bound(A, N, x)] == x)
	{
	return left_bound(A, N, x);
	}
	else {
		return -1;
	}
}

//сортировка выбором
void choise_sort(int A[], int N) {
	for (int min = 0; min < N - 1; ++min) {
		for (int maybe_min = min + 1; maybe_min < N; ++maybe_min) {
			if (A[maybe_min] < A[min]) {
				int tmp = A[min];
				A[min] = A[maybe_min];
				A[maybe_min] = tmp;
			}
		}
	}
}

//сортировка пузырьком
void buble_sort(int A[], int N) {
	for (int i = 0; i < N - 1; ++i) {
		for(int j = 0; j < N - 1 - i; ++j)
		if (A[j] > A[j + 1])
		{
			int tmp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = tmp;
		}
	}
}

//сортировка вставками
//вставляем элементы в отсортированную часть массива по одному
void insert_sort(int A[], int N) {

	for (int pos = 1; pos < N; ++pos) {
		int i = pos;
		while (i > 0 and A[i-1] > A[i]){
			int tmp = A[i];
			A[i] = A[i - 1];
			A[i - 1] = tmp;
			i--;
		}
	}
}

//заполнить по убыванию
void array_fill_back(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		*(A + i) = N - 1 - i;
	}
}

//сортировка с диапозоном
void count_sort(int A[], int N) {
	int F[10] = {0};
	//массив частот заполняем
	for (int i = 0; i < N; ++i) {
		F[A[i]]++;
	}
	
	for (int i = 0, x = 0; x < 10; ++x) {
		for (int k = 0; k < F[x]; ++k) {
			A[i] = x;
			++i;
		}
	}
}

void mass_gherts(int A[], int N) {
	int F[10] = { 0 };
	for (int i = 0; i < N; ++i) {
		while (A[i] != 0) {
			F[i] = i;

			A[i]--;
		}
		
	}
	for (int i = 0; i < 10; ++i) {
		cout << F[i] << '\t';
	}
	cout << endl;
}
//рекурентный факториал
int rec_factorial(unsigned x) {
	if (x == 1 || x == 0) {
		return 1;
	}
	return rec_factorial(x - 1) * x;
}
//НОД Евклид
int Evklid(int value1, int value2) {
	if (value1 < value2) {
		int tmp = value1;
		value1 = value2;
		value2 = tmp;
	}
	while (value1 != 0 && value2 != 0) {
		if (value1 % value2 == 0) {
			return value2;
		}
		else {
			if (value1 > value2) {
				value1 -= value2;
			}
			else {
				value2 -= value1;
			}
		}
	}
}
//Создать случайный массив
void Random_Array(int A[], int size) {
	for (int i = 0; i < size; ++i) {
		*(A + i) = rand()%100;
	}
}
// свой бинарный поиск
int bin_search(int A[], int size, int search) {
	int left = -1;
	int right = size;
	while ((right - left) > 1) {	
		int middle = (right + left) / 2;
		if (A[middle] == search && (A[middle]>A[middle - 1] || middle == 0)) {
			return middle;
		}
		if (A[middle] >= search) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	return -1;
}
// нод евклид
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
//рекурсиный факториал
int rec_factorial(int a) {
	return (a == 1) ? a : a * rec_factorial(a - 1);
}
// быстрое возведение в степень рекурсивно
int rec_exponentiation(int value, int exponentiation) {
	if (exponentiation == 0) {
		return 1;
	}
	if (exponentiation % 2 == 0) {
		return rec_exponentiation(value * value, exponentiation / 2);
	}
	else {
		return value * rec_exponentiation(value, exponentiation - 1);
	}
}
//решатель ханойских башен
// i с какого столбца перекладываем диск
// k на какой столбец перекладываем диск
// n какой диск перекладываем
void hanoi(int i, int k, int n) {
	if (n == 1) {
		cout << "перекладываем со столбца " << i <<" на стоолбец " << k <<" диск " << n << endl;
	}
	else {
		int tmp = 6 - i - k;
		hanoi(i, tmp, n - 1);
		cout << "перекладываем со столбца " << i << " на стоолбец " << k << " диск " << n << endl;
		hanoi(tmp, k, n - 1);
	}
}
//рекурсивная генерация всех чисел определённой длинны
void binary_numbers_generate(int left_number_to_generate) {
	static int combinations[17];
	static int top = 0;
	//крайний случай
	if (left_number_to_generate == 0) {
		for (int i = 0; i < top; ++i) {
			cout << combinations[i];
		}
		cout << endl;
	}
	//рекурсивный случай
	else {

		combinations[top++] = 1;
		binary_numbers_generate(left_number_to_generate - 1);
		top--;

		combinations[top++] = 0;
		binary_numbers_generate(left_number_to_generate - 1);
		top--;
	}
}
//рекурсивная генерация перестановок
void permutations(int lenth, int current, int buffer[], bool used[]) {
	//base case
	if (current == lenth) {
		for (int i = 0; i < lenth; ++i) {
			cout << buffer[i] << '\t';
		}
		cout << endl;
	}
	else {//recursive case
		for (int variant = 0; variant < lenth; ++variant) {
			if (!used[variant]) { //here we cut the recursive tree
				buffer[current] = variant;
				used[variant] = true;
				permutations(lenth, current + 1, buffer, used);
				used[variant] = false;
			}
		}
	}
}
//своя генерация цисел любой длинны в любом диапазоне
void my_tree(int lenth, int current, int buffer[], bool used[]) {
	if (lenth == current) {
		for (int i = 0; i < lenth; ++i) {
			cout << buffer[i];
		}
		cout << endl;
	}
	else {
		for (int variant = 0; variant < lenth; ++variant) {
				if(!used[variant]){
					buffer[current] = variant;
					used[variant] = true;
					my_tree(lenth, current + 1, buffer, used);
					used[variant] = false;
				}
		}
	}

}
void input_array(int array[], int array_lenth) {
	cout << "введите " << array_lenth << " элементов массива" << endl;
	for (int i = 0; i < array_lenth; ++i) {
		cin >> array[i];
	}
	cout << endl;
}
//сортировка слиянием
void merge_sort(int array[], int array_lenth) {
	if (array_lenth == 1) {
		return;
	}
	int middle = array_lenth / 2;
	int* left = array;
	int* right = array + middle;
	int left_lenth = middle;
	int right_lenth = array_lenth - left_lenth;
	merge_sort(left, left_lenth);
	merge_sort(right, right_lenth);
	int* buffer = new int[array_lenth];
	int buffer_i = 0;
	int left_i = 0;
	int right_i = 0;
	while (left_i < left_lenth && right_i < right_lenth) {
		if (left[left_i] <= right[right_i]) {
			buffer[buffer_i] = left[left_i];
			left_i++;
			buffer_i++;
		}
		else {
			buffer[buffer_i] = right[right_i];
			right_i++;
			buffer_i++;
		}
	}
	while (left_i < left_lenth) {
			buffer[buffer_i] = left[left_i];
			left_i++;
			buffer_i++;
	}
	while (right_i < right_lenth){
		buffer[buffer_i] = right[right_i];
		right_i++;
		buffer_i++;
	}
	for (int i = 0; i < array_lenth; ++i) {
		array[i] = buffer[i];
	}
	delete[] buffer;
}
//рекурентное фибоначи
uint64_t fib_rec(int n) {
	if (n == 1)return 1;
	if (n == 0)return 0;
	return fib_rec(n - 1) + fib_rec(n - 2);
}
// динамическое фибоначи
uint64_t fib_dinamic(int n) {
	uint64_t* array = new uint64_t[n + 1];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <= n; ++i) {
		array[i] = array[i - 1] + array[i - 2];
	}
	uint64_t m = array[n];
	delete[] array;
	return m;
}
void print_vector(std::vector<int> array) {
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << '\t';
	}
	cout << endl;
}
//рекурентный бином ньютона или количество траекторий, если ходить можно только вниз или вправо
int binom_newton_rec(int i, int j) {
	if (i == 0 or j == 0) {
		return 1;
	}
	else {
		return binom_newton_rec(i - 1, j) + binom_newton_rec(i, j - 1);
	}
}
//динамический бином ньютона
int binom_newton_dynamic(int n, int m) {
	//создание двумерного динамического массива
	int** K = new int* [n + 1];
	for (int i = 0; i <= n; ++i) {
		K[i] = new int[m + 1];
	}
	//крайний случай
	for (int i = 1; i <= n; ++i) {
		K[i][1] = 1;
	}
	for (int j = 1; j <= m; ++j) {
		K[1][j] = 1;
	}
	//"рекурентный" случай
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			K[i][j] = K[i - 1][j] + K[i][j - 1];
		}
	}
	int result = K[n][m];

	for (int i = 0; i <= n; ++i) {
		delete K[i];
	}
	delete[] K;
	return result;
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	std::vector<int> array = {1, 2, 3, 4, 5};
	for (int i = 6; i < 15; ++i) {
		array.push_back(i);
	}
	array.clear();
	print_vector(array);
}