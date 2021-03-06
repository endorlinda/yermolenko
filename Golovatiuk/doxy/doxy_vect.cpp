/**
 Template implementation of vector.
 @author Artem Golovatiuk
*/
#include <iostream>

using namespace std;

/**
 @brief Template class of dynamic size array
*/

template <typename T>
class vectar
{
private:
	T *ptr; /** Pointer to the array */
	int size; /** Current vector size */
	int capasity; /** Current maximum vector size */
public:
	vectar(): size(0), capasity(5) /** Default constructor */
		{
		ptr = new T[capasity];
		}
	vectar(int razm): size(0), capasity(razm) /** Constructor for particular capasity */
		{
		ptr = new T[capasity];
		}
	~vectar() /** Destructor */
		{
		delete [] ptr;
		}
	int getsize() /** @brief Current size */
		{
		return size;
		}
	T& operator[] (int num)
		{
		if (num>size) 
			{ 
			cout<< "too much" <<endl; 
			return ptr[0];
			}
		else
			return ptr[num];
		}
	void print ()
		{
		for (int i=0; i < size; ++i)
			{
			(*this)[i].print();
			cout<<" ";
			}
		cout << endl;
		}
	void pushback (T elem) /** Put an element into the end of vector */
		{
		if (size<capasity)
			{
			(*this)[size] = elem;
			++size;
			}
		else
			{
			T *copa = new T[capasity+1];
			for (int i=0; i<size; ++i)
				copa[i] = (*this)[i];
			copa[size] = elem;
			delete [] ptr;
			ptr = copa;
//			cout << copa.ptr << " " << ptr << endl;
			++capasity;
			++size;
//			(*this).print();
			}
		}
	
};

/**
 Testing class to put inside the vector.

*/

class artest
{
private:
	int art;
public:
	artest(): art(12) /** Test constructor */
	{}
	artest(int a): art(a)
	{}
	~artest()
	{}
	void print() /** Print the element stored here */
	{
	cout << art;
	}

};

/**
 Simple exmaple of the template working
*/

int main()
{
	artest ara(145);
	vectar<artest> v(2);
	v.pushback(ara);
	cout << "size " << v.getsize() << endl;
	v.pushback(ara);
	v.print();
	v.pushback(ara);
	cout << "size " << v.getsize() << endl;
	v.print();
return 0;
}




