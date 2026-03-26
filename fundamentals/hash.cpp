#include <cstdio>
#include <iostream>
#include <vector>

class MyHashSet {

private:
  std::vector<int> HT;

private:
  int _hash(int key) { return key % HT.size(); }

public:
  MyHashSet() { HT.resize(1000, -1); }

  void add(int key) {
    int idx = _hash(key);
    this->HT[idx] = key;
  }

  void remove(int key) {
    int idx = _hash(key);
    if (!HT[idx])
      return;
    this->HT[idx] = 0;
  }

  bool contains(int key) {
    const int index = _hash(key);
    return HT[index] == key;
  }
};

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
-> closed hashing (open addressing): it does not increase the space of the
hashtable
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

int hash(int key) { return key % 10; };

void sorted_insert(ListNode **H, int key) {
  ListNode *t, *q = NULL, *p = *H;
  t = new ListNode{NULL, key};

  if (!*H) {
    *H = t;
  } else {
    while (p && p->data < key) {
      q = p;
      p = p->next;
    }

    if (q == NULL) {
      t->next = *H;
      *H = t;
    } else {
      t->next = p;
      q->next = t;
    }
  }
}

void insert(ListNode *ht[], int key) {
  const int idx = hash(key);
  std::cout << "idx: " << idx << "\n";
  sorted_insert(&ht[idx], key);
}

static ListNode *search(ListNode *const H, int key) {
  if (!H)
    return NULL;

  ListNode *p = H;
  while (p) {
    if (p->data == key)
      return p;
    p = p->next;
  }

  return NULL;
}

// open hashing
static void chaining() {
  // each value is mapped to an index on the hashtable, but, instead of storing
  // the element directly on that index, it is created a node on the heap. So a
  // linked list is used to "chain" the collisions in sorted order
  // the index returned by the hash function is just the head pointer (pointer
  // to the first node on the heap)

  constexpr int len = 10;
  struct ListNode *ht[len] = {};
  for (int i = 0; i < len; i++) {
    ht[i] = nullptr;
  }

  insert(ht, 12);
  insert(ht, 22);

  const ListNode *const n = search(ht[hash(22)], 22);

  if (n) {
    std::cout << "Node result: " << n->data << "\n";
  }
}

static int LP_hash(int key) { return key % 10; }

// closed hashing ( open addressing)
/*
  represented by: h'(x) = (h(x) + f(i)) % n
  where f(i) = i, i being = 0, 1, 2, ...
  and n is the length of the hashtable.
  h(x) always gets the "original" index. The f(i) increments i places from the
  original index.
  if (original index + i) is equal to n, then it restart the
  search from the start

  original index, and this search is circular via the mod operator

  this hash function runs until it gets a free space on the hashtable.
  each time it runs, i increments by one. And it is a circular function,
  so once it reaches the end of the array, it starts from the start again
*/

/*
  loading factor is always less then one on linear probing, because the
  hashtable has to have an empty space so the search algorithm works
    this loading factor should always be less than or equal to 0.5
    what means that the hashtable should always have half of it empty
    e.g: 10 keys, hashtable can only have 5 keys stored
    e.g: 20 keys, hashtable can only jave 10 keys stored

    avg successful search:
    t = 1/LF * ln(1/1-LF)

    avg unsuccessful search:
    t = 1/(1-LF)


    drawbacks:
    - space is wasted, because half of the hashtable must be vacant
    - keys can accumulate at one place, and this forms a cluster. This is called
  primary clustering. The bigger the cluster, the longer to find an element avg
  successful search considering primary clustering: 1/2 * (1+ 1/1-LF) avg
  unsuccessful search considering primary clustering: 1/1-LF

    delete:
      - for deletion, you should apply the hash function until found the key,
        then delete it, and then do a REHASHING. Shift the remaning keys is too
        complicated, it would need lots of verifications to check if some key
  would have to go after or before etc. so the idea of rehashing is to REINSERT
  in a new hashtable. So in linear probing deletion "does not exist". It is just
  not recommended, too time consuming

*/

#define SIZE 10

static int hash_LP(int key) { return key % 10; }

static int probe(int H[], int key) {
  int index = hash_LP(key);
  int i = 0;
  while (H[(index + i) % SIZE]) {
    i++;
  }

  return (index + i) % SIZE;
}

static void insert_LP(int H[], int key) {
  int index = hash_LP(key);
  if (H[index]) {
    index = probe(H, key);
  }

  H[index] = key;
}

static int search_LP(int H[], int key) {
  int index = hash_LP(key);
  for (int i = 0; i < SIZE; i++) {
    int probedIdx = (index + i) % SIZE;
    if (H[probedIdx] == key)
      return probedIdx;
    if (!H[probedIdx])
      return -1;
  }

  // in case the hashtable is full
  return -1;
}

static void linear_probing() {
  int HT[SIZE] = {0};
  insert_LP(HT, 12);
  insert_LP(HT, 25);
  insert_LP(HT, 35);
  insert_LP(HT, 26);

  for (int i = 0; i < SIZE; i++) {
    printf("Index %d: %d\n", i, HT[i]);
  }

  printf("Position of 35: %d\n", search_LP(HT, 35));
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

  chaining();
  printf("Linear probing\n");
  linear_probing();

  auto *hashset = new MyHashSet();
  hashset->contains(0);
  hashset->remove(0);
  std::cout << "Contains: " << hashset->contains(0) << "\n";
}
