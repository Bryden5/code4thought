#include <iostream>
#include <string>
using namespace std;

class Element
{
	public:
		virtual void accept(class Visitor &v) = 0;
};

class Someone: public Element
{
	public:
		virtual void accept(Visitor &v);
		string someone()
		{
			return "Someone";
		}
};

class Nobody: public Element
{
	public:
		virtual void accept(Visitor &v);
		string nobody()
		{
			return "Nobody";
		}
};

class Somebody: public Element
{
	public:
		virtual void accept(Visitor &v);
		string somebody()
		{
			return "Somebody";
		}
};

class Visitor
{
	public:
		virtual void visit(Someone *e) = 0;
		virtual void visit(Nobody *e) = 0;
		virtual void visit(Somebody *e) = 0;	
};

void Someone::accept(Visitor &v)
{
	v.visit(this);
}
void Nobody::accept(Visitor &v)
{
	v.visit(this);
}
void Somebody::accept(Visitor &v)
{
	v.visit(this);
}

class KnockKnock: public Visitor
{
	void visit(Someone *e){
		cout << e->someone() + "'s at the door!" << '\n';
	}
	void visit(Nobody *e){
		cout << e->nobody() + "'s at the door!" << '\n';
	}
	void visit(Somebody *e){
		cout << e->somebody() + "'s at the door!" << '\n';
	}
};

int main()
{
	Element *list[] = {new Someone(), new Nobody(), new Somebody()};
	
	KnockKnock someGuy;
	
	for(int i = 0;i < 3;i++)
		list[i]->accept(someGuy);
}




