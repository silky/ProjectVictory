#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
  ofSetupOpenGL(1280,720,OF_WINDOW);			// <-------- setup the GL context
	//ofSetupOpenGL(1280,720,OF_FULLSCREEN);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
