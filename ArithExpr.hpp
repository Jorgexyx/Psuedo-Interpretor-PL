/*
 Created by Ali A. Kooshesh on 2/5/19.
*/

#ifndef EXPRINTER_ARITHEXPR_HPP
#define EXPRINTER_ARITHEXPR_HPP

#include <vector>
#include "Token.hpp"
#include "SymTab.hpp"
#include "TypeDesc.hpp"
// Classes in this file define the internal representation of arithmetic expressions.


// An ExprNode serves as the base class (super class) for arithmetic expression.
// It forces the derived classes (subclasses) to implement two functions, print and
// evaluate.
 
class ExprNode {
public:
    ExprNode(Token token);
    Token token();
    virtual void print() = 0;
    virtual int evaluate(SymTab &symTab) = 0;
		virtual std::string strEval(SymTab &symTab) = 0;

private:
    Token _token;
};


// An InfixExprNode is useful to represent binary arithmetic operators.

 
class InfixExprNode: public ExprNode {  // An expression tree node.
	using ExprNode::token;
	public:
    InfixExprNode(Token tk);
    ExprNode *&left();
    ExprNode *&right();
    virtual void print();
    virtual int evaluate(SymTab &symTab);
		virtual std::string strEval(SymTab &symTab);

	private:
    ExprNode *_left, *_right;
};

// WholeNumber is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

 
class WholeNumber: public ExprNode {
using ExprNode::token;
public:
    WholeNumber(Token token);
    virtual void print();
    virtual int evaluate(SymTab &symTab);
		virtual std::string strEval(SymTab &symTab);
};

// Variable is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

 
class Variable: public ExprNode {
using ExprNode::token;
public:
    Variable(Token token);
    virtual void print();
    virtual int evaluate(SymTab &symTab);
	  virtual std::string strEval(SymTab &symTab);
};

class BoolExpr: public ExprNode {
public:
	BoolExpr(Token token);
	virtual void print();
	virtual int evaluate(SymTab &symTab);
	virtual std::string strEval(SymTab &symTab);
};

class RelExpr: public ExprNode {
using ExprNode::token;
public:
	RelExpr(Token token);
	virtual void print();
	virtual int evaluate(SymTab &symTab);
	virtual std::string strEval(SymTab &symTab);
};

 
class Str: public ExprNode {
using ExprNode::token;
public:
	Str(Token token);
	virtual void print();
	virtual int evaluate(SymTab &symTab);
	virtual std::string strEval(SymTab &symTab);
};

class ForSequence: public ExprNode {
public:
	ForSequence(Token);
	void setIters(std::vector<ExprNode *> *iters);
	void initIters(SymTab &symTab);
	void next(SymTab &symTab);
	virtual void print();
	virtual int evaluate(SymTab &symTab);
	virtual std::string strEval(SymTab &symTab);
private:
	std::vector<ExprNode *> *_iters;
	int step;
	int endVal;
	int startVal;
};
#endif //EXPRINTER_ARITHEXPR_HPP
