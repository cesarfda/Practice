//
//  list.h
//  list
//
//  Created by josh Hellewell on 6/3/19.
//Copyright � 2019 Iron Buffalo. All rights reserved.
//

#ifndef list_h
#define list_h

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif


namespace custom {
	template< typename T > class list {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif


	private:
		class node {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);

#endif
		public:
			T data;
			node* pNext;
			node* pPrev;

			node() {
				data = T();
				pNext = NULL;
				pPrev = NULL;
			}

			node(const T& aValue) {
				data = aValue;
				pNext = NULL;
				pPrev = NULL;
			}
			~node() {}
			/*******************************************************************
			 * INSERT:
			 *        Insert a value into the linked list
			 ********************************************************************/
			node* insert(node* pNode, const T& t,
				bool after = false) throw (const char*) {
				if (pNode == NULL)
					throw "Error: inserting into NULL list.";
				node * pNew = new node(t);
				if (pNode != NULL && after == false) {
					pNew->pNext = pNode;
					pNew->pPrev = pNode->pPrev;
					pNode->pPrev = pNew;
				};
				if (pNew->pPrev)
					pNew->pPrev->pNext = pNew;

				if (pNode != NULL && after == true) {
					pNew->pNext = pNode->pNext;
					pNew->pPrev = pNode;
					pNode->pNext = pNew;
				};


				return pNew;
			}

			/*******************************************************************
			 * FIND:
			 *        Find a given value within the linked list
			 ********************************************************************/
			node* find(node* pHead, const T& t) {
				for (node* p = pHead; p; p = p->pNext)
					if (p->data == t)
						return p;
				return NULL;

			}

			/*******************************************************************
			 *  CLEAR:
			 *        Delete the entire list
			 ********************************************************************/
			void clear(node * &pHead) throw (const char*) {
				if (pHead == NULL)
					throw "Error: freeing NULL list.";
				while (pHead != NULL)
				{
					node* pDelete;
					pDelete = pHead;
					pHead = pHead->pNext;
					delete pDelete;
				}

			}

			/*******************************************************************
			 * COPY:
			 *        Copy one list and store it in another
			 ********************************************************************/
			node* copy(node * pSource) {
				if (pSource == NULL)
					return NULL;
				else {
					node* pDestination = new node(pSource->data);
					node* pSrc = pSource;
					node* pDes = pDestination;
					for (node* p = pSrc->pNext; p; p = p->pNext)
						pDes = insert(pDes, p->data, true);
					return pDestination;
				};
			}

			/*******************************************************************
			 * REMOVE:
			 *        Remove a single node from the list and the update what it
			 *        points to
			 ********************************************************************/
			node* remove(const node * pRemove) {
				if (pRemove == NULL)
					return NULL;
				node * pReturn = new node;

				if (pRemove->pPrev)
					pRemove->pPrev->pNext = pRemove->pNext;
				if (pRemove->pNext)
					pRemove->pNext->pPrev = pRemove->pPrev;

				if (pRemove->pPrev)
					pReturn = pRemove->pPrev;
				else
					pReturn = pRemove->pNext;

				delete pRemove;
				return pReturn;
			}
		};// end of node class


	public:
		node* pHead;
		node* pTail;
		int numElements;

		list() {
			pHead = NULL;
			pTail = NULL;
			numElements = 0;
		}
		list(list & rhs) {
			if (rhs.pHead == NULL) {
				pHead = NULL;
				pTail = NULL;
				numElements = 0;
			}
			else {
				pHead = new node(rhs.pHead->data);
				node* current = pHead;
				node* rhsHead = rhs.pHead;
				node* currentrhs = rhsHead;
				numElements = 1;
				if (rhs.size() >= 1)
				{
					while (currentrhs->pNext != NULL) {
						current->pNext = new node(currentrhs->pNext->data);
						currentrhs = currentrhs->pNext;
						current = current->pNext;

						numElements++;
					}
				}
				else
				{
					pTail = pHead;
				}
				//-----------------------------
				pTail = current;
			}
		}


