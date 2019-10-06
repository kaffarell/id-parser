
# Parser for id-files
Supports at the moment only read and store in variable functionality.   
A Parser for .id files which can store any type of data like age and names.
External file with variable names, so the customer can safely and easily set deeper settings for your product.   

## How to use
Example on how to use the parser:

    #include<stdio.h>  
    #include"parser.h"  
      
    int main(){  
	int result;  
	char* input;  
      
	FILE id;  
	id = init("/home/gabriel/CLionProjects/id_parser/test.id", "r");  
	printf("input identifier: \n");  
      	scanf("%s", input);  
      	result = valueof_int(input);  
      	printf("value of identifier: %d \n", result);  
     	return 0;  
    }
 * Step 1:
	 * create FILE object ( f.e.: FILE id; )
* Step 2:
	* init the object with the file name (or path) and the read:'r' or write:'w' mode ( f.e.: id = init("test.id", "r") )
* Step 3:
	* get value ( f.e.: result = valueof_int("age") ) = value of identifier age is now stored in the integer result

## Id-files  
### Structure
`identifier = value`
The first argument is a char* which represents the identifier or tag. Later you will also get the value by calling this
 identifier. The value can be a any integer. Support for strings or chars is coming!  


### Example of id-files
File: personal.id

    min_age = 18
    max_age = 99
    pass_number = 194578
    health_card_number = 457683
File: constants.id

    pi = 31415
    e = 27
    c_speed = 299792
