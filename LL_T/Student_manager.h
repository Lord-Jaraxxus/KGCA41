#include "LinkedList.h"
#include "k_Student.h"

class Student_manager
{

public:
	LinkedList<k_Student> m_List; // ��ü�� ������ ����� ���ϴϱ� �ϳ� ����?��?

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

