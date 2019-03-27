/*
 Created by Ali A. Kooshesh on 2/5/19.
*/

#ifndef EXPRINTER_ARITHEXPR_HPP
#define EXPRINTER_ARITHEXPR_HPP

#include "Token.hpp"
#include "SymTab.hpp"
#include "TypeDesc.hpp"
// Classes in this file define the internal representation of arithmetic expressions.


// An ExprNode serves as the base class (super class) for arithmetic expression.
// It forces the derived classes (subclasses) to implement two functions, print and
// evaluate.
template <typename T>
class ExprNode {
public:
    ExprNode(Token token);
    Token token();
		//virtual std::string strEval();
    virtual void print() = 0;
    virtual int evaluate(SymTab<T> &symTab) = 0;

private:
    Token _token;
};


// An InfixExprNode is useful to represent binary arithmetic operators.

template <typename T>
class InfixExprNode: public ExprNode<T> {  // An expression tree node.
	using ExprNode<T>::token;
	public:
    InfixExprNode(Token tk);
    ExprNode<T> *&left();
    ExprNode<T> *&right();
    virtual void print();
    virtual int evaluate(SymTab<T> &symTab);

	private:
    ExprNode<T> *_left, *_right;
};

// WholeNumber is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

template <typename T>
class WholeNumber: public ExprNode<T> {
using ExprNode<T>::token;
public:
    WholeNumber(Token token);
    virtual void print();
    virtual int evaluate(SymTab<T> &symTab);
};

// Variable is a leaf-node in an expression tree. It corresponds to
// a terminal in the production rules of the grammar that describes the
// syntax of arithmetic expressions.

template <typename T>
class Variable: public ExprNode<T> {
using ExprNode<T>::token;
public:
    Variable(Token token);
    virtual void print();
    virtual int evaluate(SymTab<T> &symTab);
};

template <typename T>
class RelExpr: public ExprNode<T> {
using ExprNode<T>::token;
public:
	RelExpr(Token token);
	virtual void print();
	virtual int evaluate(SymTab<T> &symTab);
};

template <typename T>
class Str: public ExprNode<T> {
using ExprNode<T>::token;
public:
	Str(Token token);
	virtual void print();
	virtual int evaluate(SymTab<T> &symTab);
	std::string strEval(SymTab<T> &symTab);
};
#endif //EXPRINTER_ARITHEXPR_HPP
