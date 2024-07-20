#include <iostream>
#include <initializer_list>
#include <stdexcept>

#define function auto

template<typename T>
class Vector {
public:
	explicit Vector(int capacity){
		if (capacity < 0)
			throw std::length_error("vector length must > 0!");
		m_size = 0;
		m_capacity = capacity;
		m_elem = new T[capacity];
		for (int i = 0; i < capacity; i++)
			m_elem[i] = 0;
	};
	explicit Vector(std::initializer_list<T> lst) : m_elem{ new T[lst.size()] }, m_size{ lst.size() }, m_capacity{lst.size()}
	{
		std::copy(lst.begin(), lst.end(), m_elem);
	}
	~Vector() { delete[] m_elem; };

	void push_back(const T& node)
	{
		if (m_size == m_capacity)
		{
			m_capacity = m_capacity * 2 + 1;
			T* temp = new T[m_capacity];
			for (int i = 0; i < m_size; i++)
				temp[i] = m_elem[i];
			delete [] m_elem;
			m_elem = temp;
			m_elem[m_size] = node;
			m_size++;
		}
		else
		{
			m_elem[m_size++] = node;
		}
	}

	T& operator[](int i) { return m_elem[i]; };
	inline size_t size() const { return m_size; };
	inline size_t capacity() const { return m_capacity; };

private:
	T* m_elem;
	size_t m_size;
	size_t m_capacity;
};

template<class T>
function add_vector()
{
	Vector<int> v1(5);
	for (int i = 0; i < 5; i++)
        v1.push_back(i);
	auto total = 0;
	for (int i = 0; i < v1.size(); i++)
	{
        std::cout << "v1["<<i<<"] = "<<v1[i]<<std::endl;
		total += v1[i];
	}
	std::cout << "add_vector return " << total << std::endl;
	return total;
}

int main()
{
    add_vector<int>();

    return 0;
}