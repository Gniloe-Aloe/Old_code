#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <thread>
#include <stack>
#include <forward_list>
#include <list>
#include <functional>
#include <algorithm>
#include <numeric>
#include <mutex>
#include <memory>
#include <deque>
#include <queue>
#include <unordered_map>
#include <any>




class My_timer {
public:
	My_timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~My_timer() {
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout <<"Duration = " << duration.count() << " s" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};
template <typename T>
void print_vector(const std::vector<T>& v) {
	for (auto pv : v) {
		std::cout << pv << '\t';
	}
	std::cout << '\n';
}

class Person {
public:
	Person(std::string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator()(const Person& any) {
		return score == any.score;
	}
	bool operator> (const Person& one) {
		return this->score > one.score;
	}
	bool operator<(const Person& one) {
		return score < one.score;
	}
	bool operator== (const Person& one) {
		return score == one.score;
	}
	void Print() {
		std::cout << name << '\t' << score << std::endl;
	}
	std::string name;
	int score;
};

void Print_Person(const std::vector<Person>& res) {
	for (auto pr : res) {
		pr.Print();
	}
}
std::mutex mtx;
void dovork(const char& sim) {
	mtx.lock();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << sim;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
	mtx.unlock();
}

class Test {
public:
	Test(const int value) : value(value) {};
	bool operator <(const Test& val) const {
		return this->value < val.value;
	}
	bool operator >(const Test& val)const {
		return val < *this;
	}
	bool operator !=(const Test& val)const {
		return (*this > val) || (*this < val);
	}
	bool operator ==(const Test& val)const {
		return!(*this != val);
	}
	Test& operator +=(const Test& val) {
		this->value += val.value;
		return *this;
	}
	Test& operator +(const Test& val) {
		Test tmp = *this;
		return tmp+=val;
	}
	Test& operator++() {
		return *this += 1;
	}
	const Test& operator++(int) {
		Test tmp = *this;
		*this += 1;
		return tmp;
	}
	void get() {
		std::cout << value << std::endl;
	}
protected:
	int value;
};

class Pred_Test :public Test {
public:
	Pred_Test(int val, std::string word) :Test(val), word(word) {};
	void get() {
		std::cout << word << std::endl;
	}
	friend void print(const Pred_Test& val);
protected:
	std::string word;
};
void print(const Pred_Test& val) {
	std::cout << val.value <<'\t' << val.word << std::endl;
}

template <typename Container>
void Printer(Container&& c){
	for (auto& pc : c) {
		std::cout << pc << std::endl;
	}
}
template<typename T>
void swap(T& x, T& y) {
	T tmp = std::move(x);
	x = std::move(y);
	y = std::move(tmp);

}
template <typename T>
void Printerm(T& c) {
	for (auto& pc : c) {
		std::cout << pc << std::endl;
	}
}
class matter {
public:
	int x;
	void foo(int x)noexcept{

	}

};
class Setter {
public:
	Setter(int a) : a(a) {};
	void f()const & {

	}
	Setter& operator =(const Setter& val) noexcept {
		this->a = val.a;
		return *this;
	}
	int a;
	int get()const noexcept {
		return a;
	}
};
class speed {
public:
	explicit speed(int x) {
		std::cout << x << std::endl;
	}
};
template<typename T>
T& fr(T&& value) {
	return ++value;
}
template<bool N>
void gss() {
	
}
template<>
void gss<true>() {
	std::cout << true << std::endl;
}
//��� ����� ������ �� �������� ������������
template<>
void gss<false>() {
	std::cout << false << std::endl;
}
//�������� �� ����������. ��, �������� - ������ �������
constexpr int cnst(int n) noexcept {
	return n < 2 ? 1 : cnst(n-1)+cnst(n-2);
}
bool ret(int a, int b) {
	return a > b;
}

int main()
{
	My_timer timer;
	setlocale(LC_ALL, "Russian");
	

	return 0;
}