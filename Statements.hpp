//
// Created by Ali A. Kooshesh on 2/5/19.
//

#ifndef EXPRINTER_STATEMENTS_HPP
#define EXPRINTER_STATEMENTS_HPP

#include <iostream>
#include <vector>

#include "ArithExpr.hpp"
#include "SymTab.hpp"

// The Statement (abstract) class serves as a super class for all statements that
// are defined in the language. Ultimately, statements have to be evaluated.
// Therefore, this class defines evaluate, a pure-virtual function to make
// sure that all subclasses of Statement provide an implementation for this
// function.

 
class Statement {
public:
    Statement();
    virtual void print() = 0;
    virtual void evaluate(SymTab &symTab) = 0;
};


// Statements is a collection of Statement. For example, all statements in a function
// can be represented by an instance of Statements.

 
class Statements {
public:
    Statements();

    void addStatement(Statement *statement);
    void evaluate(SymTab &symTab);

    void print();

private:
    std::vector<Statement *> _statements;
};

// AssignmentStatement represents the notion of an lValue having been assigned an rValue.
// The rValue is an expression.

 
class AssignmentStatement : public Statement {
public:
    AssignmentStatement();
    AssignmentStatement(std::string lhsVar, ExprNode *rhsExpr);
    AssignmentStatement(std::string lhsVar);

    std::string &lhsVariable();
    ExprNode *&rhsExpression();

    virtual void evaluate(SymTab &symTab);
    virtual void print();

private:
    std::string _lhsVariable;
    ExprNode *_rhsExpression;
};

// PrintStatement represents the notion of value being printed to stdin
 
class PrintStatement: public Statement {
public:
	//PrintStatement();
	//PrintStatement(ExprNode *);
	//PrintStatement(std::string var, ExprNode *);
	PrintStatement(std::vector<ExprNode *> *);
  //ExprNode *&valueVariable();
	virtual void evaluate(SymTab &symTab);
	virtual void print();
private:
	//std::string _Variable;
	std::vector <ExprNode *> *_nodes;
	//ExprNode *value;
};

// For Statement represents the notion of a loop
 
class ForStatement: public Statement {
public:
	ForStatement();
	ForStatement(ForSequence *seq, Statements *);
  Statements *&getSmts();
	//ForStatement(std::string var, exprNode *);
	virtual void evaluate(SymTab &);
	virtual void print();
private:
	Statements *_stmts;
	ForSequence *_seq;

};

// If Statement 
class IfStmt: public Statement {
public:
	IfStmt();
	IfStmt(std::vector<Statements *> *, std::vector<ExprNode *>*);
	virtual void evaluate(SymTab &);
	virtual void print();
private:
	std::vector<Statements *> *_stmts;
	std::vector<ExprNode *> *_relNodes;
};

#endif //EXPRINTER_STATEMENTS_HPP
