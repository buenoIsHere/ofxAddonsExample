#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    vidGrabber.initGrabber(640, 480);
    flowSolver.setup(vidGrabber.getWidth()/2, vidGrabber.getHeight()/2, 0.5, 3, 10, 1, 7, 1.5, false, false);
    ofEnableAlphaBlending();
    blur.setup(vidGrabber.getWidth(), vidGrabber.getHeight(), 4, .2, 4);
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
        flowSolver.update(vidGrabber);
    }
    
    blur.setScale(ofMap(mouseX, 0, ofGetWidth(), 1, 10));
	blur.setRotation(ofMap(mouseY, 0, ofGetHeight(), -PI, PI));
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255);
    
    blur.begin();
    vidGrabber.draw(0, 0);
    flowSolver.drawColored(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3);
    ofSetCircleResolution(64);
	ofCircle(mouseX, mouseY, 32);
	blur.end();
    
    blur.draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'p') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() - 0.01,0.0,1.0)); }
    else if(key == 'P') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() + 0.01,0.0,1.0)); }
    else if(key == 'l') { flowSolver.setPyramidLevels(MAX(flowSolver.getPyramidLevels() - 1,1)); }
    else if(key == 'L') { flowSolver.setPyramidLevels(flowSolver.getPyramidLevels() + 1); }
    else if(key == 'w') { flowSolver.setWindowSize(MAX(flowSolver.getWindowSize() - 1,1)); }
    else if(key == 'W') { flowSolver.setWindowSize(flowSolver.getWindowSize() + 1); }
    else if(key == 'i') { flowSolver.setIterationsPerLevel(MAX(flowSolver.getIterationsPerLevel() - 1,1)); }
    else if(key == 'I') { flowSolver.setIterationsPerLevel(flowSolver.getIterationsPerLevel() + 1); }
    else if(key == 'a') { flowSolver.setExpansionArea(MAX(flowSolver.getExpansionArea() - 2,1)); }
    else if(key == 'A') { flowSolver.setExpansionArea(flowSolver.getExpansionArea() + 2); }
    else if(key == 's') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() - 0.01,0.0,10.0)); }
    else if(key == 'S') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() + 0.01,0.0,10.0)); }
    else if(key == 'f') { flowSolver.setFlowFeedback(false); }
    else if(key == 'F') { flowSolver.setFlowFeedback(true); }
    else if(key == 'g') { flowSolver.setGaussianFiltering(false); }
    else if(key == 'G') { flowSolver.setGaussianFiltering(true); }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}