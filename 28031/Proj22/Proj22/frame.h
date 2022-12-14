#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "shape.h"
#include "Mbutton.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class MButton;
class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;	 // 윈도 핸들을 저장해둔다.
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

	// 공통적인 변수
	MButton* buttons_[100];
	int numButtons = 0;
	//
	//응용을 위해 필요한 변수
	static const int FIG_NONE = 0;
	static const int FIG_RECT = 1;
	static const int FIG_ELLI = 2;
	static const int FIG_LINE = 3;

	// 응용을 위해 필요한 변수
	MPoint start_;
	MPoint end_;

	int figType_ = FIG_NONE;

public:
	Frame();
	Frame(std::wstring, int, int);
	virtual void run();
	virtual void eventHandler(MEvent e);
	virtual void repaint();
	void invalidate();
	virtual void initialize();
	void addButton(MButton* b);
	void drawButtons();
	MButton* findButton(MPoint p); // p 위치를 클릭했을 때 거기 버튼의 포인터를 돌려준다.
	void setShape(int t);
};