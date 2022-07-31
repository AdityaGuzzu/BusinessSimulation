This branch is made to tackle the following problem:
1.) 	In the current, method used in main branch, We used a pointer array of type 
	base class. But in almost all the functions, we needed to access the derived class' 
	elements. This lead to compilation error.
2.)	There are other minor errors.

The solution:
1.)	Use the attributes of tickets and white tickets inside the block class instead
	of defining a separate class for them.
2.) 	General Blocks will still be derived from block class.
3.) 	In the game file, Create all the objects of general blocks and tickets and then
	assign their addresses to a pointer array of type block.
