#ifndef __buttons_h
#define __buttons_h

void buttons_setup();
void buttons_loop();
bool buttons_status(int button);
void buttons_restore();
void buttons_persist();

#endif
