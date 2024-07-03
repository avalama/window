
// Register the window class.
#include<windows.h>
#include<gdiplus.h>
#include<WinUser.h>
#include<chrono>
#include<thread>
using namespace std;
using std::this_thread::sleep_for;
HWND TextBox, cong;
char textsaved[20];
struct pas
{
	HWND hwnd;
	bool* dud;
};
const char* class_name = "cpp windows";
const char* class_name1 = "cp windows";
bool bo = true, sw = true, sn = true, * sm = &sn;
int close = 0;
void updu(HWND* ava)
{
	while (true)
	{
		sleep_for(chrono::seconds(1)); ///24));
		RedrawWindow(*ava, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
	}
}
void updut(HWND ava, long go)
{
	MSG msg{};
	msg.hwnd = ava;
	msg.message = go;
	TranslateMessage(&msg);
	DispatchMessage(&msg);
}
void mesage(pas av)
{
	while (true)
	{
		MSG msg{};
		msg.hwnd = av.hwnd;
		while (GetMessage(&msg, nullptr, 0, 0) || *av.dud)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
struct gro
{
	HWND* hnd1;
	HWND* hnd2;
};
LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount)
{
	srand(time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) //only way to get ACTUAL random number
		* time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL)
		* time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL));
	WNDCLASS wc = { };
	wc.hInstance = currentInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(160, 32, 240));
	wc.lpfnWndProc = WindowProcessMessages;
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);
	RegisterClass(&wc);
	WNDCLASS mc = { };
	mc.hInstance = currentInstance;
	mc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	mc.hbrBackground = (HBRUSH)7;
	mc.lpfnWndProc = WindowProcessMessages;
	LPCWSTR w = L"hi";
	const char * ava = CreateWindow( w, "ava pro 1", WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX, 200, 200, 1000, 1000, nullptr, nullptr, nullptr, nullptr);
	RegisterClass(&mc);
}
void paint1(HWND hwnd)
{
	Gdiplus::GdiplusStartupInput draw;
	ULONG_PTR pen;
	Gdiplus::GdiplusStartup(&pen, &draw, nullptr);
	PAINTSTRUCT ya;
	RECT siz;
	GetWindowRect(hwnd, &siz);
	HDC nah = BeginPaint(hwnd, &ya);
	FillRect(nah, &ya.rcPaint, (HBRUSH)(CreateSolidBrush(RGB(0, 0, 255))));
	Gdiplus::Graphics df(nah);
	Gdiplus::Pen pencil(Gdiplus::Color{ 255,255,0,0 });
	Gdiplus::SolidBrush bush{ Gdiplus::Color(255,160, 32, 240) };
	Gdiplus::Bitmap cat(L"75552.bmp");
	ScaleWindowExtEx(nah, 2, 1, 2, 1, NULL);//dumb
	StretchBlt(nah, 0, 0, 100, 100, nah, 1000, 1000, 1000, 1000, SRCCOPY);
	int ed = (siz.right - siz.left) / 2;
	int td = (siz.bottom - siz.top) / 2;
	df.DrawImage(&cat, rand() % (2 * ed), rand() % (2 * td), 300, 220);
	df.DrawLine(&pencil, ed, 0, ed, siz.bottom - siz.top);
	df.DrawLine(&pencil, 0, td, siz.right, td);
	EndPaint(hwnd, &ya);
}
static LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam)
{
	int f = 0;
	switch (msg)
	{

	case WM_COMMAND:
	{
		if (bo)
		{
			bo = false;
		}
		if (LOWORD(param) == 2)
		{
			if (sw)
			{
				sw = false;
				SetWindowLongPtr(cong, GWL_STYLE, WS_VISIBLE | WS_CHILD | WS_OVERLAPPED | WS_SIZEBOX | SS_CENTER);
			}
			else
			{
				sw = true;
				SetWindowLongPtr(cong, GWL_STYLE, WS_CHILD | WS_OVERLAPPED | WS_SIZEBOX | SS_CENTER);
			}
		}
		RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		switch (LOWORD(param))
		{
		case 1:
		{
			int i = 20;
			char* k = &textsaved[0];
			if (k[1] != NULL)
			{
				bool ye = SetWindowTextA(TextBox, 0);
				msg = WM_PAINT;
			}
			RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		}
		}

		f = 1;
	}
	case WM_PAINT:
	{
		paint1(hwnd);
		f = 0;
		return 0;
	}
	case WM_DESTROY:
	{
		close++;
		if (close > 0)
		{
			*sm = false;
			PostQuitMessage(0);
		}
		return 0;
	}
	default:
		return DefWindowProc(hwnd, msg, param, lparam);
	}
}