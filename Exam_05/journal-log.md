##SUBTYPE POLYMORPHISM - ABSTRACT CLASSES - INTERFACES - VIRTUAL BEHAVIOUR - INHERITANCE

2 LAYERS : from inheritance to composition.

1 - make 2 searchable concrete bags: array and binary tree;
		reuse behaviour through wrapping not only inheritance. 

2 - wrap a searchable bag and expose set behaviour - turn it into a set;
	SET is a wrapper/adaptor around bag object, not a derived bag;

	bag allows duplicetes / set not - same storage system but different insert logic - check value existence


SET: ADT

std::unordered_set -> count() or find(); ->memebership - no duplicates

bag abstract-class-interface: PURE VIRTUAL member functions -implementation inside derived classes
	 - cannot instantiate bag
diamond trap:
	derived calsses - virtual inheritance : 
	virtual public bag -> bag doesn't get multiplied, but once shared copy.

multiple inheritance: two derived classes inherit from two classes = storage + search method to implement;

polymorphism: main- uses base pointer to allocate new derived objects; method is called from each derived class at runtime->searchable_tree_bag::has(); ->virtual means runtime dispatch ->compiler looks at the obj type at runtime anc calls derived class member function, not the base class/interface.

composition: set wraps searchable_bag - HAS-A relationship.
if class set() : {} then -
wrapper-adapter - pure composition Has-A bag, but doesn't inhert from bag - means
I can't pass set to any function.
if class set() : public searchable_bag {} then -
decorator pattern: inheritance and holds a pointer to searchable_bag -> means
Is-A and Has-A -> set can be passed to any function that expects normal bag.

diamond problem : virtual inheritance


concept: method overloading -> two insert methods

concept: dynamic dispatch - runtime polymorpgism

Design pattern : how the obj is copied - assigned - compared (rule of 3)
value semantics - copy-by-value -  obj represents a pure value;
 - indipendent memories;
 - equality based on state, not identity;

## SYNTAX: bigint ##
	string operationss
	s.lenght() 			- get size
	s[i] 				- access char
	s += 'c' 			- append char
	s.substr(start) 	- substr from start
	s.substr(start, len)- substr with len

	char-int
	'3' - '0' = 3 		- char to int
	char('0' + 3) = '3'	- int to char

	loops
	for (size_t i = 0; i < n; i++)
	for (size_t i = n; i > 0; i--)
	while (cond) {}

	chaining
	return *this 		- ref to modified obj


stirng class -> basic_string - generalized template uses char: all methods operate
in terms of bytes. 
it has member funcitons: 
	- iterators
	- capacity
	- element access
	- modifiers
	- string operations
it has member const - npos(max size_t value)
it has non-member func overloads
size_t -> unsigned int type able to represent any obj in bytes (sizes and counts)
#include <cstddef>

1. REVERSE → PROCESS → REVERSE BACK
   This pattern lets us work left-to-right in code
   while doing right-to-left addition conceptually
 
2. CARRY IS CRUCIAL
   The carry propagates through the entire number
   Must check "carry > 0" to catch final carry
 
3. HANDLE DIFFERENT LENGTHS
   Use 0 for missing digits when one number is shorter
 
4. MODULO AND DIVISION
   % 10 extracts ones digit
   / 10 extracts carry
 
5. CHARACTER ARITHMETIC
   - '0' converts int→char
   + '0' converts char→int