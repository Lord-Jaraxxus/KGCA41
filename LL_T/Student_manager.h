#include "LinkedList.h"
#include "k_Student.h"

class Student_manager
{

public:
	LinkedList<k_Student> m_List; // 실체가 없으면 써먹질 못하니까 하나 만든?듯?

public:
	k_Student* NewStudent();

	void GRV(k_Student* new_student);

	void InitData(int student_num);

	void ReleaseData();

	void print_one(Box<k_Student>*);

	void print_all();

	//void save();

	//void load();

};

