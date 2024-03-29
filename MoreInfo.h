#ifndef MOREINFO_H
#define MOREINFO_H

//General
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 900
#define FRAMERATE_LIMIT 120

//Variables
#define GROUND_HEIGHT 800
#define SKY_HEIGHT 100
#define PLAYER_BORDER_SPEED 30
#define INVADER_ORIGIN 10000
#define SHIELD_ORIGIN 15000
#define BULLET_ORIGIN 12345

#define UFO_SPEED 3.0
#define INVADER_SPEED 2.0
#define HYPER_INVADER_SPEED 10.0
#define PLAYER_BULLET_SPEED 5.0
#define INVADER_BULLET_SPEED 2.0
#define PLAYER_SPEED 1.2

#define SHIELD_PROTECTION 10

//Fonts
#define ARIAL_FONT "res/fonts/arial.ttf"
#define SPACEINVADERS_FONT "res/fonts/space_invaders.ttf"

//Textures
#define UFO_T "res/images/SIUFO.png"
#define INVADER_T1 "res/images/SIInvader1.png" //Crab
#define INVADER_T2 "res/images/SIInvader2.png" //Octopus
#define INVADER_T3 "res/images/SIInvader3.png" //Squid
#define EXPLOSION_T "res/images/SIInvaderExplosion.png"
#define SHIELD_T "res/images/SIShield.png"
#define INVADER_BULLET_T "res/images/SIIBullet.png"
#define PLAYER_BULLET_T "res/images/SIPBullet.png"
#define PLAYER_T "res/images/SIPlayer.png"

//Sound Effects - FX
#define SLOW_BACKGROUND_FX "res/sounds/background/1.wav"
#define FAST_BACKGROUND_FX "res/sounds/background/0.wav"
#define UFO_FX "res/sounds/FX/4.wav"
#define INVADER_KILLED_FX "res/sounds/FX/5.wav"
#define SHOOTING_FX "res/sounds/FX/3.wav"
#define EXPLOSION_FX "res/sounds/FX/2.wav"

/*--------------COLOR INFO-------------*/
//www.rapidtables.com/web/color/RGB_Color.html
//Black		 = 0, 0, 0
//White		 = 255, 255, 255
//Red		 = 255, 0, 0
//Green		 = 0, 128, 0
//Lime Green = 0, 255, 0
//Dark Green = 0, 100, 0
//Cyan		 = 0, 255, 255
//Dark Cyan  = 0, 139, 139
//Blue		 = 0, 0, 255
//Yellow	 = 255, 255, 0
//Brown		 = 61, 53, 53
//Gray		 = 128, 128, 128
//Navy		 = 0, 0, 128

#endif