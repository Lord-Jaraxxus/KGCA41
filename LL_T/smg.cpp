#include <stdio.h>
#include "Student_manager.h"

void main() 
{
	Student_manager smg;

	int iWork = 1;
	int iWorkType = 0;

	while (iWork)
	{
		printf("1:�ʱ�ȭ 2:�߰� 3:�˻� 4:�տ��߰� 5:�ڿ��߰� 6:���� 7:���� 8:���� 9:�ε� 0:����\n");
		scanf_s("%d", &iWorkType);
		system("cls"); // ��ġ�� ���Ⱑ �³�

		switch (iWorkType)
		{
		case 0:
		{
			printf("���α׷��� �����մϴ�.");
			iWork = 0;
		}break;
		case 1:
		{
			smg.InitData(4);
			smg.print_all();
		}break;
		case 2:
		{
			smg.m_List.insertBack(*smg.NewStudent()); // ���ڳ� ���� �̰� ����?
			smg.print_all();
		}break;
		case 3:
		{
			printf("ã�� ��ȣ�� �Է��ϼ� : ");
			int find_num = -1;
			scanf_s("%d", &find_num);
			if (smg.m_List.find(find_num) == NULL) { printf("ã���ô� ��ȣ�� �����ϴ�.\n"); break; }
			smg.print_all();
		}break;
		case 4:
		{
			printf("�տ� �߰��� �л� ��ȣ�� �Է��ϼ� : ");
			int find_num = -1;
			scanf_s("%d", &find_num);
			Box<k_Student>* target_student = smg.m_List.find(find_num);
			if (target_student == NULL) { printf("ã���ô� ��ȣ�� �����ϴ�.\n"); break; }
			smg.m_List.insertTargetFront(*smg.NewStudent(), target_student);
			system("cls");
			smg.print_all();
		}break;
		case 5:
		{
			printf("�ڿ� �߰��� �л� ��ȣ�� �Է��ϼ� : ");
			int find_num = -1;
			scanf_s("%d", &find_num);
			Box<k_Student>* target_student = smg.m_List.find(find_num);
			if (target_student == NULL) { printf("ã���ô� ��ȣ�� �����ϴ�.\n"); break; }
			smg.m_List.insertTargetBack(*smg.NewStudent(), target_student);
			system("cls");
			smg.print_all();
		}break;
		case 6:
		{
			printf("�����ض� �ּ��� : ");
			int find_num = -1;
			scanf_s("%d", &find_num);
			Box<k_Student>* target_student = smg.m_List.find(find_num);
			if (target_student == nullptr) { printf("ã���ô� ��ȣ�� �����ϴ�.\n"); break; }
			smg.m_List.death(target_student);
			smg.print_all();
		}break;
		case 7:
		{
			//smg.m_List.sort();
			smg.print_all();
		}break;
		case 8:
		{
			//smg.save();
			smg.print_all();
		}break;
		case 9:
		{
			//smg.load();
			//print_all();
		}
		}
	}

	smg.ReleaseData();
}