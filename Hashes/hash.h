//    Hash
//  hash.h
//
//  Created by the Buffalo Gang on 7/3/19.
//Copyright � 2019 Iron Buffalo. All rights reserved.
//

#ifndef map_h
#define map_h

#include "list.h"
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom {
    template< typename T> class Hash {
#ifdef UNIT_TESTING
        friend int ::main(int argc, const char* argv[]);
#endif
        
    private:
        list <T> ** table;
        int numElements;
        int numBuckets;
        
    public:
        Hash(long someBuckets) {
            if (someBuckets <= 0) {
                throw "Error: Hashes must have at least 1 bucket.";
            }
            table = new list<T>*[someBuckets];
            for (int i = 0; i < someBuckets; i++) {
                table[i] = new list<T>();
            }
            this->numElements = 0;
            this->numBuckets = someBuckets;
            
        }
        
        Hash(const Hash& rhs) {
            if (rhs.numBuckets <= 0) {
                throw "Error: Hashes must have at least 1 bucket.";
            }
            table = new list<T> * [rhs.numBuckets];
            int i;
            for (i = 0; i < rhs.numBuckets; i++) {
                table[i] = new list<T>(*rhs.table[i]);
            }
            
            
            this->numElements = rhs.numElements;
            this->numBuckets = rhs.numBuckets;
        }
        
        ~Hash() {
            
        }
        
        int size() {
            return numElements;
            
        }
        long capacity() {
            return numBuckets;
        }
        bool empty() {
            return !numElements;
        }
        bool find(const T& aValue, long (*hashFunc)(const T&, long)) {
            long i = hashFunc(aValue, numBuckets);
            int j = i % numBuckets;
            if (table[j]->find(aValue) != NULL)
                return true;
            else
                return false;
        }
        void insert(const T& aValue, long (*hashFunc) (const T&, long)) {
            long i = hashFunc(aValue, numBuckets);
            int j = i % numBuckets;
            table[j]->push_back(aValue);
            numElements++;
        }
        
		Hash& operator = (const Hash& rhs) {
			if (this->numElements != 0) {
				int i = 0;
				while (numElements != 1) {

					delete table[i];
					i++;
					numElements--;
				}
			}
			numBuckets = rhs.numBuckets;
			numElements = rhs.numElements;
			this->table = rhs.table;
			return *this;
		}
    };
};

#endif /* hash_h */
