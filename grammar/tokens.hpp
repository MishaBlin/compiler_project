#ifndef TOKENS_HPP
#define TOKENS_HPP

enum yytokentype {
  YYEOF,        // end of file
  PLUS,         // "+"
  MINUS,        // "-"
  MULT,         // "*"
  COMMENT,      // //
  DIV,          // "/"
  ASSIGNMENT,   // ":="
  RANGE,        // ".."
  COLON,        // ":"
  SEMICOLON,    // ";"
  EQ,           // "="
  NEQ,          // "/="
  LT,           // "<"
  LTE,          // "<="
  GT,           // ">"
  GTE,          // ">="
  IMPLICATION,  // "=>"
  AND,          // "and"
  OR,           // "or"
  XOR,          // "xor"
  NOT,          // "not"
  VAR,          // "var"
  IS,           // "is"
  THEN,         // "then"
  EMPTY,        // "empty"
  END,          // "end"
  FUNCTION,     // "func"
  IN,           // "in"
  LOOP,         // "loop"
  FOR,          // "for"
  WHILE,        // "while"
  IF,           // "if"
  ELSE,         // "else"
  TRUE,         // "true"
  FALSE,        // "false"
  RETURN,       // "return"
  INT,          // "int"
  REAL,         // "real"
  BOOL,         // "bool"
  STRING,       // "string"

  INT_LITERAL,   // {integer} literals
  REAL_LITERAL,  // {real} literals
  IDENTIFIER,    // {identifier}

  LEFT_BR,      // "("
  RIGHT_BR,     // ")"
  DOT,          // "."
  LEFT_SQ_BR,   // "["
  RIGHT_SQ_BR,  // "]"
  COMMA,        // ","
  QUOTE,        // "\""

  INVALID_CHARACTER  // Any unrecognized character
};

const char* tokenToString(enum yytokentype token) {
  switch (token) {
    case PLUS:
      return "PLUS";
    case MINUS:
      return "MINUS";
    case MULT:
      return "MULT";
    case COMMENT:
      return "COMMENT";
    case DIV:
      return "DIV";
    case ASSIGNMENT:
      return "ASSIGNMENT";
    case RANGE:
      return "RANGE";
    case COLON:
      return "COLON";
    case SEMICOLON:
      return "SEMICOLON";
    case EQ:
      return "EQ";
    case NEQ:
      return "NEQ";
    case LT:
      return "LT";
    case LTE:
      return "LTE";
    case GT:
      return "GT";
    case GTE:
      return "GTE";
    case IMPLICATION:
      return "IMPLICATION";
    case AND:
      return "AND";
    case OR:
      return "OR";
    case XOR:
      return "XOR";
    case NOT:
      return "NOT";
    case VAR:
      return "VAR";
    case IS:
      return "IS";
    case THEN:
      return "THEN";
    case EMPTY:
      return "EMPTY";
    case END:
      return "END";
    case FUNCTION:
      return "FUNCTION";
    case IN:
      return "IN";
    case LOOP:
      return "LOOP";
    case FOR:
      return "FOR";
    case WHILE:
      return "WHILE";
    case IF:
      return "IF";
    case ELSE:
      return "ELSE";
    case TRUE:
      return "TRUE";
    case FALSE:
      return "FALSE";
    case RETURN:
      return "RETURN";
    case INT:
      return "INT";
    case REAL:
      return "REAL";
    case BOOL:
      return "BOOL";
    case STRING:
      return "STRING";
    case INT_LITERAL:
      return "INT_LITERAL";
    case REAL_LITERAL:
      return "REAL_LITERAL";
    case IDENTIFIER:
      return "IDENTIFIER";
    case LEFT_BR:
      return "LEFT_BR";
    case RIGHT_BR:
      return "RIGHT_BR";
    case DOT:
      return "DOT";
    case LEFT_SQ_BR:
      return "LEFT_SQ_BR";
    case RIGHT_SQ_BR:
      return "RIGHT_SQ_BR";
    case COMMA:
      return "COMMA";
    case QUOTE:
      return "QUOTE";
    case INVALID_CHARACTER:
      return "INVALID_CHARACTER";
    default:
      return "UNKNOWN_TOKEN";
  }
}

#endif  // TOKENS_HPP
