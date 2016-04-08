/*
 * Copyright (c) 2014 Antoine Rousseau <antoine@metalu.net>
 * BSD Simplified License, see the file "LICENSE.txt" in this distribution.
 * See https://github.com/Ant1r/ofxPof for documentation and updates.
 */
#pragma once

#include "pofBase.h"

#ifdef RASPI
#include "ofxOMXPlayer.h"
#endif

class pofFilm;

class pofFilm: public pofBase {
	public:
		pofFilm(t_class *Class, float w, float h, float istext):
			pofBase(Class), player(NULL), width(w), height(h), playing(0), actualPlaying(0), 
			file(NULL), loadedFile(NULL),isTexture(istext!=0),
			gotoFrame(-1), speed(1)
		{ }

		virtual void draw();
		virtual void postdraw();
		static void setup(void);
		
#ifdef RASPI
        ofxOMXPlayer *player;
#else
		ofVideoPlayer *player;
#endif
		float width, height, playing, actualPlaying;
		t_symbol *file, *loadedFile;
		bool isTexture;		
		float gotoFrame;
		float speed;
};



