//
//  bst.h
//  bst
//
//  Created by josh Hellewell on 6/14/19.
//Copyright © 2019 Iron Buffalo. All rights reserved.
//

#ifndef bst_h
#define bst_h
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif


namespace custom {
	template< typename T > class BST {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif

		/*******************************************************************
		 * BNode Class
		 *
		 ********************************************************************/
	public:
		class BNode {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);
#endif
		public:
			T data;
			BNode* pLeft;
			BNode* pParent;
			BNode* pRight;


			BNode() {
				data = T();
				pLeft = NULL;
				pRight = NULL;
				pParent = NULL;
			}

			BNode(const T& aValue) {
				data = aValue;
				pLeft = NULL;
				pRight = NULL;
				pParent = NULL;
			}
			~BNode() {}

			BNode add(T& t) {

				if (pLeft == NULL && pRight == NULL) {
					BNode* newNode = new BNode(t);
					if (t < data) {
						newNode->pParent = this;
						pLeft = newNode;
						return *this;

					}
					else {
						newNode->pParent = this;
						pRight = newNode;
						return *this;
					}
				}
				if (t == data) {
					return *this;
				}

				else if (t < data) {
					if (pLeft == NULL) {
						BNode* newNode = new BNode(t);
						newNode->pParent = this;
						pLeft = newNode;
						return *this;
					}
					else
						return pLeft->add(t);
				}


				else {
					if (pRight == NULL) {
						BNode* newNode = new BNode(t);
						newNode->pParent = this;
						pRight = newNode;
						return *this;
					}
					else
						return pRight->add(t);
				}

				return *this;
			}

			BNode* search(T& t) {
				if (t != data && pLeft == NULL && pRight == NULL)
					return NULL;
				return t == data ? this : t < data ? pLeft->search(t) : pRight->search(t);
			}


		};// end of node class
		/*******************************************************************
		 * ITERATOR CLASS
		 *
		 ********************************************************************/
		class iterator {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);

#endif
			friend BST;
		public:
			BNode* ptr;


			iterator() {
				ptr = NULL;
			}

			iterator(BNode* aPtr) {
				ptr = aPtr;
			}

			iterator(const iterator& aIt) {
				ptr = aIt.ptr;
			}

			iterator operator = (BNode const* aPtr) {
				ptr = aPtr;
				return this;
			}

			bool operator == (iterator anIt) {
				return ptr == anIt.ptr;
			}

			bool operator != (iterator anIt) {
				return ptr != anIt.ptr;
			}

			// prefix increment
			iterator& operator ++ () throw (const char*)
			{
				// IF our ptr is NULL, don't increment from NULL, then the next address would be hexadecimal
				if (ptr == NULL) // IF we have a NULL BNode
				{
					throw ("Error: incrementing null node."); // Throw
				}
				else if (NULL != ptr->pRight)
				{
					ptr = ptr->pRight;

					while (NULL != ptr->pLeft)
					{
						ptr = ptr->pLeft;
						return *this;
					}
				}
				BNode* temp = ptr;
				ptr = ptr->pParent;

				if (ptr == NULL)
				{
					return *this;
				}
				if (temp == ptr->pLeft)
				{
					return *this;
				}
				while (NULL != ptr && temp == ptr->pRight)
				{
					temp = ptr;
					ptr = ptr->pParent;
				}

				return *this; // Return the this pointer of our iterator, returns an object by reference
			}
			// postfix increment
			iterator operator ++ (int postfix) throw (const char*)
			{
				BNode* rTemp = ptr;
				// IF our ptr is NULL, don't increment from NULL, then the next address would be hexadecimal
				if (!ptr) // IF NULL BNode
				{
					throw ("Error: incrementing null node.");
				}
				else if (NULL != ptr->pRight)
				{
					ptr = ptr->pRight;

					while (NULL != ptr->pLeft)
					{
						ptr = ptr->pLeft;
						return rTemp;
					}
				}
				BNode* temp = ptr;
				ptr = ptr->pParent;

				if (ptr == NULL)
				{
					return rTemp;
				}
				if (temp == ptr->pLeft)
				{
					return rTemp;
				}
				while (NULL != ptr && temp == ptr->pRight)
				{
					temp = ptr;
					ptr = ptr->pParent;
				}

				return rTemp; // Return the this pointer of our iterator, returns an object by reference
			}
			// postfix decrement
			iterator operator -- (T postfix) throw (const char*)
			{
				BNode* rTemp = ptr;
				// IF our ptr is NULL, don't increment from NULL, then the next address would be hexadecimal
				if (!ptr) // IF NULL BNode
				{
					throw ("Error: decrementing null node.");
				}
				else if (NULL != ptr->pLeft)
				{
					ptr = ptr->pLeft;

					while (NULL != ptr->pRight)
					{
						ptr = ptr->pRight;
						return rTemp;
					}
				}
				BNode* temp = ptr;
				ptr = ptr->pParent;

				if (ptr == NULL)
				{
					return rTemp;
				}
				if (temp == ptr->pRight)
				{
					return rTemp;
				}
				while (NULL != ptr && temp == ptr->pLeft)
				{
					temp = ptr;
					ptr = ptr->pParent;
				}
				return rTemp; // Return the this pointer of our iterator, returns an object by reference
			}

