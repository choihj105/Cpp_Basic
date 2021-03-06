// 2. Reference counter (참조 계수)

#include <iostream>
using namespace std;

template <typename T>
class smartptr
{
private:
	T* ptr;
	int* ref;

public:
	smartptr(T* p = 0) : ptr(p) {

		ref = new int(1);
		(*ref)++;
	}

	~smartptr()
	{
		if (--(*ref) == 0)
		{
			delete ptr;
			delete ref;
		}

	}

	// 2. 레퍼런스
	smartptr(const smartptr& p)
		: ptr(p.ptr), ref(p.ref)
	{
		(*ref)++;
	}


	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }


};

int main()
{

	smartptr<int> p1 = new int;
	*p1 = 10;

	smartptr<int> p2 = p1;

	cout << *p2 << endl;

	*p2 = 5;

	cout << *p1 << endl;

	return 0;
}