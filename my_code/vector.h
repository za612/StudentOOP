const int DEF_CAPACITY = 10;

class vector {
public:
	vector();

	// copy control:
	vector(const vector& v2);
	~vector();
	vector& operator=(const vector& v2);

	void push_back(int val);
	int size() const { return sz; }
	int operator[](int i) const;
	int& operator[](int i);
private:
	int capacity;
	int sz;
	int* data;
};

void print_vector(const vector& v);


bool operator==(vector& v1, vector& v2);