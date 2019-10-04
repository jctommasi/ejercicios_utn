/*
 * stuff.h
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */

#ifndef STUFF_H_
#define STUFF_H_

#include <stdio.h>
#include <unistd.h>

void stuff_clearScreen();
void stuff_printAndSleep(int sleepTime, char msg[]);
void stuff_sleep(int sleepTime);
void stuff_displayMainBanner();
void stuff_showMenu();
void stuff_showReportBanner();
void stuff_showReportsMenu();
void stuff_showSignUpBanner();
void stuff_showDestroyBanner();
void stuff_showModifyBanner();
void stuff_showPaginateBanner();
void stuff_showDestroyed();

#endif /* STUFF_H_ */
