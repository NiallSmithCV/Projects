//Niall Smith
//Student ID: 912370187



#include "Ship.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//member function definitions

AircraftCarrier::AircraftCarrier(int x1, int y1, int x2, int y2)
{
	this->setPos(x1,y1,x2,y2);
	lev=5;
}

BattleShip::BattleShip(int x1, int y1, int x2, int y2)
{
	this->setPos(x1,y1,x2,y2);
	lev=4;
}

Cruiser::Cruiser(int x1, int y1, int x2, int y2)
{
	this->setPos(x1,y1,x2,y2);
	lev=3;
}

Destroyer::Destroyer(int x1, int y1, int x2, int y2)
{
	this->setPos(x1,y1,x2,y2);
	lev=2;
}


const char* AircraftCarrier::name(void) const
{
	return "AircraftCarrier";
}

const char* BattleShip::name(void) const
{
	return "BattleShip";
}
const char* Cruiser::name(void) const
{
	return "Cruiser";
}
const char* Destroyer::name(void) const
{
	return "Destroyer";
}

 int AircraftCarrier::size(void) const{
	return 5;
}
 int BattleShip::size(void) const{
	return 4;
}
 int Cruiser::size(void) const{
	return 3;
}
 int Destroyer::size(void) const{
	return 2;
}

int Ship::getX(int i) const
{
	if (x2 > x1)
		return x1 + i;
	else if (x2 < x1)
		return x2 + i;
	else	
		return x1;
}			

int Ship::getY(int i) const
{
	if (y2 > y1)
		return y1 + i;
	else if (y2 < y1)
		return y2 + i;
	else	
		return y1;
}

void Ship::print()  const
{
	cout << this->name() << " from " << "(" << x1<<"," << y1 << ")" << " to " <<  "(" << x2 <<"," << y2 << ")" << endl;
}

bool Ship::includes(int x, int y)
{
	bool include= false;

	if(x == x1)
	{
		if ((y>= y1) && (y<=y2))
		{
			include = true;
		}
		if ((y>= y2) && (y<=y1))
		{
			include = true;
		}
	}
	else if (y == y1)
	{
		if ((x>= x1) && (x<=x2))
			{
				include = true;
			}
		if ((x>= x2) && (x<=x1))
		{
			include = true;
		}
	}


	return include; 
}




int Ship::level (void) const
{
	return lev;
}

void Ship::decreaseLevel(void)
{
	if( lev == 0)
	{
		//do nothing;
	}

	else{
		lev -=1;
	}
}

 Ship* Ship::makeShip(char ch, int x1, int y1, int x2, int y2)
{
	switch (ch)
        {

        case 'A':

        {

                AircraftCarrier *T = new AircraftCarrier(x1, y1, x2, y2);

                if (T->checkConfig(x1, y1, x2, y2))

                        return T;

                else

                        {

                          throw invalid_argument("invalid configuration");

                        }

        }

        case 'B':

        {

                BattleShip *P = new BattleShip(x1, y1, x2, y2);

                if (P->checkConfig(x1, y1, x2, y2))

                        return P;

                else

                        {

                          throw invalid_argument("invalid configuration");

                        }

        }

        case 'C':

        {

                Cruiser *W = new Cruiser(x1, y1, x2, y2);

                if (W->checkConfig(x1, y1, x2, y2))

                        return W;

                else

                        {

                         throw invalid_argument("invalid configuration");

                        }

        }

        case 'D':

        {

                Destroyer *I = new Destroyer(x1, y1, x2, y2);

                if (I->checkConfig(x1, y1, x2, y2))

                        return I;

                else

                        {

                          throw invalid_argument("invalid configuration");

                        }

}

        default:

        {

                throw invalid_argument("invalid configuration");

        }

        }

}


bool Ship::checkConfig(int x1, int y1, int x2, int y2)
{
	bool check = false;
	if(x1==x2)
	{
		if((y2-y1)==this->size()-1){
			check= true;
		}
		if((y1-y2)==this->size()-1){
			check = true;
		}

	}
	else if (y1==y2)
	{
		if((x2-x1)==this->size()-1)
		{
			check = true;
		}
		if((x1-x2)==this->size()-1){
			check = true;
		}
	}
	return check;
}


    void Ship::setPos(int a1, int b1, int a2, int b2)
    {
    	try{
    		if(checkConfig(a1,b1,a2,b2))
    		{
    			this->x1 = a1;
    			this->y1 = b1;
    			this->x2 = a2;
        		this->y2 = b2;



    		}
    	}
    	catch(invalid_argument a) 
		{
			cerr << a.what()<< endl;

			}


    }