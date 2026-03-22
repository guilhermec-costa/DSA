#include <iostream>

// a hash function returns the target/mapped index in the hashtable

/* hash function one to one. no collision
 h(x) = x -> drawback: a lot of space is required

 hash function many to one using module operator
 h(x) = x % m (m is the length of the hashtable). less space is
required. The drawback: collision

Collision is when a hash function returns the same target index for different
values. So, two different values would be mapped to the same index

an ideal hash function is a mathematical function that maps an input to a
deterministic output, with minimal or 0 collisions


methods to avoid collision:
-> closed hashing: it does not increase the space of the hashtable
  -> linear probing
  -> quadratic probing
  -> double hashing
-> open hashing: consume extra space beyond the current space of the hashtable
  -> chaining
*/

int hash_one_to_one(int x) { return x; }
int hash_many_to_one(int x, int m) { return x % m; }

struct ListNode {
  ListNode *next = nullptr;
  int data;
};

/* loading factor: number of keys (n) / hashtable size (size)
e.g: n = 100, size = 10, so loading factor = 100 / 10 = 10
all the analysis made on hashing are based on the loading factor
it basically means how many elements are stored per index on the hashtable. It
is an assumption/expectation that the keys are uniformly distributed. It
estimates how many nodes there are per linked list

the loading factor is used for example on asymptotic notation, like bigO.

-------------------------------------------------
SEARCHING:

SUCCESS CASE:
  time = 1 (hash calculation) + O(loading factor/2);
  -> (loading factor / 2) is just an average time for search in the linked list

FAIL CASE:
  time = 1 (hash calculation) + O(loading factor)

DELETING/INSERT: same thing
-------------------------------------------------


the hash function is responsible for returning indexes in a way that the keys
are uniformly distributed ( not a fact, just the intention/assumption ) in the
hashtable. So the programmer must choose a good hash function for that
particular use case, he/she needs to have an ideia about the nature of the keys

*/

void chaining() {
  // each value is mapped to an index on the hashtable, but, instead of storing
  // the element directly on that index, it is created a node on the heap. So a
  // linked list is used to "chain" the collisions in sorted order
  // the index returned by the hash function is just the head pointer (pointer
  // to the first node on the heap)
}

void hash_main() {
  // hashing works by mapping each value on the keyspace to an index on a
  // hashtable. For this, there is a hash function, that calculates the target
  // index for a particular value

  /* horrible method: create an array of length n, n being the greatest element
    of the keyspace, then the value x in keyspace is mapped to the index x in
    hashtable
  */

  // values to be stored (domain)
  int keyspace[] = {8, 3, 6, 10, 15, 9, 4};
  int hashtable[15] = {0};

  // when writing to the hashtable, uses the hash function to get the index
  hashtable[hash_one_to_one(keyspace[2])] = keyspace[2];

  // when reading from the hashtable, uses the hash function to get the index
  std::cout << hashtable[hash_one_to_one(keyspace[2])] << "\n";

  // relation mappings
  // one - one -> function mapping = every key is mapped to one index in the
  // hashtable one - many many - one -> function mapping many - many
}