/* 
 * File:   Block.h
 * Author: Lucas Victor es71512
 * 
 * Created on 28 de Abril de 2016, 21:45
 */

#ifndef BLOCK_H
#define	BLOCK_H

#include <iostream>
#include <string> 
#include <cmath>

//using std::cerr;
//using std::cout;
using std::ostream;
using std::string;

class Block {
    friend ostream& operator<<(ostream & , const Block & );
	public:
			//construtores
		Block(int = -1, string = "", string = "", double = HUGE_VAL, double = HUGE_VAL); // esta declaração de construtor incluie também a declaração Block(), pois todos os parametros tem valores iniciais
		Block(Block & );

			//gets
		int getId() const;
		string getName() const;
		string getMaterial() const;
		double getX() const;
		double getY() const;

			//sets
		void setId(int );
		void setName(string );
		void setMaterial(string );
		void setX(double );
		void setY(double );

			//Sobregarga de Operadores:
		Block& operator=(const Block & );
		bool operator==(const Block & );

			//Other funcitions

			//Destrutor
		~Block();

	private:
		int id;
		string name;
		string material;
		double x;
		double y;
};
#endif	/* BLOCK_H */