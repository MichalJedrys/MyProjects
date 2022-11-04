//st_gr - namespace in which all elements are connected to groups of students
namespace st_gr 
{ 
	class groupOfStudents;

	//nested namespaces in which all elements are connected to single student
	namespace st
	{
		using namespace std;
		class student;
	}
}
//In C++17 in could also use "namespace st_gr::st { ... }"

//shp - shape
namespace shp
{
	class shape;
	class square;
	class rectangle;
	class triangle;
	class rhombus;
}

//cnt - containers (namespace to store more containers in future - like string class)
namespace cnt
{
	class vectorC;
}