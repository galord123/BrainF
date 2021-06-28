# BrainF
As the name suggests, this project is a compiler from the BrainF**k language to c.

The compiler also supports extended BrainF operations(type I) and file support!!.



### Commands Avaible
#### Regular BrainF command support:

  - \>	increment the data pointer (to point to the next cell to the right).
  - \<	decrement the data pointer (to point to the next cell to the left).
  - \+	increment (increase by one) the byte at the data pointer.
  - \-	decrement (decrease by one) the byte at the data pointer.
  - .	output the byte at the data pointer.
  - ,	accept one byte of input, storing its value in the byte at the data pointer.
  - [	if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
  - ]	if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.

#### Extended type I
>The nine Extended Type I language commands, each consisting of a single character:

  - @	Ends the program, generally used as a separator between code and data.
  - $1	Overwrites the byte in storage with the byte at the pointer.
  - !1	Overwrites the byte at the pointer with the byte in storage.
  - }	Performs a single right logical shift of the byte at the pointer.
  - {	Performs a single left logical shift of the byte at the pointer.
  - ~	Performs a bitwise NOT operation on the byte at the pointer (all 1's and 0's are swapped).
  - ^	Performs a bitwise XOR operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
  - &	Performs a bitwise AND operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
  - |	Performs a bitwise OR operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
  
1. Storage — The number in storage can only be changed by using a $ command, operations take place in the cell, not in storage.

#### File support!!
> you can read and write files! 
  - \# open/close file. the file name will be taken in the following way: the number of characters to read in the current cell, the characters in the following cells  
  - ; reads one byte from the file, to the current cell
  - : write one file to the file

