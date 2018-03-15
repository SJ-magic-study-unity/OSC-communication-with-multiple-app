/************************************************************
************************************************************/
#include "ofApp.h"


/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("OSC_0");
	ofSetVerticalSync(true);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	********************/
	receiver.setup(12346);
}

//--------------------------------------------------------------
void ofApp::update(){
	/********************
	********************/
	while(receiver.hasWaitingMessages()){
		ofxOscMessage m_receive;
		receiver.getNextMessage(&m_receive);
		
		if(m_receive.getAddress() == "/Mouse"){
			OSC_mouseX = m_receive.getArgAsFloat(0);
			OSC_mouseY = m_receive.getArgAsFloat(1);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(20);
	
	printf("(%5.1f, %5.1f)\r", OSC_mouseX, OSC_mouseY);
	fflush(stdout);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
