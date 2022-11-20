#include "project04.h"

// Tree that evaluates the left and right nodes
int eval_tree(struct parse_node_st *node) {
	if (node->type == EX_INTVAL) {
		return node->intval.value;
    } else if (node->type == EX_OPER2) {
    	int left = eval_tree(node->oper2.left);
        int right = eval_tree(node->oper2.right);
        if (node->oper2.oper == OP_PLUS) {
            return left + right;
        } else if (node->oper2.oper == OP_PLUS) {
            return left + right;
        } else if (node->oper2.oper == OP_MINUS) {
            return left - right;
        } else if (node->oper2.oper == OP_MULT) {
            return left * right;
        } else if (node->oper2.oper == OP_DIV) {
            return left / right;
        } else if (node->oper2.oper == OP_RSHIFT) {
            return left >>  right;
        } else if (node->oper2.oper == OP_LSHIFT) {
            return left << right;
        }  else if (node->oper2.oper == OP_AND) {
            return left & right;
        } else if (node->oper2.oper == OP_OR) {
            return left | right;
        } else if (node->oper2.oper == OP_XOR) {
        	return left ^ right;
    	}
    } else if (node->type == EX_OPER1) {
		int val = eval_tree(node->oper1.operand);
	    if (node->oper1.oper == OP_MINUS) {
	      	return -1 * val;
	    } else if (node->oper1.oper == OP_NOT) {
	        return ~val;
	    }
    }
}
