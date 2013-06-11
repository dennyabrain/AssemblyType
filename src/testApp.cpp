#include "testApp.h"
float x=-50;
int alphabet;
int alphabetFlag=0;
//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofSetRectMode(OF_RECTMODE_CENTER);
	kinect.initialize();
	image.loadImage("back.jpg");
	handImage.loadImage("hand.png");
	sound[0].loadSound("block.wav");
	sound[0].setMultiPlay(true);
	sound[0].setLoop(false);
	sound[1].loadSound("chink.wav");
	sound[1].setMultiPlay(true);
	sound[1].setLoop(false);
	ofHideCursor();

	for(int i=0;i<4;i++){
		blkState[i]=0;
	}
	
	box2d.init();
	box2d.setGravity(0, 10);
	//box2d.createBounds();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();

	hand.setPhysics(0.3,0.3,0.3);
	hand.setup(box2d.getWorld(),ofGetMouseX(),ofGetMouseY(),20);
	hand.setData(new polyData());
	polyData *sd = (polyData*)hand.getData();
	sd->bHit	= false;
	alphabet=ofRandom(0,9);

	// register the listener so that we get the events
	ofAddListener(box2d.contactStartEvents, this, &testApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &testApp::contactEnd);

	ground.setPhysics(0.0,0.3,0.8);
	ground.setup(box2d.getWorld(),100,840,1820,20);
