#include "AsphaltLane.h"
#include "Character.h"
#include "Entity.h"
#include "Global.h"
#include "GrassLane.h"
#include "InputHandler.h"
#include "Map.h"
#include "MoveUpCommand.h"
#include "RailLane.h"
#include "RenderState.h"
#include "Shape.h"
#include "renderer.h"



bool window_should_close = false;

RenderState render_state;
InputHandler ih;
Command* command = nullptr;
Character* c = new Character;

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  LRESULT result = 0;

  switch (uMsg) {
    case WM_CLOSE:
    case WM_DESTROY:
      window_should_close = true;
      break;
    case WM_KEYDOWN:
      command = ih.handleInput(wParam, *c);
      break;
    case WM_SIZE: {
      RECT clientRect;
      GetClientRect(hWnd, &clientRect);
      render_state = RenderState(clientRect.bottom - clientRect.top,
                                 clientRect.right - clientRect.left);
    } break;
    default:
      result = DefWindowProc(hWnd, uMsg, wParam, lParam);
  }
  return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
            int nShowCmd) {
  srand(time(NULL));
  WNDCLASS window_class{};
  window_class.style = CS_HREDRAW | CS_VREDRAW;
  window_class.lpszClassName = L"My Window Class";
  window_class.lpfnWndProc = Wndproc;

  RegisterClass(&window_class);

  HWND window = CreateWindowA("My Window Class", "My First Game",
                                WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT,
                                CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
  HDC hdc = GetDC(window);
  //Lane lane[10];
  initShape();
  Shape* moving = new Shape[3]{*MyShape[DOG_STAY_1], *MyShape[DOG_JUMP_1], *MyShape[DOG_JUMP_2] };
  Shape* staying = new Shape[2]{ *MyShape[DOG_STAY_1], *MyShape[DOG_STAY_2] };
  DWORD lastAddObstacleTime = 0;
  SummerLaneFactory fact;
  Map m(&fact);
  m.addLane();

  Global::drawer.set_render_state(render_state);
  c = new Character{ {90, 90}, staying, moving, 3 };

  while (!window_should_close) {
    MSG message;
    while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }

    unsigned int* pixels = render_state.getMemoryPointer();
    for (int i = 0; i < render_state.getWidth(); i++) {
      for (int j = 0; j < render_state.getHeight(); j++) {
        *pixels++ = 0xFFFFFF55;
      }
    }
    DWORD currentTime = GetTickCount();  // Get the current time in milliseconds

    m.addObstacle();
    m.moveObstacle();

    m.render();
    c->render();
    if (command != nullptr) {
        command->execute(*c);
        command = nullptr;
    }

    if (m.checkCollision(*c)) {
        c->setPos({ 90, 90 });
    }

    StretchDIBits(hdc, 0, 0, render_state.getWidth(), render_state.getHeight(),
                  0, 0, render_state.getWidth(), render_state.getHeight(),
                  render_state.getMemoryPointer(),
                  render_state.getBitmapPointer(), DIB_RGB_COLORS, SRCCOPY);
  }
}