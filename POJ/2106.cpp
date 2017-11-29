#include <cstdio> 
#include <cstdlib> 

using namespace std; 

/* 
 * LL(1) Grammar
 * expr			: sub expr_rest 
 *
 * expr_rest	: | sub expr_rest 
 * 				| ¦Å
 *
 * sub 			: term sub_rest 
 *
 * sub_rest		: & term sub_rest 
 *				| ¦Å
 *
 * term 		: ! term 
 * 				| atom
 *
 * atom 		: (expr) 
 * 				| V 
 * 				| F 
 * 
 * Pitfall: 
 * 		bool val = left_operand && term();  // lazy evaluation, or 
 * 		bool val = left_operand || sub(); 
 */ 

char lookahead = '$'; 

void match(char c) { 
	if (lookahead != c) { 
		// ERROR 
	}
	if (c == '\n') { 
		lookahead = '$'; 
		return; 
	}
	lookahead = getchar(); 
	while (lookahead == ' ') { 
		lookahead = getchar(); 
	}
}

bool expr(); 
bool expr_rest(bool left_operand); 
bool sub(); 
bool sub_rest(bool left_operand); 
bool term(); 
bool atom(); 

void line() { 
	if (expr()) { 
		printf("V\n"); 
	}
	else { 
		printf("F\n"); 
	}
	match('\n'); 
}

bool expr() { 
	bool left_operand = sub(); 
	return expr_rest(left_operand); 
}

bool expr_rest(bool left_operand) { 
	if (lookahead == '|') { 
		match('|'); 
		bool right_operand = sub(); 
		return expr_rest(left_operand || right_operand); 
	}
	else { 
		return left_operand; 
	}
}

bool sub() { 
	bool left_operand = term(); 
	return sub_rest(left_operand); 
}

bool sub_rest(bool left_operand) { 
	if (lookahead == '&') { 
		match('&'); 
		bool right_operand = term(); 
		return sub_rest(left_operand && right_operand); 
	}
	else { 
		return left_operand; 
	}
}

bool term() { 
	if (lookahead == '!') { 
		match('!');
		return !term(); 
	}
	else { 
		return atom(); 
	}
}

bool atom() { 
	if (lookahead == '(') { 
		match('('); 
		bool val = expr(); 
		match(')'); 
		return val; 
	}
	else if (lookahead == 'V') { 
		match('V'); 
		return true; 
	}
	else if (lookahead == 'F') { 
		match('F'); 
		return false; 
	}
	else { 
		printf("Symbol Error\n"); 
		exit(1); 
	}
}

int main() { 
	int t = 0; 
	while (1) { 
		lookahead = getchar(); 
		if (lookahead == EOF) { 
			break; 
		}
		printf("Expression %d: ", ++t); 
		line(); 
	}
}