﻿#include <iostream>

//F5(디버깅,다음블랙포인터까지), F9(블랙포인터,중단점), F10(프로시저단위,한줄밑으로),  F11(한 단계씩 실행,따라들어감?), Shift+F5(디버깅종료)

int main()
{
    int a = 4;
    int b = 6;
    int c = a + b;
    std::cout << "Hello World!\n";
}

// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

//호출스택, 조사식(오른쪽), 출력