//LOADING ALPHABETS
	if(alphabet==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,64.75);
		 
	
		chink[0].addTriangle(ofVec2f(0-29.3,0-64.75+20),ofVec2f(0-29.3,20-64.75+20),ofVec2f(-50-29.3,20-64.75+20));
		chink[1].addTriangle(ofVec2f(0-29.3,50-64.75+20),ofVec2f(0-29.3,80-64.75+20),ofVec2f(-30-29.3,40-64.75+20));
		chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0+29,0+25),ofVec2f(20+29,20+25),ofVec2f(0+29,10+25));
		slab.loadImage("E.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}
}
//--------------------------------------------------------------
void testApp::update() {
	x+=2;	
	kinect.getSkeleton(skeletonX,skeletonY);
	if(x>2000){
		x=-100;
		for(int i=0;i<4;i++){
			blkState[i]=0;
			chink[i].destroy();
		}
		//alphabet=ofRandom(0,9);
		alphabet=(alphabet+1)%10;
		alphabetFlag=0;
	}
	for(int i=0;i<4;i++){
		if(blkState[i]==0){
			chink[i].setPosition(x,750);
			polyData * data = (polyData*)chink[i].getData();
			if(data && data->bHit){
				blkState[i]=1;
				chink[i].addForce(ofVec2f(5,5),10);
				sound[1].play();
			}			
		}
	}
	block.setPosition(x,750);
//LOADING NEW LEVELS
	if(alphabet==0 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,64.75);
	
		chink[0].addTriangle(ofVec2f(0-29.3,0-64.75+20),ofVec2f(0-29.3,20-64.75+20),ofVec2f(-50-29.3,20-64.75+20));
		chink[1].addTriangle(ofVec2f(0-29.3,50-64.75+20),ofVec2f(0-29.3,80-64.75+20),ofVec2f(-30-29.3,40-64.75+20));
		chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0+29,0+25),ofVec2f(20+29,20+25),ofVec2f(0+29,10+25));
		slab.loadImage("E.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==1 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,64.75);
	
		chink[0].addTriangle(ofVec2f(0-29.3,0-64.75+20),ofVec2f(0-29.3,20-64.75+20),ofVec2f(-50-29.3,20-64.75+20));
		chink[1].addTriangle(ofVec2f(0-29.3,50-64.75+20),ofVec2f(0-29.3,80-64.75+20),ofVec2f(-30-29.3,40-64.75+20));
		chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0+29,0-50),ofVec2f(20+29,20-50),ofVec2f(0+29,10-50));
		slab.loadImage("F.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}
	if(alphabet==2 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,64.75);
	
		chink[0].addTriangle(ofVec2f(0-29.3,0-64.75+20),ofVec2f(0-29.3,20-64.75+30),ofVec2f(-50-29.3,20-64.75+20));
		chink[1].addTriangle(ofVec2f(0-29.3,50-64.75+20),ofVec2f(0-29.3,80-64.75+20),ofVec2f(-30-29.3,40-64.75+20));
		chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0+29,0-50),ofVec2f(20+29,20-50),ofVec2f(0+29,10-50));
		slab.loadImage("H.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==3 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,48);
	
		chink[0].addTriangle(ofVec2f(0+13,0-50),ofVec2f(10+13,-40-50),ofVec2f(20+13,0-50));
		chink[1].addTriangle(ofVec2f(0+33,0-2500),ofVec2f(10+33,-40-2500),ofVec2f(20+33,0-2500));
		chink[2].addTriangle(ofVec2f(0+13-50,0-50),ofVec2f(10+13-50,-40-50),ofVec2f(20+13-50,0-50));
		//chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0+33-250,0-2500),ofVec2f(10+33-250,-40-2500),ofVec2f(20+33-250,0-2500));
		slab.loadImage("V.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==4 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,48);
	
		chink[0].addTriangle(ofVec2f(0+13,0-50),ofVec2f(5+13,-20-50),ofVec2f(10+13,0-50));
		chink[1].addTriangle(ofVec2f(0+29.3,0-49),ofVec2f(20+29.3,10-49),ofVec2f(0+29.3,10-49));
		chink[2].addTriangle(ofVec2f(0+13-30,0-50),ofVec2f(5+13-30,-10-50),ofVec2f(10+13-30,0-50));
		//chink[2].addTriangle(ofVec2f(0+29,0-10),ofVec2f(20+29,7-10),ofVec2f(0+29,7-10));
		chink[3].addTriangle(ofVec2f(0-29.3,0+20),ofVec2f(0-29.3,20+20),ofVec2f(-30-29.3,20+20));
		slab.loadImage("Z.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==5 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,30);
	
		chink[0].addTriangle(ofVec2f(0+29.3,0-50),ofVec2f(30+29.3,60-50),ofVec2f(0.3,10-50));
		chink[1].addTriangle(ofVec2f(0+29.3,0-49),ofVec2f(20+29.3,10-49),ofVec2f(0+29.3,10-49));
		chink[2].addTriangle(ofVec2f(0-29,0-40),ofVec2f(0-29,20-40),ofVec2f(-20-29,10-40));
		chink[3].addTriangle(ofVec2f(0+9.3,0+40),ofVec2f(0+9.3,20+40),ofVec2f(-30+9.3,20+40));
		slab.loadImage("hA.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==6 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,30);
	
		chink[0].addTriangle(ofVec2f(0+29.3,0-50),ofVec2f(30+29.3,60-50),ofVec2f(0.3,10-50));
		chink[1].addTriangle(ofVec2f(0+29.3,0-49),ofVec2f(20+29.3,10-49),ofVec2f(0+29.3,10-49));
		chink[2].addTriangle(ofVec2f(0-29,0-40),ofVec2f(0-29,20-40),ofVec2f(-20-29,10-40));
		chink[3].addTriangle(ofVec2f(0,0+35),ofVec2f(0,20+35),ofVec2f(-30,20+35));
		slab.loadImage("hF.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.3,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==7 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,30);
	
		chink[0].addTriangle(ofVec2f(0+29.3,0-37),ofVec2f(20+29.3,0-37),ofVec2f(0+29.3,40-37));
		chink[1].addTriangle(ofVec2f(0-35.3,0-45),ofVec2f(20-35.3,10-45),ofVec2f(0-35.3,10-45));
		chink[2].addTriangle(ofVec2f(0+25,0-45),ofVec2f(20+25,10-45),ofVec2f(0+25,10-45));
		chink[3].addTriangle(ofVec2f(0-10.3,0-45),ofVec2f(20-10.3,10-45),ofVec2f(0-10.3,10-45));
		slab.loadImage("hG.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==8 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,30);
	
		chink[0].addTriangle(ofVec2f(0+29.3,0-37),ofVec2f(20+29.3,0-37),ofVec2f(0+29.3,40-37));
		chink[1].addTriangle(ofVec2f(0-35.3,0-45),ofVec2f(20-35.3,10-45),ofVec2f(0-35.3,10-45));
		chink[2].addTriangle(ofVec2f(0+25,0-45),ofVec2f(20+25,10-45),ofVec2f(0+25,10-45));
		chink[3].addTriangle(ofVec2f(0-10.3,0-45),ofVec2f(20-10.3,10-45),ofVec2f(0-10.3,10-45));
		slab.loadImage("hN.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.3,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	if(alphabet==9 && alphabetFlag==0){
		alphabetFlag=1;
		block.setPhysics(0.5,0.3,0.3);
		block.setup(box2d.getWorld(),0,0,29.3,30);
	
		chink[0].addTriangle(ofVec2f(0+29.3,0-37),ofVec2f(20+29.3,0-37),ofVec2f(0+29.3,40-37));
		chink[1].addTriangle(ofVec2f(0-35.3,0-45),ofVec2f(20-35.3,10-45),ofVec2f(0-35.3,10-45));
		chink[2].addTriangle(ofVec2f(0+25,0-45),ofVec2f(20+25,10-45),ofVec2f(0+25,10-45));
		chink[3].addTriangle(ofVec2f(0-10.3,0-45),ofVec2f(20-10.3,10-45),ofVec2f(0-10.3,10-45));
		slab.loadImage("hS.png");

		for(int i=0;i<4;i++){		
			chink[i].setAsEdge(false);
			chink[i].setClosed(true);
			chink[i].setPhysics(0.5,0.3,0.3);
			if(chink[i].isGoodShape()){
				chink[i].create(box2d.getWorld());
				ofLog(OF_LOG_NOTICE, "test");
			}
		polyData *sd =new polyData();
		chink[i].setData(sd);
		sd = (polyData*)chink[i].getData();
		sd->bHit	= false;
		}
	}

	//hand.setPosition(ofGetMouseX(),ofGetMouseY());
	hand.setPosition(skeletonX[6],skeletonY[6]+300);
	box2d.update();	
}


//--------------------------------------------------------------
void testApp::draw() {
	image.draw(0,0,1920,1080);
	ofSetColor(250,241,213);
	ofFill();
	//block.draw();
	ofSetColor(222,226,30);
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	slab.draw(block.getPosition().x,block.getPosition().y,58.3+16,129.5+7);
	ofSetRectMode(OF_RECTMODE_CORNER);
	for(int i=0;i<4;i++){		
		chink[i].draw();		
	}
	ofSetColor(255,255,255,0);
	ofFill();
	hand.draw();
	ofSetColor(255,255,255);
	ofFill();
	handImage.draw(hand.getPosition().x-32,hand.getPosition().y-32,64,64);

	ofSetColor(165,196,187);
	ofFill();
	//ground.draw();
	ofRect(0,500,90,400);
	ofRect(1740,500,180,400);	
	ofSetColor(255,255,255);
	ofFill();
	slab.draw(920,130,slab.getWidth()/8,slab.getHeight()/8);
	//ofDrawBitmapString("Embedded Interaction Lab",10,750);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	if(key == 't') ofToggleFullscreen();
	if(key=='b'){	
	}
	if(key=='a'){
		blkState[1]=1;
		chink[1].addForce(ofVec2f(5,5),10);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}
//--------------------------------------------------------------
void testApp::contactStart(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		if((e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_polygon) || (e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_circle)) {
			ofLog(OF_LOG_NOTICE,"hit registered");
			polyData * aData = (polyData*)e.a->GetBody()->GetUserData();
			polyData * bData = (polyData*)e.b->GetBody()->GetUserData();
			
			if(aData) {
				aData->bHit = true;
			}
			
			if(bData) {
				bData->bHit = true; 
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		polyData * aData = (polyData*)e.a->GetBody()->GetUserData();
		polyData * bData = (polyData*)e.b->GetBody()->GetUserData();
		
		if(aData) {
			aData->bHit = false;
		}
		
		if(bData) {
			bData->bHit = false;
		}
	}
}