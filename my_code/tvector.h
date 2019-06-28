const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template<typename T>
class MyVec {
public:
	template<typename T>
	class Iterator {
		/*
		 * This class supports ranged for loops.
		 * It includes:
		 * Iterator(int*)
		 * operator++
		 * operator*
		 * operator!=
		 * */
		friend bool operator!=(Iterator& rhs, Iterator& lhs) {
			return lhs.iptr != rhs.iptr;
		}

	public:
		Iterator(T* ip) : iptr(ip) {}

		Iterator& operator++() {
			++iptr;
			return *this;
		}

		T& operator*() { return *iptr; }

	private:
		T* iptr;
	};

	MyVec();
	MyVec(int sz, T val);

	// copy control:
	MyVec(const MyVec& v2);
	~MyVec();
	MyVec& operator=(const MyVec& v2);

	void push_back(T val);
	int size() const { return sz; }
	T operator[](int i) const;
	T& operator[](int i);
	Iterator<T> begin() const;
	Iterator<T> end() const;

private:
	void copy(const MyVec& v2);
	T* data;
	int sz;
	int capacity;
};

template<typename T>
void print_vector(const MyVec<T>& v);

template<typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2);