		~list() {
			if (numElements == 0)
				return;
			node * current = pHead;
			while (current != NULL) {
				node* garbage = current;
				current = (current->pNext == NULL ? NULL : current->pNext);
				delete garbage;

			}
		}
		class iterator {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);

#endif
			friend list<T>;
		private:
			node* ptr;

		public:
			iterator() {
				ptr = NULL;
			}
			iterator(node* aPtr) {
				ptr = aPtr;
			}
			iterator(const iterator& aIt) {
				ptr = aIt.ptr;
			}
			iterator operator = (node const* aPtr) {
				ptr = aPtr;
				return this;
			}
			bool operator == (iterator anIt) {
				return ptr == anIt.ptr;
			}
			bool operator != (iterator anIt) {
				return ptr != anIt.ptr;
			}

			iterator operator ++ () throw(const char*) {
				if (ptr) {
					if (ptr->pNext == NULL)
						return ptr;
					ptr = ptr->pNext;
					return *this;
				}
				else
					throw "Error: Incrementing null node.";
			}

			iterator operator ++ (T lhs)throw(const char*) {
				if (ptr) {
					if (ptr->pNext == NULL)
						return ptr;

					iterator result(*this);
					ptr = ptr->pNext;
					return result;
				}
				else
					throw "Error: Incrementing null node.";
			}

			iterator operator -- ()throw(const char*) {
				if (ptr) {
					if (ptr->pPrev == NULL)
						return ptr;
					ptr = ptr->pPrev;
					return *this;
				}
				else
					throw "Error: Decrementing null node.";
			}

			iterator operator -- (T lhs) throw(const char*) {
				if (ptr) {
					if (ptr->pPrev == NULL)
						return ptr;
					iterator result(*this);
					ptr = ptr->pPrev;
					return result;
				}
				else
					throw "Error: Decrementing null node.";
			}


