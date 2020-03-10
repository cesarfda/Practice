/***************************************************************
 *    queue.h
 *    Author:
 ****************************************************************/

#ifndef queue_hpp
#define queue_hpp
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
	template< typename T > class queue {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
	private:
		T* buffer;
		int numCapacity;
		int numPush;
		int numPop;


	public:
		/*
		 * Pop, Top functionalities.
		 */

		 /*
		  * Constructors & Destructor
		  */
		queue() {
			buffer = NULL;
			numPop = 0;
			numPush = 0;
			numCapacity = 0;
		}
		/*************************************************************
		 * NON-DEFAULT CONSTRUCTOR:
		 **************************************************************/
		queue(int numCapacity)throw (const char*) {
			if (numCapacity <= 0) {
				throw "Error: queue sizes must be greater than or equal to 0.";
			}
			this->buffer = new T[numCapacity];
			for (int i = 0; i < numCapacity; i++) {
				buffer[i] = *new T();
			}
			this->numPush = 0;
			this->numPop = 0;
			this->numCapacity = numCapacity;
		}

		/*************************************************************
		 * COPY
		 **************************************************************/
		queue(queue const& rhs) {
			if (rhs.numPush > 0) {
				if (buffer != NULL) {
					delete[] buffer;
					buffer = NULL;
				}
				buffer = new T[rhs.numPush];
				for (int i = 0; i < rhs.numPush; i++) {
					buffer[i] = rhs.buffer[i];
				}
			}
			numPush = rhs.numPush;
			numCapacity = rhs.numPush;
		}
		/*************************************************************
		 * ~DECONSTRUCTOR:
		 **************************************************************/
		~queue() {}

		/********************/
		queue assign(queue lhs, queue const& rhs) {
			numPush, numPop = 0;
			if (lhs.numCapacity < rhs.size())
				resize(rhs.size());
			for (int i = rhs.numPop; i < rhs.numPush; i++)
				lhs.push(rhs.buffer[i % rhs.numCapacity]);

		}
		/*************************************************************
		 * SIZE:
		 *    Returns the number of elements in the array
		 **************************************************************/
		int size() {
			return numPush - numPop;
		}
		/*************************************************************
		 * CAPACITY:
		 *    Returns the capacity of the array
		 **************************************************************/
		int capacity() {
			return numCapacity;
		}
		/*************************************************************
		 * Empty
		 **************************************************************/
		bool empty() {
			if (numPush == numPop)
				return true;
			else
				return !numPush;
		}
		/*************************************************************
		 * Clear
		 **************************************************************/
		void clear() {
			numPush = 0;
		}
		/*************************************************************
		 *
		 **************************************************************/
		void push(T anElement) {
			if (size() == numCapacity) {
				numCapacity == 0 ? resize(1) : resize(numCapacity * 2);
			}
			numPush++;
			buffer[iTail()] = anElement;
		}
		/*************************************************************
		 *
		 **************************************************************/
		void pop() {
			if (!empty())
				numPop++;
		}
		/*************************************************************
		 *
		 **************************************************************/

		T& front() {
			if (empty())
				throw "Error: asking for front of empty queue.";
			else
				return buffer[iHead()];
		}
		/*************************************************************
		 *
		 **************************************************************/
		T& back() {
			if (empty())
				throw "Error: asking for back of empty queue.";
			else
				return buffer[iTail()];
		}


	private:

		/*************************************************************
		 *Oldest number
		 **************************************************************/
		int iHead() {
			return numPop % numCapacity;
		}
		/*************************************************************
		 *Newest Number
		 **************************************************************/
		int iTail() {
			return (numPush - 1) % numCapacity;
		}
		/*************************************************************
		 *Resize
		 **************************************************************/

		 /* void resize(int numCapacity) {
			 T* resizedBuffer = new T[numCapacity];
			 this->numCapacity = numCapacity;
			 resizedBuffer = buffer;
			 delete[] buffer;
			 buffer = new T[numCapacity];
			 buffer = resizedBuffer;
			 delete[] resizedBuffer;
		 };*/
		void resize(int numCapacity) {
			T* resizedBuffer = NULL;
			int numElementsToCopy = 0;
			if (numCapacity >= 0) {
				if (numCapacity > 0) {
					resizedBuffer = new T[numCapacity];
					if (buffer != NULL) {
						numElementsToCopy = size() < numCapacity ? size() : numCapacity;
						for (int i = 0; i < numElementsToCopy; i++) {
							resizedBuffer[i] = buffer[i];
						}
						delete[] buffer;
					}
				}
				buffer = resizedBuffer;
				this->numCapacity = numCapacity;
				numPush = numElementsToCopy;
				numPop = 0;
			}
		};

	public:
		const T& operator[](int anIndex) const throw(const char*) {

			if (anIndex < 0 && anIndex < size()) {
				return buffer[anIndex];
			}
			throw "Error: indices must be greater than zero and less than size().";

		}
		T& operator[](int anIndex) throw(const char*) {

			if (anIndex >= 0 && anIndex < size()) {
				return buffer[anIndex];
			}
			throw "Error: indices must be greater than zero and less than size().";

		}
		queue& operator = (queue & rhs) {
			numPush = 0;
			if (rhs.numCapacity > numCapacity) {
				resize(rhs.size());
			}
			numPush = rhs.size();
			for (int i = 0; i < size(); i++) {
				buffer[i] = rhs.buffer[i];
			}
			return *this;
		};
	};
};
#endif /* queue_h */
