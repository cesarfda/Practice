#ifndef set_hpp
#define set_hpp
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
	template< typename T > class set {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
	private:
		T* buffer;
		int numElements;
		int numCapacity;
	public:
		/*
		 * Constructors & Destructor
		 */
		set() {
			buffer = NULL;
			numElements = 0;
			numCapacity = 0;
		}
		set(int numElements)throw (const char*) {
			if (numElements <= 0) {
				throw "Error: set sizes must be greater than or equal to 0.";
			}
			this->buffer = new T[numElements];
			for (int i = 0; i < numElements; i++) {
				buffer[i] = *new T();
			}
			this->numElements = numElements;
			this->numCapacity = numElements;
		}
		set(int numElements, T value) {
			buffer = new T[numElements];
			numElements = 0;
			numCapacity = numElements;
		}

		set(set const& rhs) {
			if (rhs.numElements > 0) {
				if (buffer != NULL) {
					delete[] buffer;
					buffer = NULL;
				}
				buffer = new T[rhs.numElements];
				for (int i = 0; i < rhs.numElements; i++) {
					buffer[i] = rhs.buffer[i];
				}
			}
			numElements = rhs.numElements;
			numCapacity = rhs.numElements;
		}
		~set() {}

		set assignment(set const& rhs) {

			return 0;
		}

		int size() {
			return numElements;
		}
		int capacity() {
			return numCapacity;
		}
		bool empty() {
			return !numElements;
		}
		void clear() {
			numElements = 0;
		}
		int find() {
			return 0;
		}


		// need to fix
		void insert(T anElement) {
			if (numElements == numCapacity) {
				numCapacity == 0 ? resize(1) : resize(numCapacity * 2);
			}
			buffer[numElements++] = anElement;
		}

		void union(set rhs) {
			return;
		}

		void intersection(set rhs) {
			return;
		}


		class iterator {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);
#endif
		private:
			T* ptr;
		public:
			iterator() {
				ptr = NULL;
			}
			iterator(T* aTPtr) {
				ptr = aTPtr;
			}
			iterator(const iterator& aIt) {
				ptr = aIt.ptr;
			}
			iterator operator = (T* aPtr) {
				ptr = aPtr;
				return this;
			}
			bool operator==(iterator anIt) {
				return ptr = anIt.ptr;
			}

			bool operator!=(iterator anIt) {
				return ptr != anIt.ptr;
			}
			//prefix operator
			iterator operator++() {
				if (ptr != NULL) {
					++ptr;
				}
				return *this;
			}
			//postfix operator
			iterator operator++(T lhs) {
				iterator result = iterator(*this);
				if (ptr != NULL) {
					++ptr;
				}
				return result;
			}
			//prefix operator
			iterator operator--() {
				if (ptr != NULL) {
					ptr--;
				}
				return *this;
			}
			//postfix operator
			iterator operator--(T lhs) {
				iterator result = iterator(*this);
				if (ptr != NULL) {
					ptr--;
				}
				return result;
			}
			//dereference operator
			T& operator *() {
				return *ptr;
			}

		};
		iterator begin() {
			return iterator(buffer);
		}
		iterator end() {
			return iterator(buffer + numElements);
		}

	private:
		void resize(int numCapacity) {
			T* resizedBuffer = NULL;
			int numElementsToCopy = 0;
			if (numCapacity >= 0) {
				if (numCapacity > 0) {
					resizedBuffer = new T[numCapacity];
					if (buffer != NULL) {
						numElementsToCopy = numElements < numCapacity ? numElements : numCapacity;
						for (int i = 0; i < numElementsToCopy; i++) {
							resizedBuffer[i] = buffer[i];
						}
						delete[] buffer;
					}
				}
				buffer = resizedBuffer;
				this->numCapacity = numCapacity;
				numElements = numElementsToCopy;
			}
		}
		/*
		 * Operators
		 */
	public:
		const T& operator[](int anIndex) const throw(const char*) {

			if (anIndex < 0 && anIndex < numElements) {
				return buffer[anIndex];
			}
			throw "Error: indices must be greater than zero and less than size().";

		}
		T& operator[](int anIndex) throw(const char*) {

			if (anIndex >= 0 && anIndex < numElements) {
				return buffer[anIndex];
			}
			throw "Error: indices must be greater than zero and less than size().";

		}
		set& operator = (const set & rhs) {
			numElements = 0;
			if (rhs.numCapacity > numCapacity) {
				resize(rhs.numElements);
			}
			numElements = rhs.numElements;
			for (int i = 0; i < numElements; i++) {
				buffer[i] = rhs.buffer[i];
			}
			return *this;
		}
	};
}

#endif /* set_h */

