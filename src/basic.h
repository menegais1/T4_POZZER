
#ifndef BASIC_H
#define BASIC_H

#include <string>


static const int APP_LINES = 35;
static const int APP_COLUMNS = 100;

void initMpc(void);

void initApp(void);

void clearScreen();

void leftButtonClick(int lin, int col);

void displayApp(void);

void cbMouse(int l, int c, int button, int state);

void cbKeyboard(int key, int modifier, bool special, bool up);

void cbUpdate(void);


#endif // __APP_DEMO_H__
