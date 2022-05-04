#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    grabber.listDevices();
    grabber.setDeviceID(0);
    
    grabber.setup(1920, 1080);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){


    
    cam.begin();
    cam.enableOrtho();

    grabber.draw(0, 0);

    for (int y = 0; y < grabber.getHeight(); y+=9){
        ofPolyline line;
        for (int x = 0; x < grabber.getWidth(); x++){
            float brightness = grabber.getPixels().getColor(x,y).getBrightness();
            line.addVertex(x - grabber.getWidth()/2, (grabber.getHeight()-y-1) - grabber.getHeight()/2, ofMap(brightness, 0, 255, -200, 100));
        }
        line = line.getSmoothed(7);
        line.draw();
    }
    cam.end();
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
