/*
 * MenuScreen.hpp
 *
 *  Created on: 2 févr. 2019
 *      Author: Greg
 */

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <ScreenManager.hpp>
#include <Screen.hpp>

class MenuScreen: public Screen {
public:
	MenuScreen(ScreenManager *);
	virtual ~MenuScreen();
};

#endif /* MENUSCREEN_HPP_ */
