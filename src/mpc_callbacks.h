
#ifndef BASIC_H
#define BASIC_H

#include <string>

void initMpc(void);

void initApp(void);

void leftButtonClick(int lin, int col);

void displayApp(void);

void cbMouse(int l, int c, int button, int state);

void cbKeyboard(int key, int modifier, bool special, bool up);

void cbUpdate(void);


#endif // __APP_DEMO_H__
