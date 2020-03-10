//
//  linked_list.h
//  linked list
//
//  Created by josh Hellewell on 5/29/19.
//Copyright © 2019 Iron Buffalo. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h


#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif


namespace custom {
	template< typename T > class node {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif

	public:
		node* pNext;
		node* pPrev;
		T data;

		node() {
			data = 0;
			pNext = NULL;
			pPrev = NULL;
		}

		node(T data) {
			this->data = data;
			pNext = NULL;
			pPrev = NULL;
		}

	};
	template <class T>
	/*******************************************************************
	 * INSERT:
	 *        Insert a value into the linked list
	 ********************************************************************/
	node <T>* insert(node <T>* pNode, const T& t,
		bool after = false) throw (const char*) {
		if(pNode == NULL)
			throw "Error: inserting into NULL list.";
		node<T>* pNew = new node<T>(t);
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

	template <class T>
	/*******************************************************************
	 * FIND:
	 *        Find a given value within the linked list
	 ********************************************************************/
	node <T>* find(node <T>* pHead, const T& t) {
		for (node<T>* p = pHead; p; p = p->pNext)
			if(p->data == t)
				return p;
		return NULL;
		
	}

	template <class T>
	/*******************************************************************
	 *  CLEAR:
	 *        Delete the entire list
	 ********************************************************************/
	void clear(node <T>*& pHead) throw (const char*) {
		if(pHead == NULL)
			throw "Error: freeing NULL list.";
		while (pHead != NULL)
		{
			node<T>* pDelete;
			pDelete = pHead;
			pHead = pHead->pNext;
			delete pDelete;
		}
		
	}

	template <class T>
	/*******************************************************************
	 * COPY:
	 *        Copy one list and store it in another
	 ********************************************************************/
		node <T>* copy(node <T>* pSource) {
			if (pSource == NULL)
				return NULL;
			else {
				node <T>* pDestination = new node<T>(pSource->data);
				node<T>* pSrc = pSource;
				node<T>* pDes = pDestination;
				for (node<T>* p = pSrc->pNext; p; p = p->pNext)
					pDes = insert(pDes, p->data, true);
				return pDestination;
			};
	}

	template <class T>
	/*******************************************************************
	 * REMOVE:
	 *        Remove a single node from the list and the update what it
	 *        points to
	 ********************************************************************/
	node <T> * remove(const node <T> * pRemove) {
		if (pRemove == NULL)
			return NULL;
		
		if (pRemove->pPrev == NULL && pRemove->pNext == NULL) {
			delete pRemove;
				return NULL;
		};

		if (pRemove->pPrev)
			pRemove->pPrev->pNext = pRemove->pNext;
		if (pRemove->pNext)
			pRemove->pNext->pPrev = pRemove->pPrev;

		node <T>* pReturn = new node<T>;

		if (pRemove->pPrev) 
			pReturn = pRemove->pPrev;
		else 
			pReturn = pRemove->pNext;

		delete pRemove;
		return pReturn;
	}
}

#endif /* linked_list_h */
