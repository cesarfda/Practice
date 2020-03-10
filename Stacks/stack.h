//
//  stack.hpp
//  Stacks
//
//  
//  
//

#ifndef stack_hpp
#define stack_hpp
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
	template< typename T > class stack {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
	private:
		T* buffer;
		int numElements;
		int numCapacity;

	public:
		/*
		 * Pop, Top functionalities.
		 */

		 /*
		  * Constructors & Destructor
		  */
		stack() {
			buffer = NULL;
			numElements = 0;
			numCapacity = 0;
		}
		stack(int numCapacity)throw (const char*) {
			if (numCapacity <= 0) {
				throw "Error: stack sizes must be greater than or equal to 0.";
			}
			this->buffer = new T[numCapacity];
			for (int i = 0; i < numCapacity; i++) {
				buffer[i] = *new T();
			}
			this->numElements = numElements;
			this->numCapacity = numElements;
		}

		stack(stack const& rhs) {
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
		~stack() {}

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
		void push(T anElement) {
			if (numElements == numCapacity) {
				numCapacity == 0 ? resize(1) : resize(numCapacity * 2);
			}
			buffer[numElements++] = anElement;
		}
		T& top()throw (const char*) {
			if (!empty())
				return buffer[numElements - 1];
			else
				throw "Error: stack sizes must be greater than or equal to 0.";
		}
		void pop() {
			if (!empty())
				--numElements;
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
		stack& operator = (const stack& rhs) {
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
#endif /* stack_h */
