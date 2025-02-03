#include <windows.h>
#include <string>
#include <sstream>

#define BUTTON_0 1000
#define BUTTON_1 1001
#define BUTTON_2 1002
#define BUTTON_3 1003
#define BUTTON_4 1004
#define BUTTON_5 1005
#define BUTTON_6 1006
#define BUTTON_7 1007
#define BUTTON_8 1008
#define BUTTON_9 1009
#define BUTTON_ADD 1010
#define BUTTON_SUBTRACT 1011
#define BUTTON_MULTIPLY 1012
#define BUTTON_DIVIDE 1013
#define BUTTON_EQUAL 1014
#define BUTTON_CLEAR 1015
#define BUTTON_DELETE 1016

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HWND hDisplay;
std::wstring currentInput = L"";
double firstNumber = 0;
double secondNumber = 0;
wchar_t operation = 0;

// Custom function to convert integer to wstring
std::wstring IntToWString(int number) {
    std::wstringstream wss;
    wss << number;
    return wss.str();
}

void UpdateDisplay() {
    SetWindowTextW(hDisplay, currentInput.c_str());
}

void Clear() {
    currentInput = L"";
    firstNumber = 0;
    secondNumber = 0;
    operation = 0;
    UpdateDisplay();
}

void PerformCalculation() {
    std::wstringstream ss(currentInput);
    ss >> secondNumber;
    double result = 0;

    if (operation) {
        switch (operation) {
            case '+':
                result = firstNumber + secondNumber;
                break;
            case '-':
                result = firstNumber - secondNumber;
                break;
            case '*':
                result = firstNumber * secondNumber;
                break;
            case '/':
                if (secondNumber != 0)
                    result = firstNumber / secondNumber;
                else
                    currentInput = L"Error";  // Error message for division by zero
                break;
        }

        if (currentInput != L"Error") {
            std::wstringstream resultStream;
            resultStream << result;
            currentInput = resultStream.str();
        }
    }
    UpdateDisplay();
}

void DeleteLastChar() {
    if (!currentInput.empty()) {
        currentInput = currentInput.substr(0, currentInput.size() - 1);
        UpdateDisplay();
    }
}

void HandleNumber(int number) {
    currentInput += IntToWString(number);
    UpdateDisplay();
}

void HandleOperation(wchar_t op) {
    std::wstringstream ss(currentInput);
    ss >> firstNumber;
    currentInput = L"";
    operation = op;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    WNDCLASSW wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"CalculatorClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    HWND hWnd = CreateWindowW(L"CalculatorClass", L"Simple Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                              100, 100, 300, 400, NULL, NULL, hInst, NULL);

    if (!hWnd) return -1;

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void AddControls(HWND hWnd) {
    hDisplay = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | SS_RIGHT,
                             20, 20, 240, 40, hWnd, NULL, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    int buttonWidth = 50;
    int buttonHeight = 50;
    int xOffset = 20;
    int yOffset = 80;

    // Number buttons
    CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + buttonWidth, yOffset + 4 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_0, NULL, NULL);

    for (int i = 1; i <= 9; ++i) {
        int x = xOffset + ((i - 1) % 3) * buttonWidth;
        int y = yOffset + (3 - (i - 1) / 3) * buttonHeight;
        CreateWindowW(L"Button", IntToWString(i).c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER, x, y, buttonWidth, buttonHeight, hWnd, (HMENU)(BUTTON_0 + i), NULL, NULL);
    }

    // Operator buttons
    CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 3 * buttonWidth, yOffset, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_ADD, NULL, NULL);
    CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 3 * buttonWidth, yOffset + buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_SUBTRACT, NULL, NULL);
    CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 3 * buttonWidth, yOffset + 2 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_MULTIPLY, NULL, NULL);
    CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 3 * buttonWidth, yOffset + 3 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_DIVIDE, NULL, NULL);

    // Equal, Clear, and Delete buttons
    CreateWindowW(L"Button", L"=", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 2 * buttonWidth, yOffset + 4 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_EQUAL, NULL, NULL);
    CreateWindowW(L"Button", L"C", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset, yOffset + 4 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_CLEAR, NULL, NULL);
    CreateWindowW(L"Button", L"<-", WS_VISIBLE | WS_CHILD | WS_BORDER, xOffset + 3 * buttonWidth, yOffset + 4 * buttonHeight, buttonWidth, buttonHeight, hWnd, (HMENU)BUTTON_DELETE, NULL, NULL);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            switch (wp) {
                case BUTTON_0: case BUTTON_1: case BUTTON_2: case BUTTON_3: case BUTTON_4:
                case BUTTON_5: case BUTTON_6: case BUTTON_7: case BUTTON_8: case BUTTON_9:
                    HandleNumber(wp - BUTTON_0);
                    break;
                case BUTTON_ADD:
                    HandleOperation('+');
                    break;
                case BUTTON_SUBTRACT:
                    HandleOperation('-');
                    break;
                case BUTTON_MULTIPLY:
                    HandleOperation('*');
                    break;
                case BUTTON_DIVIDE:
                    HandleOperation('/');
                    break;
                case BUTTON_EQUAL:
                    PerformCalculation();
                    break;
                case BUTTON_CLEAR:
                    Clear();
                    break;
                case BUTTON_DELETE:
                    DeleteLastChar();
                    break;
            }
            break;
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

