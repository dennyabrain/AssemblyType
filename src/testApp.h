#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "Kinect.h"

// -------------------------------------------------
class polyData {
public:
	bool bHit;
};

class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);

	ofImage image;
	ofImage handImage;
	
	ofxBox2d box2d;	  //	the box2d world
	ofxBox2dRect ground;
	ofxBox2dCircle hand;

	// this is the function for contacts
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);

//LOOPY STUFF
	ofxBox2dRect block;
	ofxBox2dPolygon chink[4];
	int blkState[4];
	ofImage slab;
	ofSoundPlayer sound[2];

	Kinect kinect;

	float skeletonX[21];
	float skeletonY[21];
};

