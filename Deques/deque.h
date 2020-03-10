/***************************************************************
 *    deque.h
 *    Author:
 ****************************************************************/

#ifndef deque_hpp
#define deque_hpp
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
	template< typename T > class deque {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
	private:
		T* buffer;
		int numCapacity;
		int iFront;
		int iBack;

	public:

		/*
		 * Constructors & Destructor
		 */
		deque() {
			buffer = NULL;
			iFront = 0;
			iBack = -1;
			numCapacity = 0;
		}
		/*************************************************************
		 * NON-DEFAULT CONSTRUCTOR:
		 **************************************************************/
		deque(int numCapacity)throw (const char*) {
			if (numCapacity <= 0) {
				throw "Error: deque sizes must be greater than or equal to 0.";
			}
			this->buffer = new T[numCapacity];
			for (int i = 0; i < numCapacity; i++) {
				buffer[i] = *new T();
			}
			this->iBack = -1;
			this->iFront = 0;
			this->numCapacity = numCapacity;
		}

		/*************************************************************
		 * COPY
		 **************************************************************/
		deque(deque const& rhs) {
			if (rhs.iBack > 0) {
				if (buffer != NULL) {
					delete[] buffer;
					buffer = NULL;
				}
				buffer = new T[rhs.iBack];
				for (int i = iFront; i < size() + 1; i++) {
					buffer[i - iFront] = rhs.buffer[rhs.iFront + i];
				}
			}
			iBack = size();
			numCapacity = rhs.iBack;
		}
		/*************************************************************
		 * ~DECONSTRUCTOR:
		 **************************************************************/
		~deque() {}

		/********************/
		deque assign(deque lhs, deque const& rhs) {
			iBack, iFront = 0;
			if (lhs.numCapacity < rhs.size())
				resize(rhs.size());
			for (int i = rhs.iFront; i < rhs.iBack; i++)
				lhs.push(rhs.buffer[i % rhs.numCapacity]);

		}
		/*************************************************************
		 * SIZE:
		 *    Returns the number of elements in the array
		 **************************************************************/
		int size() {
			return (iBack - iFront) + 1;
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
			if (size() == 0)
				return true;
			else
				return false;
		}
		/*************************************************************
		 * Clear
		 **************************************************************/
		void clear() {
			iFront = 0;
			iBack = -1;
		}
		/*************************************************************
		 *Push front
		 **************************************************************/
		void push_front(T anElement) {
			if (size() == numCapacity) {
				numCapacity == 0 ? resize(1) : resize(numCapacity * 2);
			}
			iFront--;
			buffer[iFrontNormalize()] = anElement;
		}
		/*************************************************************
		 *Push back
		 **************************************************************/
		void push_back(T anElement) {
			if (size() == numCapacity) {
				numCapacity == 0 ? resize(1) : resize(numCapacity * 2);
			}
			iBack++;
			buffer[(iBackNormalize())] = anElement;
		}
		/*************************************************************
		 * Pop front
		 **************************************************************/
		void pop_front() {
			if (!empty())
				iFront++;
			else
				throw "Error: Can not pop an empty deque.";
		}
		/*************************************************************
		 * Pop back
		 **************************************************************/
		void pop_back() {
			if (!empty())
				iBack--;
			else
				throw "Error: Can not pop an empty deque.";
		}
		/*************************************************************
		 *
		 **************************************************************/

		T& front() {
			if (empty())
				throw "Error: deque is empty.";
			else
				return buffer[iFrontNormalize()];
		}
		/*************************************************************
		 *
		 **************************************************************/
		T& back() {
			if (empty())
				throw "Error: deque is empty.";
			else
				return buffer[iBackNormalize()];
		}


	private:

		/*************************************************************
		 *normalize
		**************************************************************/
		int iNormalize(int num) {
			if (numCapacity == 0)
				throw "Error: uninitialized deque.";
			else {
				int normalized = num % numCapacity;
				if (num < 0)
					normalized += numCapacity;
				if (normalized == numCapacity)
					normalized = 0;
				return normalized;
			}
		}

		/*************************************************************
		 *Front index
		 **************************************************************/
		int iFrontNormalize() {
			return iNormalize(iFront);
		}
		/*************************************************************
		 *Back index
		 **************************************************************/
		int iBackNormalize() {
			return iNormalize(iBack);
		}
		/*************************************************************
		 *Resize
		 **************************************************************/
		void resize(int numCapacity) {
			T* resizedBuffer = NULL;
			int numElementsToCopy = 0;
			if (numCapacity >= 0) {
				if (numCapacity > 0) {
					resizedBuffer = new T[numCapacity];
					if (buffer != NULL) {
						numElementsToCopy = size() < numCapacity ? size() : numCapacity;
						iBack = -1;
						for (int i = iFront; i < numElementsToCopy + iFront; i++) {
							resizedBuffer[i - iFront] = buffer[(i - iFront) + iFrontNormalize()];
							iBack++;
						}
						delete[] buffer;
					}
					buffer = resizedBuffer;
					this->numCapacity = numCapacity;
					iFront = 0;
				}
				else{
				buffer = resizedBuffer;
				this->numCapacity = numCapacity;
				iFront = 0;
				iBack = -1;
				}
			}
		};

	public:
		/*const T& operator[](int anIndex) const throw(const char*) {

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

		}*/
		deque& operator = (deque & rhs) {
			iBack = size();
			if (rhs.numCapacity > numCapacity) {
				resize(rhs.size());
			}
			iBack = rhs.size();
			for (int i = 0; i < size(); i++) {
				buffer[i] = rhs.buffer[i];
			}
			return *this;
		};
	};
};
#endif /* deque_h */
