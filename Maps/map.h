//    MAP
//  map.h
//
//  Created by josh Hellewell on 6/14/19.
//Copyright © 2019 Iron Buffalo. All rights reserved.
//

#ifndef map_h
#define map_h

#include "bst.h"
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
	template< typename K, typename V > class map {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif

	public:
		class pair {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);
#endif
		public:
			K first;
			V second;

			//-----------------------------------------
			// Constructor
			//-----------------------------------------
			pair() {
				first = K();
				second = V();
			}

			pair(int t) : first(), second() {}
			pair(const K& first, const V& second) : first(first), second(second) {}
			pair(const pair& rhs) : first(rhs.first), second(rhs.second) {}

			pair operator = (pair rhs) {
				this->first = rhs.first;
				this->second = rhs.second;
				return *this;
			}

			bool operator >(pair rhs) {
				return first > rhs.first;
			}
			bool operator < (pair rhs) {
				return first < rhs.first;
			}

			bool operator== (pair rhs) {
				return first == rhs.first;
			}

			bool operator>= (pair rhs) {
				return first >= rhs.first;
			}

			bool operator<= (pair rhs) {
				return first <= rhs.first;
			}
		};// End Pair
		class iterator {
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);
#endif
		private:
			typename BST<map::pair>::iterator it;
		public:
			iterator() {
				it = NULL;
			}
			iterator(const iterator& rhs) {
				it = rhs.it;
			}

			iterator operator = (const iterator& rhs) {
				it = rhs.it;
				return *this;
			}
			bool operator == (const iterator& it) {
				return true;
			}
			bool operator != (const iterator& anIt) {
				return it != anIt.it;
			}
			//prefix operator
			iterator& operator ++ () throw (const char*)
			{
				if (it == NULL)
				{
					throw ("Error: Incrementing null node.");
				}
				it++;
				return *this;

			}

			// postfix increment
			iterator operator ++ (int postfix) throw (const char*)
			{
				if (it == NULL)
				{
					throw ("Error: Incrementing null node.");
				}
				postfix++;
				return *this;
			}
			// postfix decrement
			iterator operator -- (int postfix) throw (const char*)
			{
				if (it == NULL)
				{
					throw ("Error: Decrementing null node.");
				}
				postfix--;
				return *this;
			}

			// prefix decrement
			iterator& operator -- () throw (const char*)
			{
				if (it == NULL)
				{
					throw ("Error: Decrementing null node.");
				}
				it--;
				return *this;
			}

			pair operator *() throw(const char*) {
				if (it == NULL)
					throw ("Error: Dereferencing null node.");
				return *it;
			}
		};

	private:
		BST<map::pair> bst;
		BST<pair> bs;

	public:


		map() {

		}
		~map() {

		}
		int size() {
			return bst.numElements;
		}
		int empty() {
			return !bst.numElements;
		}
		void clear() {
			bst.clear();
			bst.numElements = 0;
		}
		iterator find(K& k) {
			pair temp = pair(k, V());
			iterator it = bst.find(temp);
			return it;
		}
		

		void insert(const K& aKey, const V& aValue)
        {
           /* pair temp = pair(aKey, aValue);
            bst.insert(temp);*/
        }
        void insert(pair pair) {bst.insert(pair); }
        iterator find(K key)
        {
            /*pair tempPair = pair(key, V());
            iterator it(bst.find(tempPair));
            iterator temp(it);
            return temp;*/
        }

		V& operator [] (K key) throw (const char*)
		{
			//iterator temp = bst.find(key);
			////If the specified key is not there, then add it
			//if (temp == bst.end())
			//{
			//	pair tempPair = pair(key, V());
			//	insert(tempPair);
			//	temp = find(key);
			//}
			//return *temp;
		}

		V operator[](const K& aKey)const {
			iterator it = bst.find(aKey);
			return *(new V());
		}
		map operator = (const map& rhs) {
			this = rhs;
			return this;
		}

	};
}

#endif /* map_h */