			// prefix decrement
			iterator& operator -- () throw (const char*)
			{
				// IF our ptr is NULL, don't increment from NULL, then the next address would be hexadecimal
				if (!ptr) // IF we have a NULL BNode
				{
					throw ("Error: decrementing null node."); // Throw
				}
				else if (NULL != ptr->pLeft)
				{
					ptr = ptr->pLeft;

					while (ptr->pRight)
					{
						ptr = ptr->pRight;
					}
					return *this;
				}
				BNode* temp = ptr;
				ptr = ptr->pParent;

				if (ptr == NULL)
				{
					return *this;
				}
				if (temp == ptr->pRight)
				{
					return *this;
				}
				while (NULL != ptr && temp == ptr->pLeft)
				{
					temp = ptr;
					ptr = ptr->pParent;
				}
				return *this;
			}


			T operator *() throw(const char*) {
				if (this->ptr == NULL)
					throw "Error: dereferencing null node.";
				return ptr->data;
			}
		}; // end of iterator class


	public:
		int numElements;
		BNode* root;

		BST() {
			root = NULL;
			numElements = 0;
		}

		/**************************************************
		 * copy() copy a binary node and traverse recursivly through the bst to copy
		 *************************************************/

		BNode* copyTree(const BNode* t) {
			if (t != NULL)
			{
				BNode* newNode = new BNode(t->data);
				newNode->pLeft = copyTree(t->pLeft);
				newNode->pRight = copyTree(t->pRight);

				if (newNode->pLeft != NULL)
				{
					newNode->pLeft->pParent = newNode;
				}
				if (newNode->pRight != NULL)
				{
					newNode->pRight->pParent = newNode;
				}
				return newNode;
			}
			else
			{
				return NULL;
			}
		}

		BST(const BST& rhs) {
			root = copyTree(rhs.root);
			numElements = rhs.numElements;
		}


		/*******************************************************************
		 * BST FUNCTIONS
		 *
		 ********************************************************************/
		BST& operator = (const BST& rhs) {

		}

		~BST()
		{
			while (root != NULL)
			{
				deleteBST(root);
			}
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

		void deleteBST(typename BNode*& head)
		{
			if (head == NULL)
				return;
			deleteBST(head->pLeft);
			deleteBST(head->pRight);
			delete head;
			head = NULL;
		}

		void clear() {
				deleteBST(root);
		}

		void insert(T aValue) throw(const char*) {
			if (numElements == 0) {
				BNode* newNode = new BNode(aValue);
				newNode->data = aValue;
				root = newNode;
				numElements++;
				return;
			}
			if (aValue == root->data)
				return;
			root->add(aValue);
			numElements++;

		}

		void erase(iterator & itElement) {
			if (end() == itElement)
			{
				return;
			}

			if (NULL == itElement.ptr->pLeft && NULL == itElement.ptr->pRight)
			{
				if (NULL != itElement.ptr->pParent && itElement.ptr == itElement.ptr->pParent->pLeft)
				{
					itElement.ptr->pParent->pLeft = NULL;
				}
				else if (NULL != itElement.ptr->pParent && itElement.ptr == itElement.ptr->pParent->pRight)
				{
					itElement.ptr->pParent->pRight = NULL;
				}
				else if (NULL == itElement.ptr->pParent)
				{
					root = NULL;
				}
			}
			else if (NULL == itElement.ptr->pLeft && NULL != itElement.ptr->pRight)
			{
				//check to see if the right side of the left child is null and the left side of the right child is Null
				itElement.ptr->pRight->pParent = itElement.ptr->pParent;
				if (NULL == itElement.ptr->pParent)
				{
					root = itElement.ptr->pRight->pParent;
				}
				else if ((NULL != itElement.ptr->pParent) && (itElement.ptr->pParent->pRight == itElement.ptr))
				{
					itElement.ptr->pParent->pRight = itElement.ptr->pRight;
				}
				else if ((NULL != itElement.ptr->pParent) && (itElement.ptr->pParent->pLeft == itElement.ptr))
				{
					itElement.ptr->pParent->pLeft = itElement.ptr->pRight;
				}

			}
			else if (NULL != itElement.ptr->pLeft && NULL == itElement.ptr->pRight)
			{
				itElement.ptr->pLeft->pParent = itElement.ptr->pParent;
				if (NULL == itElement.ptr->pParent)
				{
					root = itElement.ptr->pLeft->pParent;
				}
				else if ((NULL != itElement.ptr->pParent) && (itElement.ptr->pParent->pRight == itElement.ptr))
				{
					itElement.ptr->pParent->pRight = itElement.ptr->pRight;
				}
				else if ((NULL != itElement.ptr->pParent) && (itElement.ptr->pParent->pLeft == itElement.ptr))
				{
					itElement.ptr->pParent->pLeft = itElement.ptr->pRight;
				}
			}
			else if (NULL != itElement.ptr->pLeft && NULL != itElement.ptr->pRight)
			{
				BNode* temp = itElement.ptr->pRight;
				while (NULL != temp->pLeft)
				{
					temp = temp->pLeft;
				}
				if (temp->pRight != NULL)
				{
					temp->pRight->pParent = temp->pParent;
					temp->pParent->pLeft = temp->pRight;
				}
				else
					temp->pParent->pLeft = NULL;
				temp->pParent = itElement.ptr->pParent;
				if ((NULL != temp->pParent) && (itElement.ptr->pParent->pRight == itElement.ptr))
					temp->pParent->pRight = temp;
				else if ((temp->pParent != NULL) && (itElement.ptr->pParent->pLeft == itElement.ptr))
					temp->pParent->pLeft = temp;
				temp->pRight = itElement.ptr->pRight;
				temp->pRight->pParent = temp;
				temp->pLeft = itElement.ptr->pLeft;
				temp->pLeft->pParent = temp;
				if (NULL == temp->pParent)
				{
					root = temp;
				}
			}
			delete itElement.ptr;
			numElements--;
			return;
		}

		iterator find(T aValue) {
			if (numElements == 0)
				return NULL;
			return *(new iterator(root->search(aValue)));
		}


		iterator begin() {
			if (numElements == 0)
				return NULL;
			BNode * newNode = root;
			while (newNode->pLeft != NULL)
				newNode = newNode->pLeft;
			return newNode;
		}
		iterator end() {
			if (numElements == 0)
				return NULL;
			BNode * newNode = root;
			while (newNode->pRight != NULL)
				newNode = newNode->pRight;
			return newNode;
		}
	};
}
#endif /* bst_h */