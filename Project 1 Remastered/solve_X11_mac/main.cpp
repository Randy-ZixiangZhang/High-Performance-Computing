#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>

int main(void) {
    Display* dis = XOpenDisplay(NULL);
    return 0;
}