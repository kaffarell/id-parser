# Parser for id-files
The parser can get values and store them in variables and overwrite values.
A Parser for .id files which can store any type of data like age and names.
External file with variable names, so the customer can safely and easily set deeper settings for your product.   

## How to use
### Getting Values:
Example on how to read with the parser:

    #include<stdio.h>  
    #include"parser.h"  
      
    int main(){  
        int result;  
        char* input;  
      
        FILE id;  
        id = init("/home/gabriel/CLionProjects/id_parser/test.id");  
        printf("input identifier: \n");  
        scanf("%s", input);  
        result = valueof_int(input);  
        printf("value of identifier: %d \n", result);  
        return 0;  
    }
 * Step 1:
	 * create FILE object ( f.e.: FILE id; ).
* Step 2:
	* init the object with the file name (or path) ( f.e.: id = init("test.id") ).
* Step 3:
	* get integer ( f.e.: result = valueof_int("age") ) = value of identifier age is now stored in the integer result.
	* get string ( f.e.: result = valueof_string("name") ) = stores string of name in the variable result.  
	* get float ( f.e: result = valueof_float("pi")) = stores float of pi in variable.

### Writing values
Same steps as above but use the function write().
The function write(char* identifier, int value), takes the identifier as a char array and the new value as a integer. The value will than be written to the identifier specified.

    write("id", 5);


## Id-files  
### Structure
The first tag of the id file is the `>version:<version number>`.  
Examples: `>version:0.3.1`, `>version:0.2.2`.  
The values are stored as followed:  
`identifier = value`  
The first argument is a char* which represents the identifier or tag. In the code you will also get the value by calling this
 identifier. The value can be a integer or a string.


### Example of id-files
File: personal.id

    >version:0.3.1
    
    min_age = 18
    max_age = 99
    pass_number = 1945
    health_card_number = 4576
    name = Jake
    surname = Pichai
    height: 1.80
File: constants.id

    >version:0.2.2
    
    pi = 3.141592
    e = 27
    c_speed = 2997
    constant = pi

    
### Compile with gcc parser.c main.c -lm