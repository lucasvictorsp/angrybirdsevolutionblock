/* 
 * File:   Block.cpp
 * Author: Lucas Victor es71512
 * 
 * Created on 28 de Abril de 2016, 21:45
 */

#include "Block.h"

	//construtores:
/*Block::Block(){

}//*/

Block::Block(int id1, string nome, string mat, double x1, double y1) : id(id1), name(nome), material(mat), x(x1), y(y1){

}

Block::Block(Block & b){
	this->id = b.id;
	this->name = b.name;
	this->material = b.material;
	this->x = b.x;
	this->y = b.y;
}

	//gets:
int Block::getId() const{
	return (this->id);
}

string Block::getName() const{
	return (this->name);
}

string Block::getMaterial() const{
	return (this->material);
}

double Block::getX() const{
	return (this->x);
}

double Block::getY() const{
	return (this->y);
}

	//sets
void Block::setId(int id1){
	this->id = id1;
}

void Block::setName(string nome){
	this->name = nome;
}

void Block::setMaterial(string mat){
	this->material = mat;
}

void Block::setX(double x1){
	this->x = x1;
}

void Block::setY(double y1){
	this->y = y1;
}

	//Other Functions:


	//Sobrecarga de Operadores:
		//Atricuição:
Block& Block::operator=(const Block & b){
	if(this != & b){
		this->setId(b.getId());
		this->setName(b.getName());
		this->setMaterial(b.getMaterial());
		this->setX(b.getX());
		this->setY(b.getY());
	}
}

bool Block::operator==(const Block & b){
	if(this->getId() != b.getId() || this->getName() != b.getName() || this->getX() != b.getX() || this->getY() != b.getY()){
		return false;
	}

	return true;
}

	//Sobrecarga de Operadores:
ostream& operator<<(ostream & os , const Block & b){
	os << "Id: " << b.getId() << "\nNome: " << b.getName() << ", Material: " << b.getMaterial() << "\nX : " << b.getX() << " , Y: " << b.getY() << '\n';
	os << '\n';
}

	//Destrutor:
Block::~Block(){
	//cout << "DESTRUIU\n"; 
}