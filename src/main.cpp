#include <iostream>
#include "BraunnerTree.h"
#include "ColiderCheck.h"
#include "vec3.h"
#include "Triangle.h"



int main(int argc, char **argv) {
	 //Testes de Colisão pura (triângulo a triânglo
	 std::cout << "triangle 1\n a:";
	 vec3 a(0,-2,-.3);
	 vec3 b(0.5,1,0);
	 vec3 c(1,0,.3);
	 std::cout << a;
	 std::cout << "\n b:";
	 std::cout << b;
	 std::cout << "\n c:";
	 std::cout << c;
	 std::cout << "\n";
	 Triangle t1(a,b,c);
	 t1.plane();
	 std::cout << "t1 center: \n";
	 std::cout << t1.center;
	 std::cout << "\nt1 Normal: \n";
	 std::cout << t1.cross_v1xv2;
	 std::cout << "\nTriangle2\n a:";
	 a.x=t1.a.x; a.y=t1.center.y;a.z=t1.a.z-0.5;
	 b.x=.5;b.y=t1.center.y;b.z=1;
	 c.x=1;c.y=t1.center.y;c.z=0.5;
	 std::cout << a;
	 std::cout << "\n b:";
	 std::cout << b;
	 std::cout << "\n c:";
	 std::cout << c;
	 std::cout << "\n";
	 Triangle t2(a,b,c);
	 a.x=10;a.y=10;a.z=0;
	 b.x=10;b.y=15;c.z=0;
	 c.x=15;c.y=10;c.z=0;
	 Triangle t3(a,b,c);
	 bool colide=false;
	 ColiderCheck col(t1,t2,colide);
	 if (colide)
		 std::cout << "t1 e t2 colidem\n";

	 ColiderCheck col2(t1,t3,colide);
	 if (!colide)
		 std::cout << "não colide t3 com t1 \n";

	 ColiderCheck col3(t1,t1,colide);
	 if (colide)
		 std::cout << "t1 colide com um triângulo igual a ele \n";
	 //Triangle t4(vec3(.5,0,0),vec3(1,1,0),vec3(1.5,0,0));



	 //Bounding Box Tests
	 BoundingBox box(t1);
	 if (box.colision(BoundingBox(t1)))
		 std::cout<< "Bounding boxes iguais colidem"<< std::endl;
	 if (! box.insideBox(BoundingBox(t3)) )
		 std::cout << "t3 fora do alcance da box"<< std::endl;
	 if (box.insideBox(vec3(9,.5,0)))
		 std::cout << "true"<< std::endl;
	 if (box.interceptBox((BoundingBox(t2))))
		 std::cout<< "Bounding box de t2 e t1 colidem"<< std::endl;
	 if (!box.interceptBox((BoundingBox(t3))))
	 	 std::cout<< "Bounding box de t3 e t1 NÃO colidem"<< std::endl;
	 if (box.colision((BoundingBox(t2))))
		 std::cout<< "Elementos de t1 e t2 colidem"<< std::endl;
	 if (!box.colision((BoundingBox(t3))))
	 	 std::cout<< "Elementos de t1 e t3 NÃO colidem"<< std::endl;


	 //testes da Octree
	 vec3 TreeCenter(2,-1,2);
	 vec3 halfDimension(10,10,10);

	 BraunnerTree bt (3,halfDimension,TreeCenter);
	 bt.insert(t1);
	 std::cout << bt.getContainingOctant(t1);
	 std::cout << std::endl;
	 std::cout << bt.getContainingOctant(t2);
	 std::cout << std::endl;


	return 0;
}



