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

## SYNTAX: ##
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
 