			T operator *() throw(const char*) {
				if (this->ptr == NULL)
					throw "Error: Dereferencing null node.";
				return ptr->data;
			}
		}; // end of iterator class

		list& operator = (const list & rhs) {
			if (rhs.pHead == NULL) {
				pHead = NULL;
			}
			else {
				pHead = new node(rhs.pHead->data);
				node* current = pHead;
				node* rhsHead = rhs.pHead;
				node* currentrhs = rhsHead;
				numElements = 1;
				while (currentrhs->pNext != NULL) {
					current->pNext = new node(currentrhs->pNext->data);
					currentrhs = currentrhs->pNext;
					current = current->pNext;
					pTail = current;
					numElements++;
				}
				pTail = current;
			}
			return *this;
		}

		iterator begin() {
			return iterator(pHead);
		}
		iterator end() {
			return iterator(pTail);
		}
		/*****************************************************
		 * SIZE: returns the number of elements in the array
		 *****************************************************/
		int size() {
			return numElements;
		}
		/*****************************************************
		 * EMPTY: Returns true if there are elements in the array
		 *         and false if otherwise
		 *****************************************************/
		bool empty() {
			return !numElements;
		}
		void clear() {
			//list <T>::iterator it = this->begin();
			//while (it != this->end()) {
			//    it = this->erase(it);
			//}
			if (pHead) {
				for (int i = 0; i <= numElements; i++) {
					node* pDelete;
					pDelete = pHead;
					pHead = pHead->pNext;
					delete pDelete;
					pDelete = NULL;
					numElements--;
				}
				pHead = NULL;
				pTail = NULL;
			}
		}
		void push_back(T aValue) throw (const char*) {
			//pNew = new(std::nothrow) node<T>(aValue);
			if (pTail == NULL) {
				pTail = new node(aValue);
				pHead = pTail;
				numElements++;
			}
			else {
				node* pTemp = pTail;
				pTail = new node(aValue);
				pTail->pPrev = pTemp;
				pTail->pPrev->pNext = pTail;

				numElements++;
			}
		}

		void push_front(T aValue) throw (const char*) {

			if (pHead == NULL) {
				pHead = new node(aValue);
				pTail = pHead;
				numElements++;
			}

			else {
				node* pTemp = pHead;
				pHead = new node(aValue);
				pHead->pNext = pTemp;
				pHead->pNext->pPrev = pHead;
				numElements++;
			}
		}

		void pop_back() {
			if (pTail) {
				node* tempTail = pTail;
				node* tailPrev = pTail->pPrev;
				delete pTail;
				if (tempTail) {
					pTail = tailPrev;
					numElements--;
				}
				else
					pTail = NULL;
			}
		}

		void pop_front() {
			if (pHead) {
				node* tempHead = pHead;
				node* HeadNext = pHead->pNext;

				delete pHead;
				pHead = NULL;
				if (tempHead) {
					pHead = HeadNext;
					numElements--;
				}
				pHead->pPrev = NULL;
				//else
				//pHead = NULL;
			}
		}

		//T front() throw(const char*){
		//    return *(pHead->data);
		//}
		//T back() throw(const char*) {
		//    return *(pTail->data);
		//}
		T& front() throw(const char*) {
			if (pHead == NULL)
				throw "Error: Calling front on empty list.";
			return pHead->data;
		}
		T& back() throw(const char*) {
			if (pHead == NULL)
				throw "Error: Calling back on empty list.";
			return pTail->data;
		}
		/*       iterator find(T aValue) {
		 for (iterator it = pHead; it != pTail; it++) {
		 if (*it == aValue)
		 return it;
		 }
		 return iterator();
		 }*/
		iterator find(const T & data) {
			node* pNode = pHead;
			while (pNode != NULL)
			{
				if (pNode->data == data)
				{
					return iterator(pNode);
				}
				pNode = pNode->pNext;
			}
			return iterator();
		}

		iterator erase(iterator toErase) {
			if (toErase == NULL)
				return NULL;
			if (toErase == pHead) {
				pHead = pHead->pNext;

			}

			else if (toErase.ptr->pNext == NULL)
				toErase.ptr->pPrev->pNext = toErase.ptr->pNext;
			else if (toErase.ptr->pPrev == NULL)
				toErase.ptr->pNext->pPrev = toErase.ptr->pPrev;
			else {
				toErase.ptr->pPrev->pNext = toErase.ptr->pNext;
				toErase.ptr->pNext->pPrev = toErase.ptr->pPrev;
			}
			delete toErase.ptr;
			++toErase;

			return iterator();

			/*            if (toErase == NULL)
			 return NULL;
			 if (toErase != pTail && toErase != pHead) {
			 toErase.ptr->pNext->pPrev = toErase.ptr->pPrev;
			 toErase.ptr->pPrev->pNext = toErase.ptr->pNext;
			 iterator it(toErase.ptr->pNext);
			 toErase.ptr = NULL;
			 delete toErase.ptr;
			 return it;
			 }
			 if (toErase == pHead) {
			 toErase.ptr->pNext->pPrev = pHead;
			 iterator it(toErase.ptr->pNext);
			 toErase.ptr = NULL;
			 delete toErase.ptr;
			 return it;
			 }
			 if (toErase == pTail) {
			 toErase.ptr->pPrev->pNext = NULL;
			 iterator it(toErase.ptr->pPrev);
			 toErase.ptr = NULL;
			 delete toErase.ptr;
			 return it;
			 }
			 return 0;*/
		}
		/*     void insert(iterator toInsert, T aValue) throw(const char*) {
		 if (pHead == NULL){
		 pHead = new node(aValue);
		 pTail = pHead;
		 }

		 }*/
		iterator insert(iterator var, T data) throw (const char*)
		{
			node* toReturn = new node;
			if (var.ptr != NULL)
			{
				if (var.ptr->pNext == NULL && var.ptr->pPrev == NULL)
				{
					toReturn->data = data;
					toReturn->pNext = pHead;
					pHead->pPrev = toReturn;
					pHead = toReturn;
					return toReturn;
				}
				else
				{
					toReturn->data = data;
					var.ptr->pPrev->pNext = toReturn;
					toReturn->pPrev = var.ptr->pPrev;
					var.ptr->pPrev = toReturn;
					toReturn->pNext = var.ptr;
					return toReturn;
				}
				return toReturn;
			}
			else
			{
				toReturn->data = data;
				pTail = toReturn;
				pHead = toReturn;
				return toReturn;
			}
		}
	};


}


#endif /* list_h */
