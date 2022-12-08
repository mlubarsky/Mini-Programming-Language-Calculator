#include "project04.h"

void int_to_string(int number, int base) {
	unsigned int negative = number;	
	char *buff;
	// Convert decimal
	if (base == 10) {
		int i = 0;
		buff = malloc(32);
		while (number != 0) {
			buff[i] = (number % base) + 48; 
			number = number / base;
			i++;
		} 
		buff[strlen(buff)] = '\0';
		for (int i = strlen(buff) - 1; i >= 0; i--) {
			printf("%c", buff[i]);
		}
	// Convert binary
	} else if(base == 2) {
		int i = 0;
		int j = 32;
		buff = malloc(32);
		while (j != 0) {
			buff[i] = (number % base) + 48;
			number = number / base;
			i++;
			j--;
		} 
		buff[strlen(buff)] = '\0';
		printf("0b");
		for (int i = strlen(buff) - 1; i >= 0; i--) {
			printf("%c", buff[i]);
		}
	// Convert hexadecimal
	} else if(base == 16) {
		int i = 0;
		int j = 8;
		buff = malloc(32);
		while (j != 0) {
			if (((negative % base) <= 9)) {
				buff[i] = (negative % base) + 48;
			} else {
				buff[i] = (negative % base) + 55;
			}
			negative /= base;
			i++;
			j--;
		} 
		buff[strlen(buff)] = '\0';
		printf("0x");
		for (int i = strlen(buff) - 1; i >= 0; i--) {
			printf("%c", buff[i]);
		}
	} 
	// Free allocated buffer memory
	free(buff);
}

int main(int argc, char **argv) {

    	struct scan_table_st scan_table; // Table of tokens
    	struct parse_table_st parse_table; // Table of parse nodes
   	struct parse_node_st *parse_tree; // Tree (pointers only) of parse nodes

    	char input[SCAN_INPUT_LEN];
    	int len;

    	// Parse for the command line arguments
    	int base = 10;
    	for (int i = 1; i < argc; i++) {
    		if (!strncmp(argv[i], "-b", 2)) {
    			base = atoi(argv[i + 1]);
    			i++;
    		} else if (!strncmp(argv[i], "-e", 2)) {
   			strncpy(input, argv[i + 1], SCAN_INPUT_LEN);
   			len = strnlen(input, SCAN_INPUT_LEN);
    			i++;
    		}
    	}

    	// Scanning
    	scan_table_init(&scan_table);
    	scan_table_scan(&scan_table, input, len);

    	// Parsing
    	parse_table_init(&parse_table);
    	parse_tree = parse_program(&scan_table);
	
    	// Evaluating
	int output_number =  eval_tree(parse_tree);
    	int_to_string(output_number, base);
    	printf("\n");
    
    	return 0;
}
